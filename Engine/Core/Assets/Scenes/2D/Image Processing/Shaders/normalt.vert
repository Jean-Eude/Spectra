#version 450 core

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;
layout (location = 2) in vec2 aTex;
layout (location = 3) in vec3 aNormal;

out vec2 texCoord;
out vec3 texNormal;

void main()
{
   gl_Position = vec4(aPos, 1.0);
   texCoord = aTex;
   texNormal = aNormal;
}