#pragma once
#ifndef _IUPDATE_HPP_
#define _IUPDATE_HPP_

namespace Engine
{
	namespace Core
	{
		class IUpdate
		{
		public:
			/*
			* CTOR // DTOR
			*/
			IUpdate() : m_nUpdates(0) {};
			virtual ~IUpdate() = default;

			/*
			 * PUBLIC FUNCTIONS
			 */
			void virtual Update(double deltaTime) { m_nUpdates++; };
		protected:
			/*
			* MEMBERS
			*/
			int m_nUpdates;
		};
	}
}

#endif // !_IUPDATE_HPP_
