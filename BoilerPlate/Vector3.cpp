#include "Vector3.hpp"
#include <cmath>

Vector3::Vector3()
{
	x = 0.0f;
	y = 0.0f;
	z = 0.0f;
	module = 0.0f;
}

Vector3::Vector3(double xValue, double yValue, double zValue)
{
	x = xValue;
	y = yValue;
	z = zValue;
	module = Module();
}

Vector3::Vector3(double value)
{
	x = value;
	y = value;
	z = value;
	module = Module();
}

Vector3::Vector3(const Vector2 &twoDimensionalVector)
{
	x = twoDimensionalVector.x;
	y = twoDimensionalVector.y;
	z = 0.0f;
	module = Module();
}

double Vector3::Module()
{
	return std::sqrt((x*x) + (y*y) + (z*z));
}

double Vector3::SquaredLenght()
{
	return ((x*x) + (y*y) + (z*z));
}

void Vector3::Normalize()
{
	module = Module();
	double multiplyFactor = 1 / module;
	x = x * multiplyFactor;
	y = y * multiplyFactor;
	z = z * multiplyFactor;
}

Vector3 & Vector3::operator=(const Vector3 &toEqual)
{
	if (this == &toEqual)
		return *this;
	else
	{
		x = toEqual.x;
		y = toEqual.y;
		z = toEqual.z;
		return *this;
	}
}

Vector3 & Vector3::operator+=(const Vector3 &toAdd)
{
	x += toAdd.x;
	y += toAdd.y;
	z += toAdd.z;
	return *this;
}

Vector3 & Vector3::operator-=(const Vector3 &toSubstract)
{
	x -= toSubstract.x;
	y -= toSubstract.y;
	z -= toSubstract.z;
	return *this;
}

Vector3 & Vector3::operator*=(const Vector3 &toMultiply)
{
	x *= toMultiply.x;
	y *= toMultiply.y;
	z *= toMultiply.z;
	return *this;
}

Vector3 & Vector3::operator/=(const Vector3 &toDivide)
{
	x /= toDivide.x;
	y /= toDivide.y;
	z /= toDivide.z;
	return *this;
}

Vector3 Vector3::operator+(const Vector3 &toAdd) const
{
	Vector3 newVector = Vector3((x + toAdd.x), (y + toAdd.y), (z + toAdd.z));
	return newVector;
}

Vector3 Vector3::operator-(const Vector3 &toSubstract) const
{
	Vector3 newVector = Vector3((x - toSubstract.x), (y - toSubstract.y), (z - toSubstract.z));
	return newVector;
}

Vector3 Vector3::operator*(const Vector3 &toMultiply) const
{
	Vector3 newVector = Vector3((x * toMultiply.x), (y * toMultiply.y), (z*toMultiply.z));
	return newVector;
}

Vector3 Vector3::operator/(const Vector3 &toDivide) const
{
	Vector3 newVector = Vector3((x / toDivide.x), (y / toDivide.y), (z / toDivide.z));
	return newVector;
}

bool Vector3::operator == (const Vector3& toCompare) const
{
	if (x == toCompare.x && y == toCompare.y && z == toCompare.z)  
		return true;
	else
		return false;
}

bool Vector3::operator != (const Vector3& toCompare) const
{
	if (x != toCompare.x || y != toCompare.y || z != toCompare.z)
		return true;
	else
		return false;
}

Vector3 operator*(double scaleUnit, const Vector3 &toMultiply)
{
	Vector3 newVector = Vector3((scaleUnit*toMultiply.x), (scaleUnit*toMultiply.y), (scaleUnit*toMultiply.z));
	return newVector;
}

Vector3 operator*(const Vector3 &toMultiply, double scaleUnit)
{
	Vector3 newVector = Vector3((scaleUnit*toMultiply.x), (scaleUnit*toMultiply.y), (scaleUnit*toMultiply.z));
	return newVector;
}


