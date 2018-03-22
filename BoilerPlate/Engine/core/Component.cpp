#include "Component.hpp"

namespace Engine
{
	namespace Core
	{
		Component::Component(const std::string& name)
			: m_name(name)
		{}

		Component::~Component()
		{
			m_owner = nullptr;
		}

		void Component::Update(double deltaTime)
		{
			IUpdate::Update(deltaTime);
		}
	}
}