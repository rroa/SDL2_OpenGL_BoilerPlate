#pragma once

#ifndef _RENDERER_HPP
#define _RENDERER_HPP

#include "shaders_utilities.hpp"
#include "texture.hpp"

namespace Engine
{
	const int MAXIMUM_TEXTURES = 16;

	class renderer
	{
	public:
		renderer();
		~renderer();
		void vertex_loader();
		void textures_loader(const char* pTextureFiles[]);
		void get_program_id();
		void render();
		void toggle_fill_or_line();

		bool fillOrLineDrawing;

	private:
		GLuint mVertexArrayObject; //VAO
		GLuint mVertexBufferObject; //VBO
		GLuint mElementsBufferObject; //EBO
		GLuint mProgramID;
		shaders_utilities mShaderManager;
		texture mTextures[MAXIMUM_TEXTURES];

	};
}

#endif // !_RENDERER_HPP



