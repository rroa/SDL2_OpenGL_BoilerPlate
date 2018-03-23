#pragma once

#ifndef _I_RENDER_HPP
#define _I_RENDER_HPP

namespace Engine
{
	namespace core
	{
		class i_render
		{
		public:
			virtual ~i_render() = default;

			//public function
			void virtual render() = 0;
		};
	}
}

#endif // !_I_RENDER_HPP


