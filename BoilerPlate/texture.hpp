#pragma once

#ifndef _TEXTURE_HPP
#define _TEXTURE_HPP

// OpenGL includes
#include <GL/glew.h>
#include <SDL2/SDL_opengl.h>

namespace Engine
{
	class texture
	{
	public:
		texture();
		texture(const char *);
		~texture();

		GLuint get_texture();

		GLuint load_texture(const char *);
	private:

		GLuint mTexture;
	};
}

#endif // !_TEXTURE_HPP