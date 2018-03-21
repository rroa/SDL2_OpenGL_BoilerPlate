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
			i_render();
			virtual ~i_render() = default;
			void virtual Render() = 0;

		private:

		};

		i_render::i_render()
		{
		}

		i_render::~i_render()
		{
		}
	}
}

#endif // !_I_RENDER_HPP


