#pragma once
#ifndef _UNIQUEID_HPP_
#define _UNIQUEID_HPP_

namespace Engine
{
	namespace Core
	{
		class UniqueID
		{
		public:
			/* =============================================================
			* CTOR
			* ============================================================= */
			UniqueID();
			UniqueID(const UniqueID& orig);

			/* =============================================================
			* OPERATORS
			* ============================================================= */
			UniqueID& operator=(const UniqueID& orig);

			/* =============================================================
			* MEMBERS
			* ============================================================= */
			int id;
		protected:
			static int nextID;
		};

	}
}

#endif // !_UNIQUEID_HPP_
