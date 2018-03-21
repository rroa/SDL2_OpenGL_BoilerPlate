#pragma once

namespace Engine
{
	namespace core
	{
		class i_update
		{
		public:
			i_update();
			virtual ~i_update() = default;
			void virtual update(double pDeltaTime) { mNUpdates++ };

		protected:
			int mNUpdates;
		};
	}
}