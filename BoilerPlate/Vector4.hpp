#pragma once
#include "Vector2.hpp"
#include "Vector3.hpp"

struct Vector4
{
	//Attributes
	double x;
	double y;
	double z;
	double w;
	double module;

	//Constructors
	Vector4();
	Vector4(double, double, double, double);
	Vector4(double);
	Vector4(const Vector2&);
	Vector4(const Vector3&);

	//Functions
	double Module();
	double SquaredLenght();
	void Normalize();

	//Operators to overload
	Vector4& operator = (const Vector4&);
	Vector4& operator += (const Vector4&);
	Vector4& operator -= (const Vector4&);
	Vector4& operator *= (const Vector4&);
	Vector4& operator /= (const Vector4&);
	Vector4 operator + (const Vector4&) const;
	Vector4 operator - (const Vector4&) const;
	Vector4 operator * (const Vector4&) const;
	Vector4 operator / (const Vector4&) const;
	bool operator == (const Vector4&) const;
	bool operator != (const Vector4&) const;
	friend Vector4 operator*(double, const Vector4&);
	friend Vector4 operator*(const Vector4&, double);
};