#pragma once
// OpenGL includes
#include <GL/glew.h>
#include <SDL2/SDL_opengl.h>
#include "error_manager.hpp"

#include <string>
#include <vector>
#include <fstream>
#include <sstream>
struct shaders_utilities
{
public:
	shaders_utilities();
	~shaders_utilities();
	error_manager errorManager;

	GLuint load_shaders(const char *, const char *);
};

