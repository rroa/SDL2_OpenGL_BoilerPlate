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
		class GameObject : public IUpdate, public IRender, public UniqueID
		{
		public:
			/* =============================================================
			* CTOR FUNCTIONS
			* ============================================================= */
			GameObject();
			~GameObject();

			/* =============================================================
			* PUBLIC FUNCTIONS
			* ============================================================= */
			void AttachComponent(Component*);
			void RemoveComponent(Component*);
			void AddChild(GameObject*);
			void RemoveChild(GameObject*);
			void Update(double deltaTime) override;
			void Render() override;

			/* =============================================================
			* GETTER FUNCTIONS
			* ============================================================= */
			std::vector<Component*>GetComponents() const { return m_components; }
			std::vector<GameObject*> GetChildren() const { return m_children; }
			GameObject* GetParent() const { return m_parent; }

			template<typename T>
			T* GetComponent()
			{
				// If no components have been attached then return nothing
				//
				if (m_components.size() == 0) return nullptr;

				std::vector< Component* >::iterator comp = m_components.begin();
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
			/* =============================================================
			* MEMBERS
			* ============================================================= */
			std::vector<Component*>	m_components;
			std::vector<GameObject*> m_children;
			GameObject* m_parent;
		};

	}
}

#endif // !_GAMEOBJECT_HPP_
