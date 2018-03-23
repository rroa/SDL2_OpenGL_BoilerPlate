#pragma once

#ifndef _UNIQUE_ID_HPP
#define _UNIQUE_ID_HPP

namespace Engine
{
	namespace core
	{
		class unique_id
		{
		public:
			//constructors
			unique_id();
			unique_id(const unique_id& pOrig);

			//operator
			unique_id& operator=(const unique_id& pOrig);

			//members
			int mId;
		protected:
			static int mNextID;
		};
	}
}

#endif // !_UNIQUE_ID_HPP


