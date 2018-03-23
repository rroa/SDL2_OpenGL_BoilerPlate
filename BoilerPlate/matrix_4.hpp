#pragma once

#ifndef MATRIX_4_HPP
#define MATRIX_4_HPP

#include <iostream>

#include "Vector_3.hpp"
#include "Vector_4.hpp"
#include "Math_Utilities.hpp"

namespace Engine {

	class matrix_4
	{
		//This struct hides the structure of the matrix
		/*struct array_2D
		{
			float mArray[4][4];
		};*/

	public:
		//Constructors
		matrix_4();
		matrix_4(float, float, float, float, float, float, float, float, float, float, float, float, float, float, float, float);
		matrix_4(float[16]);
		~matrix_4();

		//Public functions
		float* get_matrix();
		matrix_4 get_invert();
		matrix_4 get_transpose();
		void set_identity();
		Vector_3 get_angle();
		matrix_4 translate(Vector_4);
		matrix_4 rotate_x(float);
		matrix_4 rotate_y(float);
		matrix_4 rotate_z(float);
		matrix_4 generate_ortho(float, float, float, float, float, float);
		matrix_4 generate_perspective(float, float, float);
		matrix_4 look_at(Vector_3, Vector_3);

		//Global variables
		Math_Utilities mathTools;

		//Operators to overload
		friend std::ostream& operator<<(std::ostream&, const matrix_4&);
		matrix_4& operator = (const matrix_4&);
		matrix_4 operator + (const matrix_4&) const;
		matrix_4 operator - (const matrix_4&) const;
		matrix_4 operator * (const matrix_4&) const;
		matrix_4 operator / (matrix_4&) const;

	private:
		//Members
		float mMatrix[16];
	};
}

#endif // _MATRIX_4_H_
