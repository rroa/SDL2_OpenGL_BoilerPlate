#include "renderer.hpp"


renderer::renderer()
{
	mProgramID = mShaderManager.load_shaders("vertex.glsl", "frag.glsl");
}


renderer::~renderer()
{
}
