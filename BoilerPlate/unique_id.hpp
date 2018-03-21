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
			unique_id();
			unique_id(const unique_id& pOrig);
			virtual ~unique_id() = default;
			unique_id& operator = (const unique_id&);

		private:

		};

		unique_id::unique_id()
		{
		}

		unique_id::~unique_id()
		{
		}
	}
}

#endif // !_UNIQUE_ID_HPP


