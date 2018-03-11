#pragma once
#include "Vector2.hpp"

struct Vector3
{
	//Attributes
	double x;
	double y;
	double z;
	double module;

	//Constructors
	Vector3();
	Vector3(double, double, double);
	Vector3(double);
	Vector3(const Vector2&);


	//Functions
	double Module();
	double SquaredLenght();
	void Normalize();

	//Operators to overload
	Vector3& operator = (const Vector3&);
	Vector3& operator += (const Vector3&);
	Vector3& operator -= (const Vector3&);
	Vector3& operator *= (const Vector3&);
	Vector3& operator /= (const Vector3&);
	Vector3 operator + (const Vector3&) const;
	Vector3 operator - (const Vector3&) const;
	Vector3 operator * (const Vector3&) const;
	Vector3 operator / (const Vector3&) const;
	bool operator == (const Vector3&) const;
	bool operator != (const Vector3&) const;
	friend Vector3 operator*(double, const Vector3&);
	friend Vector3 operator*(const Vector3&, double);

};