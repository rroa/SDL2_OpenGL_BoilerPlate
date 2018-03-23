#pragma once

#ifndef VECTOR_3_HPP
#define VECTOR_3_HPP

#include "Vector_2.hpp"

namespace Engine
{
	struct Vector_3
	{
		//Constructors
		Vector_3();
		Vector_3(double, double, double);
		Vector_3(double);
		Vector_3(const Vector_2&);

		//Functions
		double module();
		double squared_lenght();
		Vector_3 cross_product(Vector_3 pToCross);
		void normalize();

		//Operators to overload
		Vector_3& operator = (const Vector_3&);
		Vector_3& operator += (const Vector_3&);
		Vector_3& operator -= (const Vector_3&);
		Vector_3& operator *= (const Vector_3&);
		Vector_3& operator /= (const Vector_3&);
		Vector_3 operator + (const Vector_3&) const;
		Vector_3 operator - (const Vector_3&) const;
		Vector_3 operator * (const Vector_3&) const;
		Vector_3 operator / (const Vector_3&) const;
		bool operator == (const Vector_3&) const;
		bool operator != (const Vector_3&) const;
		friend Vector_3 operator*(double, const Vector_3&);
		friend Vector_3 operator*(const Vector_3&, double);

		//Attributes
		double mX;
		double mY;
		double mZ;
		double mModule;
	};
}

#endif // _VECTOR_3_H_
