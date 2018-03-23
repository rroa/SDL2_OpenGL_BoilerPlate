#include <cmath>

#include "Vector_2.hpp"

namespace Engine 
{
	Vector_2::Vector_2()
	{
		mX = 0.0f;
		mY = 0.0f;
		mModule = 0.0f;
	}

	Vector_2::Vector_2(double pXValue, double pYValue)
	{
		mX = pXValue;
		mY = pYValue;
		mModule = module();
	}

	Vector_2::Vector_2(double pValue)
	{
		mX = pValue;
		mY = pValue;
		mModule = module();
	}

	double Vector_2::module()
	{
		double value = std::sqrt((mX*mX) + (mY*mY));
		mModule = value;
		return value;
	}

	double Vector_2::squared_lenght()
	{
		return (mX*mX + mY * mY);
	}

	void Vector_2::normalize()
	{
		mModule = module();
		double multiplyFactor = 1 / mModule;
		mX = mX * multiplyFactor;
		mY = mY * multiplyFactor;
	}

	Vector_2 & Vector_2::operator=(const Vector_2 &pToEqual)
	{
		if (this == &pToEqual)
			return *this;
		else
		{
			mX = pToEqual.mX;
			mY = pToEqual.mY;
			return *this;
		}
	}

	Vector_2 & Vector_2::operator+=(const Vector_2 &pToAdd)
	{
		mX += pToAdd.mX;
		mY += pToAdd.mY;
		return *this;
	}

	Vector_2 & Vector_2::operator-=(const Vector_2 &pToSubstract)
	{
		mX -= pToSubstract.mX;
		mY -= pToSubstract.mY;
		return *this;
	}

	Vector_2 & Vector_2::operator*=(const Vector_2 &pToMultiply)
	{
		mX *= pToMultiply.mX;
		mY *= pToMultiply.mY;
		return *this;
	}

	Vector_2 & Vector_2::operator/=(const Vector_2 &pToDivide)
	{
		mX /= pToDivide.mX;
		mY /= pToDivide.mY;
		return *this;
	}

	Vector_2 Vector_2::operator+(const Vector_2 &pToAdd) const
	{
		Vector_2 newVector = Vector_2((mX + pToAdd.mX), (mY + pToAdd.mY));
		return newVector;
	}

	Vector_2 Vector_2::operator-(const Vector_2 &pToSubstract) const
	{
		Vector_2 newVector = Vector_2((mX - pToSubstract.mX), (mY - pToSubstract.mY));
		return newVector;
	}

	Vector_2 Vector_2::operator*(const Vector_2 &pToMultiply) const
	{
		Vector_2 newVector = Vector_2((mX * pToMultiply.mX), (mY * pToMultiply.mY));
		return newVector;
	}

	Vector_2 Vector_2::operator/(const Vector_2 &pToDivide) const
	{
		Vector_2 newVector = Vector_2((mX / pToDivide.mX), (mY / pToDivide.mY));
		return newVector;
	}

	bool Vector_2::operator == (const Vector_2& pToCompare) const
	{
		if (mX == pToCompare.mX && mY == pToCompare.mY)
			return true;
		else
			return false;
	}

	bool Vector_2::operator != (const Vector_2& pToCompare) const
	{
		if (mX != pToCompare.mX || mY != pToCompare.mY)
			return true;
		else
			return false;
	}

	Vector_2 operator*(double pScaleUnit, const Vector_2 &pToMultiply)
	{
		Vector_2 newVector = Vector_2((pScaleUnit*pToMultiply.mX), (pScaleUnit*pToMultiply.mY));
		return newVector;
	}

	Vector_2 operator*(const Vector_2 &pToMultiply, double pScaleUnit)
	{
		Vector_2 newVector = Vector_2((pScaleUnit*pToMultiply.mX), (pScaleUnit*pToMultiply.mY));
		return newVector;
	}
}