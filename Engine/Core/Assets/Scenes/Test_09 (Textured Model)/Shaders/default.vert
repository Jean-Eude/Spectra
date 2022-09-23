#version 450 core

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;
layout (location = 2) in vec2 aTex;

// Inputs the matrices needed for 3D viewing with perspective

out vec2 Tex;

uniform mat4 proj;
uniform mat4 view;
uniform mat4 model;


void main()
{
   gl_Position = proj * view * model * vec4(aPos, 1.0);
   Tex = aTex;
}