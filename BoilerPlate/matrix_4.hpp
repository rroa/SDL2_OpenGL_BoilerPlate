#pragma once
#include "Vector3.hpp"

namespace engine {

	class matrix_4
	{
	public:
		matrix_4();
		matrix_4(float, float, float, float, float, float, float, float, float, float, float, float, float, float, float, float);
		matrix_4(float[]);
		~matrix_4();

		float *get_matrix();
		matrix_4 get_transpose();
		void set_identity();
		Vector3 get_angle();

		float& operator [] (const int pIndex);
		matrix_4& operator = (const matrix_4&);
		matrix_4 operator + (const matrix_4&) const;
		matrix_4 operator - (const matrix_4&) const;
		matrix_4 operator * (const matrix_4&) const;
		matrix_4 operator / (const matrix_4&) const;

	private:
		float mMatrix[4][4];
	};
}
