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
		class game_object : public i_update, public i_render, public unique_id
		{
		public:
			//constructor ~ destructor
			game_object();
			~game_object();

			//public functions
			void attach_component(component*);
			void remove_component(component*);
			void add_child(game_object*);
			void remove_child(game_object*);
			void update(double pDeltaTime) override;
			void render() override;

			//getter functions
			std::vector<component*>get_components() const { return mComponents; }
			std::vector<game_object*> get_children() const { return mChildren; }
			game_object* get_parent() const { return mParent; }

			template<typename T>
			T* get_component()
			{
				if (mComponents.size() == 0) return nullptr;

				std::vector<component*>::iterator comp = mComponents.begin();
				for (; comp != mComponents.end(); ++comp)
				{
					T* theComponent = dynamic_cast<T*>(*comp);
					if (theComponent)
					{
						return theComponent;
					}
				}

				return nullptr;
			}
		protected:
			//members
			std::vector<component*>	mComponents;
			std::vector<game_object*> mChildren;
			game_object* mParent;
		};
	}
}

#endif // !_GAME_OBJECT_HPP


