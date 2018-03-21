#pragma once

namespace Engine
{
	namespace core 
	{
		class i_render
		{
		public:
			i_render();
			virtual ~i_render()= default;
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