#version 450 core

in vec2 texCoord;
out vec4 FragColor;


uniform sampler2D tex0;

uniform bool red;
uniform bool green;
uniform bool blue;
uniform bool alphab;
uniform bool maxc;
uniform bool screenblend;
uniform bool invert;
uniform bool emboss;

const float offset_x  = 1.0f/1600.0f; // Peut être modifié, utile de changer pour varier les effets
const float offset_y  = 1.0f/900.0f; // Peut être modifié, utile de changer pour varier les effets

vec2 offset[9]=vec2[]
(
    vec2(-offset_x,offset_y),   vec2(0.0,offset_y),     vec2(offset_x,offset_y),
    vec2(-offset_x,0.0),        vec2(0.0,0.0),          vec2(offset_x,0.0),
    vec2(-offset_x,-offset_y),  vec2(0.0,-offset_y),    vec2(offset_x,-offset_y)
);

float Gz_z[25] = float[]
(
    1,      0,      0,      0,      0, 
    0,      1,      0,      0,      0, 
    0,      0,      0,      0,      0, 
    0,      0,      0,      -1,     0,
    0,      0,      0,      0,      -1
);

void main()
{   
    vec4 tex = texture(tex0, texCoord);
    vec3 pass = vec3(0.0f);


    float alpha = tex.a;
    float grey;

    if(emboss == true)
    {
        for(int o=0;o<25;o++)
        {
            pass+= vec3(texture(tex0,texCoord.st+offset[o]))*Gz_z[o];
        }

    pass+= 0.5f;
    tex = vec4(pass, alpha);    
    }


    if(red == true)
    {
        grey = tex.r;
    }

    if(green == true)
    {
        grey = tex.g;
    }

    if(blue == true)
    {
        grey = tex.b;
    }

    if(alphab == true)
    {
        grey = tex.a;
    }

    if(maxc == true)
    {
        grey = max(max(tex.r, tex.g), tex.b); // On choisit le max des 3 canaux
    }  

    if(screenblend == true)
    {
        grey = (1.0f - tex.r)*(1.0f-tex.g)*(1.0f-tex.b); // On screen blend les 3 canaux , faire 1.0f - ... avant (1.0f - tex.r)..
    }  

    if(invert == true)
    {
        grey = 1.0f - grey;
    }


    FragColor = vec4(vec3(grey), alpha);
}