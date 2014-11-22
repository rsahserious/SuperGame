#version 120

varying vec2 UV0;
varying vec3 normal0;

uniform sampler2D textureSampler;

float minBrightness = 0.6;
float maxBrightness = 1.0;

vec3 lightDir = vec3(-1.0, -0.7, 0.6);

void main()
{
	gl_FragColor = texture2D(textureSampler, UV0);
    gl_FragColor *= clamp(dot(-lightDir, normal0), minBrightness, maxBrightness);
}


/*

vec3 gLightDir = vec3(-1.0, -0.3, 0.3);
vec3 bLightDir = vec3(1.0, 0.3, 0.3);

void main()
{
	float rColor = clamp(dot(-gLightDir, normal0), minBrightness, maxBrightness) * 1.2;
	float gColor = clamp(dot(-bLightDir, normal0), minBrightness, maxBrightness) * 1.2;

	gl_FragColor = texture2D(textureSampler, UV0);

	vec4 colorFilter = vec4(rColor, gColor, 0.7, 1.0);
	
	gl_FragColor *= colorFilter;
}

*/