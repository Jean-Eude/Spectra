#version 450 core

in vec2 texCoord;
out vec4 FragColor;


uniform sampler2D tex0;
uniform float contrast;

void main()
{   
   vec4 o = texture(tex0, texCoord);
   vec4 f = vec4(((o.rgb - vec3(0.5f))*contrast) + vec3(0.5f), 1.0f);
   FragColor = clamp(f, 0.0f, 1.0f);
}