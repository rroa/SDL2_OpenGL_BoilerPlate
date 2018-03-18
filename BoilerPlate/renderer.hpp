#pragma once
#include "shaders_utilities.hpp"
#include "texture.hpp"
class renderer
{
public:
	renderer();
	~renderer();

private:
	GLuint mVertexArrayObject; //VAO
	GLuint mVertexBufferObject; //VBO
	GLuint mProgramID;
	shaders_utilities mShaderManager;
};

