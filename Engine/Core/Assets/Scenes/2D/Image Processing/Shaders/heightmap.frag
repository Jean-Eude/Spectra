#version 450 core

in vec2 texCoord;
in vec3 texNormal;
out vec4 FragColor;

uniform sampler2D tex0;

uniform float brightness;
uniform float contrast;
uniform float gamma;
uniform float minLevel;
uniform float maxLevel;


float opacity(vec4 inTex)
{
    return inTex.a;
}

float grayscaled(vec4 inTex)
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


void main()
{    
    vec4 tex = texture(tex0, texCoord);

    float alpha = opacity(tex);
    float grayscale = grayscaled(tex);

    vec4 f1 = vec4(grayscale, grayscale, grayscale, alpha);
    vec3 bc = brightnessContrast(f1.rgb, brightness, contrast);
    vec4 f2 = vec4(vec3(bc), alpha);
    vec3 gm = gammaCorrect(f2.rgb, gamma);
    vec4 f3 = vec4(vec3(gm), alpha);
    vec3 lv = finalLevels(f3.rgb, minLevel, gamma, maxLevel);
    vec4 f4 = vec4(vec3(lv), alpha);

    FragColor = f4;
}