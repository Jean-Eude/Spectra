#version 450 core

in vec2 texCoord;
in vec3 texNormal;
out vec4 FragColor;

uniform sampler2D tex0;

void main()
{
	vec4 tex = texture(tex0, texCoord) * 2.0f - 1.0f;
	vec3 Normal = texNormal;


	float alpha = tex.a;
    float grey = dot(tex.rgb, vec3(0.2627f, 0.6780f, 0.0593f));
    tex = vec4(grey, grey, grey, alpha);


	Normal = normalize(Normal);

	Normal.x = -dFdx(tex.x) / sqrt(dFdx(tex.x)*dFdx(tex.x)+dFdy(tex.y)*dFdy(tex.y)+1);
	Normal.y = -dFdy(tex.y) / sqrt(dFdx(tex.x)*dFdx(tex.x)+dFdy(tex.y)*dFdy(tex.y)+1);
	Normal.z = 1.0f / sqrt(dFdx(tex.z)*dFdx(tex.z)+dFdy(tex.z)*dFdy(tex.z)+1);

	Normal.r = (Normal.x+1.0f)/2.0f;
	Normal.g = (Normal.y+1.0f)/2.0f;
	Normal.b = Normal.b + 0.0f;

	Normal = normalize(Normal);


	FragColor = vec4(Normal, 1.0f);
}