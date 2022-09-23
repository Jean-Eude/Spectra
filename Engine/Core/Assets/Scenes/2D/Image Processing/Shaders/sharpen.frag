#version 450 core

in vec2 texCoord;
out vec4 FragColor;


uniform sampler2D tex0;


const float offset_x  = 1.0f/1600.0f; // Peut être modifié, utile de changer pour varier les effets
const float offset_y  = 1.0f/900.0f; // Peut être modifié, utile de changer pour varier les effets

vec2 offset[9]=vec2[]
(
	vec2(-offset_x,offset_y),	vec2(0.0f,offset_y),	vec2(offset_x,offset_y),
	vec2(-offset_x,0.0f),		vec2(0.0f,0.0f),		vec2(offset_x,0.0f),
	vec2(-offset_x,-offset_y),	vec2(0.0f,-offset_y),	vec2(offset_x,-offset_y)
);

float kernel[9] = float[]
(
	0,-1, 0,
	-1, 5, -1,
	0, -1, 0
);

void main(){

vec3 color = vec3(0.0f);

//Single-Pass
for(int i=0;i<9;i++)
{
	color+= vec3(texture(tex0,texCoord.st+offset[i]))*kernel[i];
}

FragColor = vec4(color,1.0f);

}
