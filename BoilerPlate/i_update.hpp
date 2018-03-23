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
			//constructor
			i_update() : mNupdates(0) {}
			virtual ~i_update() = default;

			//public function
			void virtual update(double pDeltaTime) { mNupdates++; };
		protected:
			//memeber
			int	mNupdates;
		};
	}
}

#endif // !_I_UPDATE_HPP


