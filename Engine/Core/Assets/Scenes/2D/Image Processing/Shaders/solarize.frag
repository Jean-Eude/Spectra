#version 450 core

in vec2 texCoord;
out vec4 FragColor;

uniform sampler2D tex0;
uniform vec2 uResolution;
uniform vec3 tresholdSolarize;
uniform bool enableSabbEff;

void main()
{
	vec3 trs = vec3(1.0f,0.92f,0.1f);

	vec2 uv = gl_FragCoord.xy / uResolution.xy;
	vec3 val = vec3(texture(tex0, uv));

	if(val.x < tresholdSolarize.x)
	{
		val.x = 1.0 - val.x;
	}
	if(val.y < tresholdSolarize.y)
	{
		val.y = 1.0 - val.y;
	}
	if(val.z < tresholdSolarize.z)
	{
		val.z = 1.0 - val.z;
	}


	if(enableSabbEff == true)
	{
    	float grey = dot (val.rgb, vec3(0.2627f, 0.6780f, 0.0593f));
    	FragColor = vec4(vec3(grey), 1.0f);
	}
	else
	{
		FragColor = vec4(val, 1.0f);
	}
}