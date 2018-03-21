#pragma once

#include <vector>

#include "i_update.hpp"
#include "i_render.h"
#include "unique_id.h"
namespace Engine
{
	namespace core
	{
		class component;
		class scene;
		class game_object : public i_update, public i_render, public unique_id
		{
		public:
			game_object();
			~game_object();

		protected:
			
		};

		game_object::game_object()
		{
		}

		game_object::~game_object()
		{
		}
	}
}