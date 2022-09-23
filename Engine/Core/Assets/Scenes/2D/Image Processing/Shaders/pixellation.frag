#version 450 core

in vec2 texCoord;
out vec4 FragColor;


uniform sampler2D tex0;
uniform float pixelSize;

uniform vec2 uResolution;


void main()
{   
   vec2 coordinates = gl_FragCoord.xy / uResolution.xy;
   vec2 size = vec2(pixelSize/uResolution.x, pixelSize/uResolution.y);
   vec2 position = floor(coordinates / size)*size;
   vec4 f = texture(tex0, position);

   FragColor = f;
}