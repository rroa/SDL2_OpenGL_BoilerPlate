#include "game.hpp"
namespace game {
	game::game()
	{
		//mRenderManager = Engine::renderer();
	}

	game::~game()
	{
		mRenderManager.~renderer();
	}


	void game::execute(int pFrameHeight, int pFrameWidth)
	{
		mRenderManager.init_render();
		mRenderManager.vertex_loader(pFrameHeight, pFrameWidth);
	}

	void game::render()
	{
		mRenderManager.render();
	}
	void game::toggle_drawing_mode()
	{
		mRenderManager.toggle_fill_or_line();
	}
}