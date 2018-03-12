#pragma once
#include "Vector3.hpp"
#include <iostream>

namespace engine {

	class matrix_4
	{
		struct array_2D
		{
			float mArray[4][4];
		};

	public:
		matrix_4();
		matrix_4(float, float, float, float, float, float, float, float, float, float, float, float, float, float, float, float);
		matrix_4(float[16]);
		~matrix_4();

		array_2D get_matrix();
		matrix_4 get_invert();
		matrix_4 get_transpose();
		void set_identity();
		Vector3 get_angle();

		float& operator [] (const int);
		friend std::ostream& operator<<(std::ostream&, const matrix_4&);
		matrix_4& operator = (const matrix_4&);
		matrix_4 operator + (const matrix_4&) const;
		matrix_4 operator - (const matrix_4&) const;
		matrix_4 operator * (const matrix_4&) const;
		matrix_4 operator / (const matrix_4&) const;

	private:

		array_2D mMatrix;
	};
}
