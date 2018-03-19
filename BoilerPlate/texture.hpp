#pragma once
// OpenGL includes
#include <GL/glew.h>
#include <SDL2/SDL_opengl.h>

class texture
{
public:
	texture();
	texture(const char *);
	~texture();

	GLuint load_texture(const char *);
private:
	GLuint mTexture;
};

