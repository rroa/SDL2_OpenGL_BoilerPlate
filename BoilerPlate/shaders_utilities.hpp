#pragma once
// OpenGL includes
#include <GL/glew.h>
#include <SDL2/SDL_opengl.h>

//Move this
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
class shaders_utilities
{
public:
	shaders_utilities();
	~shaders_utilities();

	GLuint load_shaders(const char *, const char *);
};

