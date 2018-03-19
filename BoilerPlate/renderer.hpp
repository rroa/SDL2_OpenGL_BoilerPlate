#pragma once
#include "shaders_utilities.hpp"
#include "texture.hpp"

const int MAXIMUM_TEXTURES = 16;

class renderer
{
public:
	renderer();
	~renderer();
	void vertex_loader();
	void textures_loader(const char* pTextureFiles[]);
	void fill_vertices();
	void get_program_id();
	void render();

private:
	GLuint mVertexArrayObject; //VAO
	GLuint mVertexBufferObject; //VBO
	GLuint mElementsBufferObject; //EBO
	GLuint mProgramID;
	shaders_utilities mShaderManager;
	texture mTextures[MAXIMUM_TEXTURES];
	
};

