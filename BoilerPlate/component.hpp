#pragma once

#ifndef _COMPONENT_HPP
#define _COMPONENT_HPP

#include <string>

#include "i_update.hpp"

namespace Engine
{
	namespace core
	{
		class game_object;
		class component : i_update
		{
		public:
			//public functions
			explicit component(const std::string& name);
			~component();
			void update(double pDeltaTime) override;
			
			//getter functions
			void set_owner(game_object* pOwner) { mOwner = pOwner; }
			game_object* get_owner() const { return mOwner; }
			std::string get_name() const { return mName; }
		protected:
			//members
			game_object* mOwner;
			std::string	mName;
		};
	}
}

#endif // !_COMPONENT_HPP

