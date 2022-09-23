#version 450 core

out vec4 FragColor;
  
in vec3 Normal;  
in vec3 FragPos;  
in vec2 TexCoords;
  
uniform vec3 lightPos; 
uniform vec3 lightColor;
uniform vec3 objectColor;
uniform sampler2D diffuse;

void main()
{
    vec4 tex = texture(diffuse, TexCoords);

    // ambient
    float ambientStrength = 0.1f;
    vec3 ambient = ambientStrength * lightColor;
    
    // diffuse 
    vec3 norm = normalize(Normal);
    vec3 lightDir = normalize(lightPos - FragPos);
    float diff = max(dot(norm, lightDir), 0.0f);
    vec3 diffuse = diff * lightColor;
            
    vec3 result = (ambient + diffuse) * tex.rgb;
    FragColor = vec4(result, 1.0f);
}