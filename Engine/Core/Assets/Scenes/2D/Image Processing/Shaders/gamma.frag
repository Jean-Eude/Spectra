#version 450 core

in vec2 texCoord;
out vec4 FragColor;


uniform float gamma;
uniform sampler2D tex0;


void main()
{   
   vec4 f = texture(tex0, texCoord);
   FragColor.rgb = pow(f.rgb, vec3(1.0f/gamma));
}