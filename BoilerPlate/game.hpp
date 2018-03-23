#pragma once
#include "renderer.hpp"
#include "game_object.hpp"

namespace game 
{
	class game
	{
	public:

		game();
		~game();
		void execute(int, int);
		void render();
		void toggle_drawing_mode();

	private:
		Engine::renderer mRenderManager;
		Engine::core::game_object ball;
		Engine::core::game_object brick;
	};
}