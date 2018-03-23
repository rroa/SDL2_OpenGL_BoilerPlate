#version 330 core

// Input vertex data, different for all executions of this shader.

layout(location = 0) in vec3 vertexPosition_modelspace;
layout(location = 1) in vec2 texture_position;

out vec2 textureCoord;

void main() {
    gl_Position.xyz = vertexPosition_modelspace;
    gl_Position.w = 1.0;

	textureCoord= texture_position;
}