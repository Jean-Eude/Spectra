#version 450 core

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;
layout (location = 2) in vec2 aTex;

out vec2 texCoord;
out vec2 coordinate;

void main()
{
   gl_Position = vec4(aPos, 1.0);
   texCoord = aTex;
}