#include "component.hpp"

namespace Engine
{
	namespace core
	{
		component::component(const std::string& pName)
			: mName(pName)
		{}

		component::~component()
		{
			mOwner = nullptr;
		}

		void component::update(double pDeltaTime)
		{
			i_update::update(pDeltaTime);
		}
	}
}