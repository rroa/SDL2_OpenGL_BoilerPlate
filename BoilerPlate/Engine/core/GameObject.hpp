#pragma once
#ifndef _GAMEOBJECT_HPP_
#define _GAMEOBJECT_HPP_

#include <vector>

//
#include "IUpdate.hpp"
#include "IRender.hpp"
#include "UniqueID.hpp"

namespace Engine
{
	namespace Core
	{
		class Component;
		class Scene;
		class GameObject : public IUpdate, public IRender, public UniqueID
		{
		public:
			template<typename T>
			T* GetComponent()
			{
				// If no components have been attached then return nothing
				if (m_components.size() == 0) return nullptr;
				std::vector<Component*>::iterator comp = m_components.begin();
				for (; comp != m_components.end(); ++comp)
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
			std::vector<Component*> m_components;
			Scene* m_scene;
			std::vector<GameObject*> m_children;
			GameObject* m_parent;
		};
	}
}

#endif // !_GAMEOBJECT_HPP_
