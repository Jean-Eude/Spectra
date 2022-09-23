//pas fini

#version 450 core

in vec2 texCoord;
out vec4 FragColor;


uniform sampler2D tex0;
uniform bool grayscaledEmb;
uniform bool invertEmb;
uniform bool tresholdEmb;
uniform float tresholdScaleEmb;

uniform bool pass1;
uniform bool pass2;
uniform bool pass3;
uniform bool pass4;
uniform bool Dpass1;
uniform bool Dpass2;
uniform bool Epass1;

const float offset_x  = 1.0f/1600.0f; // Peut être modifié, utile de changer pour varier les effets
const float offset_y  = 1.0f/900.0f; // Peut être modifié, utile de changer pour varier les effets

vec2 offset[9]=vec2[]
(
	vec2(-offset_x,offset_y),	vec2(0.0,offset_y),		vec2(offset_x,offset_y),
	vec2(-offset_x,0.0),		vec2(0.0,0.0),			vec2(offset_x,0.0),
	vec2(-offset_x,-offset_y),	vec2(0.0,-offset_y),	vec2(offset_x,-offset_y)
);

float Gx_x[9] = float[]
(
	0, 		1, 		0,
	0, 		0, 		0,
	0, 		-1, 	0
);

float Gx_y[9] = float[]
(
	1, 		0, 		0,
	0, 		0, 		0,
	0, 		0, 		-1
);

float Gy_x[9] = float[]
(
	0, 		0, 		0,
	1, 		0, 		-1,
	0, 		0, 		0
);

float Gy_y[9] = float[]
(
	0, 		0, 		1,
	0, 		0, 		0,
	-1, 	0, 		0
);

float Gz_x[9] = float[]
(
	-1, 	0, 		0,
	0, 		0, 		0,
	0, 		0, 		1
);

float Gz_y[9] = float[]
(
	0, 		0, 		-1,
	0, 		0, 		0,
	1, 		0, 		0
);

float Gz_z[25] = float[]
(
	1, 		0, 		0, 		0, 		0, 
	0, 		1, 		0, 		0, 		0, 
	0, 		0, 		0, 		0, 		0, 
	0, 		0, 		0, 		-1, 	0,
	0, 		0, 		0, 		0, 		-1
);


void main(){

vec3 pass = vec3(0.0f);


if(pass1 == true)
{
	for(int i=0;i<9;i++)
	{
		pass+= vec3(texture(tex0,texCoord.st+offset[i]))*Gx_x[i];
	}
}

if(pass2 == true)
{
	for(int j=0;j<9;j++)
	{
		pass+= vec3(texture(tex0,texCoord.st+offset[j]))*Gx_y[j];
	}
}

if(pass3 == true)
{
	for(int k=0;k<9;k++)
	{
		pass+= vec3(texture(tex0,texCoord.st+offset[k]))*Gy_x[k];
	}
}

if(pass4 == true)
{
	for(int l=0;l<9;l++)
	{
		pass+= vec3(texture(tex0,texCoord.st+offset[l]))*Gy_y[l];
	}
}

if(Dpass1 == true)
{
	for(int m=0;m<9;m++)
	{
		pass+= vec3(texture(tex0,texCoord.st+offset[m]))*Gz_x[m];
	}
}

if(Dpass2 == true)
{
	for(int n=0;n<9;n++)
	{
		pass+= vec3(texture(tex0,texCoord.st+offset[n]))*Gz_y[n];
	}
}

if(Epass1 == true)
{
	for(int o=0;o<25;o++)
	{
		pass+= vec3(texture(tex0,texCoord.st+offset[o]))*Gz_z[o];
	}
}


//Bump Map
pass+= 0.5f;


// Normal map
/*
pass.r+=0.5f;
pass.g+=0.5f;
pass.b+=1.0f;

// Flow Map
pass.r+=0.5f;
pass.g+=0.5f;
pass.b+=0.0f;
*/


if(grayscaledEmb == true)
{
	float grey = dot(pass.rgb, vec3(0.2627f, 0.6780f, 0.0593f));
	FragColor = vec4(vec3(grey), 1.0f);
}
else if(invertEmb == true)
{
	FragColor = vec4(1.0f - pass, 1.0f);
}
else if(tresholdEmb == true)
{
	vec3 col = pass.rgb;
    float bright = 0.33333f * (col.r + col.g + col.b);
    float b = mix(0.0f, 1.0f, step(tresholdScaleEmb, bright));
    
    FragColor = vec4(vec3(b), 1.0f);
}
else
{
	FragColor = vec4(pass, 1.0f);
}
}
