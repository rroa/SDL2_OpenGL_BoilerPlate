#pragma once
#ifndef _IRENDER_HPP_
#define _IRENDER_HPP_

namespace Engine
{
	namespace Core
	{
		class IRender
		{
		public:
			virtual ~IRender() = default;
			/*
			 * PUBLIC FUNCTIONS
			 */
			void virtual Render() = 0;
		};
	}
}

#endif // !_IRENDER_HPP_
