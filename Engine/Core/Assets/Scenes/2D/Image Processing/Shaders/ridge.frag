#version 450 core

in vec2 texCoord;
out vec4 FragColor;


uniform sampler2D tex0;
uniform bool grayscaledRidge;
uniform bool invertRidge;
uniform bool tresholdRidge;
uniform float tresholdScaleRidge;

const float offset_x  = 1.0f/1600.0f; // Peut être modifié, utile de changer pour varier les effets
const float offset_y  = 1.0f/900.0f; // Peut être modifié, utile de changer pour varier les effets

vec2 offset[9]=vec2[]
(
	vec2(-offset_x, offset_y),	vec2(0.0f, offset_y),		vec2(offset_x, offset_y),
	vec2(-offset_x, 0.0f),		vec2(0.0f, 0.0f),			vec2(offset_x, 0.0f),
	vec2(-offset_x, -offset_y),	vec2(0.0f, -offset_y),	    vec2(offset_x, -offset_y)
);

float kernel[9] = float[]
(
	-1,-1, -1,
	-1, 8, -1,
	-1, -1, -1
);

void main(){

vec3 color = vec3(0.0f);

//Single-Pass
for(int i=0;i<9;i++)
{
	color+= vec3(texture(tex0,texCoord.st+offset[i]))*kernel[i];
}


if(grayscaledRidge == true)
{
	float grey = dot(color.rgb, vec3(0.2627f, 0.6780f, 0.0593f));
	FragColor = vec4(vec3(grey), 1.0f);
}
else if(invertRidge == true)
{
	FragColor = vec4(1.0f - color,1.0f);
}
else if(tresholdRidge == true)
{
	vec3 col = color.rgb;
    float bright = 0.33333f * (col.r + col.g + col.b);
    float b = mix(0.0f, 1.0f, step(tresholdScaleRidge, bright));
    
    FragColor = vec4(vec3(b), 1.0f);
}
else
{
	FragColor = vec4(color, 1.0f);
}
}
