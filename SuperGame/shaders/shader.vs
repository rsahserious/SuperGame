#version 120

attribute vec3 position;
attribute vec2 UV;
attribute vec3 normal;

varying vec2 UV0;
varying vec3 normal0;

uniform mat4 cameraTransform;
uniform mat4 objectTransform;

void main()
{
	UV0 = UV;
	normal0 = (objectTransform * vec4(normal, 0.0)).xyz;

	gl_Position = cameraTransform * vec4(position, 1.0);
}