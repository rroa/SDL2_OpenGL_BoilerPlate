#pragma once

#ifndef VECTOR_2_HPP
#define VECTOR_2_HPP

namespace Engine 
{
	struct Vector_2
	{
		//Constructors
		Vector_2();
		Vector_2(double, double);
		Vector_2(double);

		//Functions
		double module();
		double squared_lenght();
		void normalize();

		//Operators to overload
		Vector_2& operator = (const Vector_2&);
		Vector_2& operator += (const Vector_2&);
		Vector_2& operator -= (const Vector_2&);
		Vector_2& operator *= (const Vector_2&);
		Vector_2& operator /= (const Vector_2&);
		Vector_2 operator + (const Vector_2&) const;
		Vector_2 operator - (const Vector_2&) const;
		Vector_2 operator * (const Vector_2&) const;
		Vector_2 operator / (const Vector_2&) const;
		bool operator == (const Vector_2&) const;
		bool operator != (const Vector_2&) const;
		friend Vector_2 operator*(double, const Vector_2&);
		friend Vector_2 operator*(const Vector_2&, double);

		//Attributes
		double mX;
		double mY;
		double mModule;
	};
}

#endif // _VECTOR_2_H_
