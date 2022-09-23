#version 450 core

in vec2 texCoord;
out vec4 FragColor;


uniform sampler2D tex0;


void main()
{   
    float alpha = texture(tex0, texCoord).a;
    float grey = dot (texture(tex0, texCoord).rgb, vec3(0.2627f, 0.6780f, 0.0593f));
    FragColor = vec4(grey, grey, grey, alpha);
}