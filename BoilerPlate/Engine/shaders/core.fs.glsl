#version 330 core

// Ouput data
out vec4 color;

uniform float time;

in vec3 ourColor;
in vec2 TexCoord;

// texture sampler
uniform sampler2D texture1;
uniform sampler2D texture2;

void main()
{
	color = mix(texture(texture1, TexCoord), texture(texture2, TexCoord), 0.7);
}