#include <cmath>

#include "Vector_3.hpp"

namespace Engine
{
	Vector_3::Vector_3()
	{
		mX = 0.0f;
		mY = 0.0f;
		mZ = 0.0f;
		mModule = 0.0f;
	}

	Vector_3::Vector_3(double pXValue, double pYValue, double pZValue)
	{
		mX = pXValue;
		mY = pYValue;
		mZ = pZValue;
		mModule = module();
	}

	Vector_3::Vector_3(double pValue)
	{
		mX = pValue;
		mY = pValue;
		mZ = pValue;
		mModule = module();
	}

	Vector_3::Vector_3(const Vector_2 &pTwoDimensionalVector)
	{
		mX = pTwoDimensionalVector.mX;
		mY = pTwoDimensionalVector.mY;
		mZ = 0.0f;
		mModule = module();
	}

	double Vector_3::module()
	{
		return std::sqrt((mX*mX) + (mY*mY) + (mZ*mZ));
	}

	double Vector_3::squared_lenght()
	{
		return ((mX*mX) + (mY*mY) + (mZ*mZ));
	}

	void Vector_3::normalize()
	{
		mModule = module();
		double multiplyFactor = 1 / mModule;
		mX = mX * multiplyFactor;
		mY = mY * multiplyFactor;
		mZ = mZ * multiplyFactor;
	}

	Vector_3 & Vector_3::operator=(const Vector_3 &pToEqual)
	{
		if (this == &pToEqual)
			return *this;
		else
		{
			mX = pToEqual.mX;
			mY = pToEqual.mY;
			mZ = pToEqual.mZ;
			return *this;
		}
	}

	Vector_3 & Vector_3::operator+=(const Vector_3 &pToAdd)
	{
		mX += pToAdd.mX;
		mY += pToAdd.mY;
		mZ += pToAdd.mZ;
		return *this;
	}

	Vector_3 & Vector_3::operator-=(const Vector_3 &pToSubstract)
	{
		mX -= pToSubstract.mX;
		mY -= pToSubstract.mY;
		mZ -= pToSubstract.mZ;
		return *this;
	}

	Vector_3 & Vector_3::operator*=(const Vector_3 &pToMultiply)
	{
		mX *= pToMultiply.mX;
		mY *= pToMultiply.mY;
		mZ *= pToMultiply.mZ;
		return *this;
	}

	Vector_3 & Vector_3::operator/=(const Vector_3 &pToDivide)
	{
		mX /= pToDivide.mX;
		mY /= pToDivide.mY;
		mZ /= pToDivide.mZ;
		return *this;
	}

	Vector_3 Vector_3::operator+(const Vector_3 &pToAdd) const
	{
		Vector_3 newVector = Vector_3((mX + pToAdd.mX), (mY + pToAdd.mY), (mZ + pToAdd.mZ));
		return newVector;
	}

	Vector_3 Vector_3::operator-(const Vector_3 &pToSubstract) const
	{
		Vector_3 newVector = Vector_3((mX - pToSubstract.mX), (mY - pToSubstract.mY), (mZ - pToSubstract.mZ));
		return newVector;
	}

	Vector_3 Vector_3::operator*(const Vector_3 &pToMultiply) const
	{
		Vector_3 newVector = Vector_3((mX * pToMultiply.mX), (mY * pToMultiply.mY), (mZ*pToMultiply.mZ));
		return newVector;
	}

	Vector_3 Vector_3::operator/(const Vector_3 &pToDivide) const
	{
		Vector_3 newVector = Vector_3((mX / pToDivide.mX), (mY / pToDivide.mY), (mZ / pToDivide.mZ));
		return newVector;
	}

	bool Vector_3::operator == (const Vector_3& pToCompare) const
	{
		if (mX == pToCompare.mX && mY == pToCompare.mY && mZ == pToCompare.mZ)
			return true;
		else
			return false;
	}

	bool Vector_3::operator != (const Vector_3& pToCompare) const
	{
		if (mX != pToCompare.mX || mY != pToCompare.mY || mZ != pToCompare.mZ)
			return true;
		else
			return false;
	}

	Vector_3 operator*(double pScaleUnit, const Vector_3 &pToMultiply)
	{
		Vector_3 newVector = Vector_3((pScaleUnit*pToMultiply.mX), (pScaleUnit*pToMultiply.mY), (pScaleUnit*pToMultiply.mZ));
		return newVector;
	}

	Vector_3 operator*(const Vector_3 &pToMultiply, double pScaleUnit)
	{
		Vector_3 newVector = Vector_3((pScaleUnit*pToMultiply.mX), (pScaleUnit*pToMultiply.mY), (pScaleUnit*pToMultiply.mZ));
		return newVector;
	}
}