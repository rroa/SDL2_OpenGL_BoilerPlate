#include "renderer.hpp"
#include "vertex.hpp"

vertex vertices[] = {
	// first triangle
	{0.5f,  0.5f, 0.0f},  // top right
	{0.5f, -0.5f, 0.0f},  // bottom right
	{-0.5f,  0.5f, 0.0f}, // top left 
	// second triangle
	{0.5f, -0.5f, 0.0f},  // bottom right
	{-0.5f, -0.5f, 0.0f}, // bottom left
	{-0.5f,  0.5f, 0.0f}  // top left
};

int indices[] = { 0, 1, 2, 1, 3, 2 };

renderer::renderer()
{
	
}


renderer::~renderer()
{
	glDeleteBuffers(1, &mVertexBufferObject);
	glDeleteBuffers(1, &mElementsBufferObject);
	glDeleteVertexArrays(1, &mVertexArrayObject);
}

void renderer::vertex_loader()
{
	// set up vertex data (and buffer(s)) and configure vertex attributes
	// ------------------------------------------------------------------

	glGenVertexArrays(1, &mVertexArrayObject);
	glGenBuffers(1, &mVertexBufferObject);
	glGenBuffers(1, &mElementsBufferObject);
	

	// bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
	glBindVertexArray(mVertexArrayObject);

	glBindBuffer(GL_ARRAY_BUFFER, mVertexBufferObject);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);


	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mElementsBufferObject);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);


	glVertexAttribPointer(
		0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
		4,                  // size
		GL_FLOAT,           // type
		GL_FALSE,           // normalized?
		4 * sizeof(float),  // stride
		(void*)0            // array buffer offset
	);

	
	glEnableVertexAttribArray(0);

	// note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);


	// You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
	// VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
	glBindVertexArray(0);

	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}

void renderer::textures_loader(const char* pTextureFiles[])
{
	for (int i = 0; i < sizeof(pTextureFiles); i++) 
	{
		mTextures[i] = texture(pTextureFiles[i]);
	}
}

void renderer::fill_vertices()
{
	
}

void renderer::get_program_id()
{
	mProgramID = mShaderManager.load_shaders("vertex.glsl", "frag.glsl");
}

void renderer::render()
{
	//Use the program
	glUseProgram(mProgramID);
	glBindVertexArray(mVertexArrayObject);
	//glDrawElements(GL_TRIANGLES, sizeof(indices), GL_UNSIGNED_BYTE, (void*)0);
	glDrawArrays(GL_TRIANGLES, 0, 6); 
}
