#version 450 core

out vec4 FragColor;
  

struct Material {
    sampler2D diffuse;
    sampler2D specular; 
    sampler2D normal;     
    float shininess;
}; 

struct Light {
    vec3 position;  
  
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;

    float constant;
    float linear;
    float quadratic;
};


in vec3 Normal;  
in vec3 FragPos;  
in vec2 TexCoords;
  
uniform vec3 viewPos;
uniform Material material;
uniform Light light;
uniform float SpecStrength;
uniform bool blinn;

void main()
{
    vec4 texDiff = texture(material.diffuse, TexCoords);
    vec4 texSpec = texture(material.specular, TexCoords);
    vec4 texNorm = texture(material.normal, TexCoords);

    // ambient
    vec3 ambient = light.ambient * texDiff.rgb;
    
    // diffuse 
    vec3 norm = texNorm.rgb;
    norm = normalize(norm * 2.0 - 1.0);   


    vec3 lightDir = normalize(light.position - FragPos);
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = light.diffuse * diff * texDiff.rgb;  
    
    // specular
    vec3 viewDir = normalize(viewPos - FragPos);
    vec3 reflectDir = reflect(-lightDir, norm);  
    vec3 halfwayDir = normalize(lightDir + viewDir);  

    const float kPi = 3.14159265;
    const float kShininess = 16.0;

    float spec = 0.0f;
    if(blinn)
    {
        const float kEnergyConservation = ( 8.0 + kShininess ) / ( 8.0 * kPi ); 
        spec = kEnergyConservation * pow(max(dot(norm, halfwayDir), 0.0), material.shininess);
    }
    else
    {
        const float kEnergyConservation = ( 2.0 + kShininess ) / ( 2.0 * kPi ); 
        spec = kEnergyConservation * pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
    }
    vec3 specular = light.specular * spec * (texSpec.rgb * SpecStrength);  

    /*
    // attenuation
    float distance    = length(light.position - FragPos);
    float attenuation = 1.0 / (light.constant + light.linear * distance + light.quadratic * (distance * distance));    

    ambient  *= attenuation;  
    diffuse   *= attenuation;
    specular *= attenuation;  
    */
        
    vec3 result = ambient + diffuse + specular;
    FragColor = vec4(result, 1.0);
}