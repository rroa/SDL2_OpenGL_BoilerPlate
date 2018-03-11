#include "Vector4.hpp"
#include <cmath>

Vector4::Vector4()
{
	x = 0.0f;
	y = 0.0f;
	z = 0.0f;
	w = 0.0f;
	module = 0.0f;
}

Vector4::Vector4(double xValue, double yValue, double zValue, double wValue)
{
	x = xValue;
	y = yValue;
	z = zValue;
	w = wValue;
	module = Module();
}

Vector4::Vector4(double value)
{
	x = value;
	y = value;
	z = value;
	w = value;
	module = Module();
}

Vector4::Vector4(const Vector2 &twoDimensionalVector)
{
	x = twoDimensionalVector.x;
	y = twoDimensionalVector.y;
	z = 0.0f;
	w = 0.0f;
	module = Module();
}

Vector4::Vector4(const Vector3 &threeDimensionalVector)
{
	x = threeDimensionalVector.x;
	y = threeDimensionalVector.y;
	z = threeDimensionalVector.z;
	w = 0.0f;
	module = Module();
}

double Vector4::Module()
{
	return std::sqrt((x*x) + (y*y) + (z*z) + (w*w));
}

double Vector4::SquaredLenght()
{
	return ((x*x) + (y*y) + (z*z) + (w*w));
}

void Vector4::Normalize()
{
	module = Module();
	double multiplyFactor = 1 / module;
	x = x * multiplyFactor;
	y = y * multiplyFactor;
	z = z * multiplyFactor;
	w = w * multiplyFactor;
}

Vector4 & Vector4::operator=(const Vector4 &toEqual)
{
	if (this == &toEqual)
		return *this;
	else
	{
		x = toEqual.x;
		y = toEqual.y;
		z = toEqual.z;
		w = toEqual.w;
		return *this;
	}
}

Vector4 & Vector4::operator+=(const Vector4 &toAdd)
{
	x += toAdd.x;
	y += toAdd.y;
	z += toAdd.z;
	w += toAdd.w;
	return *this;
}

Vector4 & Vector4::operator-=(const Vector4 &toSubstract)
{
	x -= toSubstract.x;
	y -= toSubstract.y;
	z -= toSubstract.z;
	w -= toSubstract.w;
	return *this;
}

Vector4 & Vector4::operator*=(const Vector4 &toMultiply)
{
	x *= toMultiply.x;
	y *= toMultiply.y;
	z *= toMultiply.z;
	w *= toMultiply.w;
	return *this;
}

Vector4 & Vector4::operator/=(const Vector4 &toDivide)
{
	x /= toDivide.x;
	y /= toDivide.y;
	z /= toDivide.z;
	w /= toDivide.w;
	return *this;
}

Vector4 Vector4::operator+(const Vector4 &toAdd) const
{
	Vector4 newVector = Vector4((x + toAdd.x), (y + toAdd.y), (z + toAdd.z), (w + toAdd.w));
	return newVector;
}

Vector4 Vector4::operator-(const Vector4 &toSubstract) const
{
	Vector4 newVector = Vector4((x - toSubstract.x), (y - toSubstract.y), (z - toSubstract.z), (w - toSubstract.w));
	return newVector;
}

Vector4 Vector4::operator*(const Vector4 &toMultiply) const
{
	Vector4 newVector = Vector4((x * toMultiply.x), (y * toMultiply.y), (z*toMultiply.z), (w*toMultiply.w));
	return newVector;
}

Vector4 Vector4::operator/(const Vector4 &toDivide) const
{
	Vector4 newVector = Vector4((x / toDivide.x), (y / toDivide.y), (z / toDivide.z), (w / toDivide.w));
	return newVector;
}

bool Vector4::operator == (const Vector4& toCompare) const
{
	if (x == toCompare.x && y == toCompare.y && z == toCompare.z && w == toCompare.w)
		return true;
	else
		return false;
}

bool Vector4::operator != (const Vector4& toCompare) const
{
	if (x != toCompare.x || y != toCompare.y || z != toCompare.z || w != toCompare.w)
		return true;
	else
		return false;
}

Vector4 operator*(double scaleUnit, const Vector4 &toMultiply)
{
	Vector4 newVector = Vector4((scaleUnit*toMultiply.x), (scaleUnit*toMultiply.y), (scaleUnit*toMultiply.z), (scaleUnit*toMultiply.w));
	return newVector;
}

Vector4 operator*(const Vector4 &toMultiply, double scaleUnit)
{
	Vector4 newVector = Vector4((scaleUnit*toMultiply.x), (scaleUnit*toMultiply.y), (scaleUnit*toMultiply.z), (scaleUnit*toMultiply.w));
	return newVector;
}