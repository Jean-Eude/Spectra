#version 450 core

in vec2 texCoord;

out vec4 FragColor;

uniform sampler2D texWall;

void main()
{
   FragColor = texture(texWall, texCoord);
}