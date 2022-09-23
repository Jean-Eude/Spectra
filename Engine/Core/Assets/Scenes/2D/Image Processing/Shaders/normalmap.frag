#version 450 core

in vec2 texCoord;
in vec3 texNormal;
out vec4 FragColor;

uniform sampler2D tex0;

float opacity(vec4 inTex)
{
	return inTex.a;
}

float grayscale(vec4 inTex)
{
 	return dot(inTex.rgb, vec3(0.2627f, 0.6780f, 0.0593f));
}

vec3 brightnessContrast(vec3 value, float brightness, float contrast)
{
    return (value - 0.5) * contrast + 0.5 + brightness;
}

vec3 gammaCorrect(vec3 color, float gamma)
{
    return pow(color, vec3(1.0/gamma));
}

vec3 levelRange(vec3 color, float minInput, float maxInput){
    return min(max(color - vec3(minInput), vec3(0.0)) / (vec3(maxInput) - vec3(minInput)), vec3(1.0));
}

vec3 finalLevels(vec3 color, float minInput, float gamma, float maxInput){
    return gammaCorrect(levelRange(color, minInput, maxInput), gamma);
}

float sRGB(float x) {
    if (x <= 0.00031308)
        return 12.92 * x;
    else
        return 1.055*pow(x,(1.0 / 2.4) ) - 0.055;
}

void main()
{
	vec4 tex = texture(tex0, texCoord);
	vec3 Normal = texNormal;

	float alpha = opacity(tex);
    float grey = max(max(tex.r, tex.g), tex.b);

    tex = vec4(vec3(grey), alpha);

    Normal.x = -dFdx(tex.x);
    Normal.y = -dFdy(tex.y);
    Normal.z = 1.0f;


    vec3 f = vec3(Normal.x, Normal.y, Normal.z);
    f = normalize(f);

    f.r = 0.5f + 0.5f * Normal.x;
    f.g = 0.5f + 0.5f * Normal.y;

    f = vec3(f.r, f.g, f.b);

    FragColor = vec4(f, alpha);
}