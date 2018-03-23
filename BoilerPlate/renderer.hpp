#pragma once

#ifndef _RENDERER_HPP
#define _RENDERER_HPP

#include "shaders_utilities.hpp"
#include "texture.hpp"
#include <vector>

namespace Engine
{
	const int MAXIMUM_TEXTURES = 16;

	class renderer
	{
	public:
		renderer();
		~renderer();
		void vertex_loader(int, int);
		//void textures_loader(const char* pTextureFiles[]);
		void init_render();
		void render();
		void toggle_fill_or_line();
		void objects_generator();
		void objects_activator();
		void objects_atrributes_manager();

		//Global variables
		bool fillOrLineDrawing;

		//Public attributes
		shaders_utilities mShaderManager;
		texture mTexture;

	private:
		GLuint mVertexArrayObject; //VAO
		GLuint mVertexBufferObject; //VBO
		GLuint mElementsBufferObject; //EBO
		GLuint mProgramID;
	};
}

#endif // !_RENDERER_HPP



