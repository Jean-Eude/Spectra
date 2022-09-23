#version 450 core

out vec4 FragColor;
  

struct Material {
    sampler2D diffuse;
    sampler2D specular;    
    float shininess;
}; 

struct Light {
    vec3 direction;

    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};


in vec3 Normal;  
in vec3 FragPos;  
in vec2 TexCoords;
  
uniform vec3 viewPos;
uniform Material material;
uniform Light light;
uniform float SpecStrength;

void main()
{
    vec4 texDiff = texture(material.diffuse, TexCoords);
    vec4 texSpec = texture(material.specular, TexCoords);

    // ambient
    vec3 ambient = light.ambient * texDiff.rgb;
    
    // diffuse 
    vec3 norm = normalize(Normal);
    vec3 lightDir = normalize(-light.direction);
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = light.diffuse * diff * texDiff.rgb;  
    
    // specular
    vec3 viewDir = normalize(viewPos - FragPos);
    vec3 reflectDir = reflect(-lightDir, norm);  
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
    vec3 specular = light.specular * spec * (texSpec.rgb * SpecStrength);  
        
    vec3 result = ambient + diffuse + specular;
    FragColor = vec4(result, 1.0);
}