#version 450 core

in vec2 texCoord;
out vec4 FragColor;


uniform sampler2D tex0;
uniform float treshold;


void main()
{   
    vec3 col = texture(tex0, texCoord.st).rgb;
    float bright = 0.33333 * (col.r + col.g + col.b);
    float b = mix(0.0, 1.0, step(treshold, bright));
    
    FragColor = vec4(vec3(b), 1.0);
}