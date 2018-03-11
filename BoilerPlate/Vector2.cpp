#include "Vector2.hpp"
#include <cmath>

Vector2::Vector2()
{
	x = 0.0f;
	y = 0.0f;
	module = 0.0f;
}

Vector2::Vector2(double xValue, double yValue)
{
	x = xValue;
	y = yValue;
	module= Module();
}

Vector2::Vector2(double value)
{
	x = value;
	y = value;
	module= Module();
}

double Vector2::Module()
{
	double value= std::sqrt((x*x) + (y*y));
	module = value;
	return value;
}

double Vector2::SquaredLenght()
{
	return (x*x + y*y);
}

void Vector2::Normalize()
{
	module= Module();
	double multiplyFactor = 1 / module;
	x = x * multiplyFactor;
	y = y * multiplyFactor;
}

Vector2 & Vector2::operator=(const Vector2 &toEqual)
{
	if (this == &toEqual)
		return *this;
	else
	{
		x = toEqual.x;
		y = toEqual.y;
		return *this;
	}
}

Vector2 & Vector2::operator+=(const Vector2 &toAdd)
{
	x += toAdd.x;
	y += toAdd.y;
	return *this;
}

Vector2 & Vector2::operator-=(const Vector2 &toSubstract)
{
	x -= toSubstract.x;
	y -= toSubstract.y;
	return *this;
}

Vector2 & Vector2::operator*=(const Vector2 &toMultiply)
{
	x *= toMultiply.x;
	y *= toMultiply.y;
	return *this;
}

Vector2 & Vector2::operator/=(const Vector2 &toDivide)
{
	x /= toDivide.x;
	y /= toDivide.y;
	return *this;
}

Vector2 Vector2::operator+(const Vector2 &toAdd) const
{
	Vector2 newVector = Vector2((x + toAdd.x), (y + toAdd.y));
	return newVector;
}

Vector2 Vector2::operator-(const Vector2 &toSubstract) const
{
	Vector2 newVector = Vector2((x - toSubstract.x), (y - toSubstract.y));
	return newVector;
}

Vector2 Vector2::operator*(const Vector2 &toMultiply) const
{
	Vector2 newVector = Vector2((x * toMultiply.x), (y * toMultiply.y));
	return newVector;
}

Vector2 Vector2::operator/(const Vector2 &toDivide) const
{
	Vector2 newVector = Vector2((x / toDivide.x), (y / toDivide.y));
	return newVector;
}

bool Vector2::operator == (const Vector2& toCompare) const
{
	if (x == toCompare.x && y == toCompare.y)
		return true;
	else
		return false;
}

bool Vector2::operator != (const Vector2& toCompare) const
{
	if (x != toCompare.x || y != toCompare.y)
		return true;
	else
		return false;
}

Vector2 operator*(double scaleUnit, const Vector2 &toMultiply)
{
	Vector2 newVector= Vector2((scaleUnit*toMultiply.x), (scaleUnit*toMultiply.y));
	return newVector;
}

Vector2 operator*(const Vector2 &toMultiply, double scaleUnit)
{
	Vector2 newVector = Vector2((scaleUnit*toMultiply.x), (scaleUnit*toMultiply.y));
	return newVector;
}

