#include "unique_id.hpp"

namespace Engine
{
	namespace core
	{
		int unique_id::mNextID = 0;

		unique_id::unique_id()
		{
			mId = ++mNextID;
		}

		unique_id::unique_id(const unique_id& pOrig)
		{
			mId = pOrig.mId;
		}

		unique_id& unique_id::operator=(const unique_id& pOrig)
		{
			mId = pOrig.mId;
			return(*this);
		}
	}
}