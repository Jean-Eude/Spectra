#version 450 core

in vec2 texCoord;
out vec4 FragColor;


uniform sampler2D tex0;
uniform bool grayscaledRobC;
uniform bool invertRobC;
uniform bool tresholdRobC;
uniform float tresholdScaleRobC;


const float offset_x  = 1.0f/1600.0f; // Peut être modifié, utile de changer pour varier les effets
const float offset_y  = 1.0f/900.0f; // Peut être modifié, utile de changer pour varier les effets

vec2 offset[9]=vec2[]
(
	vec2(-offset_x,offset_y),	vec2(0.0f,offset_y),		vec2(offset_x,offset_y),
	vec2(-offset_x,0.0f),		vec2(0.0f, 0.0f),			vec2(offset_x, 0.0f),
	vec2(-offset_x,-offset_y),	vec2(0.0f, -offset_y),		vec2(offset_x,-offset_y)
);

float Gx[4] = float[]
(
	1, 0,
	0, -1
);

float Gy[4] = float[]
(
	0,  1,
	-1, 0
);

void main(){


vec3 horizontal = vec3(0.0f);
vec3 vertical = vec3(0.0f);

//Double Pass

//Horizontal Pass
for(int i=0;i<4;i++)
{
	horizontal+= vec3(texture(tex0,texCoord.st+offset[i]))*Gx[i];
}

//Vertical Pass
for(int j=0;j<4;j++)
{
	vertical+= vec3(texture(tex0,texCoord.st+offset[j]))*Gy[j];
}

//Normalization
vec3 normalized = sqrt(horizontal*horizontal + vertical*vertical);


if(grayscaledRobC == true)
{
	float grey = dot(normalized.rgb, vec3(0.2627f, 0.6780f, 0.0593f));
	FragColor = vec4(vec3(grey), 1.0f);
}
else if(invertRobC == true)
{
	FragColor = vec4(1.0f - normalized, 1.0f);
}
else if(tresholdRobC == true)
{
	vec3 col = normalized.rgb;
    float bright = 0.33333f * (col.r + col.g + col.b);
    float b = mix(0.0f, 1.0f, step(tresholdScaleRobC, bright));
    
    FragColor = vec4(vec3(b), 1.0f);
}
else
{
	FragColor = vec4(normalized, 1.0f);
}
}
