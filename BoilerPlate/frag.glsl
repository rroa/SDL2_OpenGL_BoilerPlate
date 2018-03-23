#version 330 core

// Ouput data
out vec4 color;

in vec2 textureCoord;

uniform sampler2D texture1;
uniform sampler2D texture2;

void main()
{
	color = mix(texture(texture1, textureCoord), texture(texture2, textureCoord), 0.7);
}