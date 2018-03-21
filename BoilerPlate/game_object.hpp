#pragma once

#ifndef _GAME_OBJECT_HPP
#define _GAME_OBJECT_HPP

#include <vector>

#include "i_render.hpp"
#include "i_update.hpp"
#include "unique_id.hpp"

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

#endif // !_GAME_OBJECT_HPP


