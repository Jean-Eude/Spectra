#version 450 core

in vec2 texCoord;
out vec4 FragColor;


uniform sampler2D tex0;


void main()
{   
   vec4 texture = vec4(texture(tex0, texCoord));
   FragColor = vec4(1.0f - texture);
}