#pragma once

struct Vector2
{
	//Attributes
	double x;
	double y;
	double module;

	//Constructors
	Vector2();
	Vector2(double, double);
	Vector2(double);

	//Functions
	double Module();
	double SquaredLenght();
	void Normalize();

	//Operators to overload
	Vector2& operator = (const Vector2&);
	Vector2& operator += (const Vector2&);
	Vector2& operator -= (const Vector2&);
	Vector2& operator *= (const Vector2&);
	Vector2& operator /= (const Vector2&);
	Vector2 operator + (const Vector2&) const;
	Vector2 operator - (const Vector2&) const;
	Vector2 operator * (const Vector2&) const;
	Vector2 operator / (const Vector2&) const;
	bool operator == (const Vector2&) const;
	bool operator != (const Vector2&) const;
	friend Vector2 operator*(double, const Vector2&);
	friend Vector2 operator*(const Vector2&, double);

};