#pragma once

#ifndef _I_UPDATE_HPP
#define _I_UPDATE_HPP

namespace Engine
{
	namespace core
	{
		class i_update
		{
		public:
			i_update();
			virtual ~i_update() = default;
			void virtual update(double pDeltaTime) { mNUpdates++; };

		protected:
			int mNUpdates;
		};
	}
}

#endif // !_I_UPDATE_HPP


