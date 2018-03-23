#pragma once

#ifndef VECTOR_4_HPP
#define VECTOR_4_HPP

#include "Vector_2.hpp"
#include "Vector_3.hpp"

namespace Engine
{
	struct Vector_4
	{
		//Constructors
		Vector_4();
		Vector_4(double, double, double, double);
		Vector_4(double);
		Vector_4(const Vector_2&);
		Vector_4(const Vector_3&);

		//Functions
		double module();
		double squared_lenght();
		void normalize();

		//Operators to overload
		Vector_4& operator = (const Vector_4&);
		Vector_4& operator += (const Vector_4&);
		Vector_4& operator -= (const Vector_4&);
		Vector_4& operator *= (const Vector_4&);
		Vector_4& operator /= (const Vector_4&);
		Vector_4 operator + (const Vector_4&) const;
		Vector_4 operator - (const Vector_4&) const;
		Vector_4 operator * (const Vector_4&) const;
		Vector_4 operator / (const Vector_4&) const;
		bool operator == (const Vector_4&) const;
		bool operator != (const Vector_4&) const;
		friend Vector_4 operator*(double, const Vector_4&);
		friend Vector_4 operator*(const Vector_4&, double);

		//Attributes
		double mX;
		double mY;
		double mZ;
		double mW;
		double mModule;
	};
}

#endif // _VECTOR_4_H_

