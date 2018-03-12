#include <cmath>

#include "Vector_4.hpp"

namespace Engine
{
	Vector_4::Vector_4()
	{
		mX = 0.0f;
		mY = 0.0f;
		mZ = 0.0f;
		mW = 0.0f;
		mModule = 0.0f;
	}

	Vector_4::Vector_4(double pXValue, double pYValue, double pZValue, double pWValue)
	{
		mX = pXValue;
		mY = pYValue;
		mZ = pZValue;
		mW = pWValue;
		mModule = module();
	}

	Vector_4::Vector_4(double pValue)
	{
		mX = pValue;
		mY = pValue;
		mZ = pValue;
		mW = pValue;
		mModule = module();
	}

	Vector_4::Vector_4(const Vector_2 &pTwoDimensionalVector)
	{
		mX = pTwoDimensionalVector.mX;
		mY = pTwoDimensionalVector.mY;
		mZ = 0.0f;
		mW = 0.0f;
		mModule = module();
	}

	Vector_4::Vector_4(const Vector_3 &pThreeDimensionalVector)
	{
		mX = pThreeDimensionalVector.mX;
		mY = pThreeDimensionalVector.mY;
		mZ = pThreeDimensionalVector.mZ;
		mW = 0.0f;
		mModule = module();
	}

	double Vector_4::module()
	{
		return std::sqrt((mX*mX) + (mY*mY) + (mZ*mZ) + (mW*mW));
	}

	double Vector_4::squared_lenght()
	{
		return ((mX*mX) + (mY*mY) + (mZ*mZ) + (mW*mW));
	}

	void Vector_4::normalize()
	{
		mModule = module();
		double multiplyFactor = 1 / mModule;
		mX = mX * multiplyFactor;
		mY = mY * multiplyFactor;
		mZ = mZ * multiplyFactor;
		mW = mW * multiplyFactor;
	}

	Vector_4 & Vector_4::operator=(const Vector_4 &pToEqual)
	{
		if (this == &pToEqual)
			return *this;
		else
		{
			mX = pToEqual.mX;
			mY = pToEqual.mY;
			mZ = pToEqual.mZ;
			mW = pToEqual.mW;
			return *this;
		}
	}

	Vector_4 & Vector_4::operator+=(const Vector_4 &pToAdd)
	{
		mX += pToAdd.mX;
		mY += pToAdd.mY;
		mZ += pToAdd.mZ;
		mW += pToAdd.mW;
		return *this;
	}

	Vector_4 & Vector_4::operator-=(const Vector_4 &pToSubstract)
	{
		mX -= pToSubstract.mX;
		mY -= pToSubstract.mY;
		mZ -= pToSubstract.mZ;
		mW -= pToSubstract.mW;
		return *this;
	}

	Vector_4 & Vector_4::operator*=(const Vector_4 &pToMultiply)
	{
		mX *= pToMultiply.mX;
		mY *= pToMultiply.mY;
		mZ *= pToMultiply.mZ;
		mW *= pToMultiply.mW;
		return *this;
	}

	Vector_4 & Vector_4::operator/=(const Vector_4 &pToDivide)
	{
		mX /= pToDivide.mX;
		mY /= pToDivide.mY;
		mZ /= pToDivide.mZ;
		mW /= pToDivide.mW;
		return *this;
	}

	Vector_4 Vector_4::operator+(const Vector_4 &pToAdd) const
	{
		Vector_4 newVector = Vector_4((mX + pToAdd.mX), (mY + pToAdd.mY), (mZ + pToAdd.mZ), (mW + pToAdd.mW));
		return newVector;
	}

	Vector_4 Vector_4::operator-(const Vector_4 &pToSubstract) const
	{
		Vector_4 newVector = Vector_4((mX - pToSubstract.mX), (mY - pToSubstract.mY), (mZ - pToSubstract.mZ), (mW - pToSubstract.mW));
		return newVector;
	}

	Vector_4 Vector_4::operator*(const Vector_4 &pToMultiply) const
	{
		Vector_4 newVector = Vector_4((mX * pToMultiply.mX), (mY * pToMultiply.mY), (mZ * pToMultiply.mZ), (mW * pToMultiply.mW));
		return newVector;
	}

	Vector_4 Vector_4::operator/(const Vector_4 &pToDivide) const
	{
		Vector_4 newVector = Vector_4((mX / pToDivide.mX), (mY / pToDivide.mY), (mZ / pToDivide.mZ), (mW / pToDivide.mW));
		return newVector;
	}

	bool Vector_4::operator == (const Vector_4& pToCompare) const
	{
		if (mX == pToCompare.mX && mY == pToCompare.mY && mZ == pToCompare.mZ && mW == pToCompare.mW)
			return true;
		else
			return false;
	}

	bool Vector_4::operator != (const Vector_4& pToCompare) const
	{
		if (mX != pToCompare.mX || mY != pToCompare.mY || mZ != pToCompare.mZ || mW != pToCompare.mW)
			return true;
		else
			return false;
	}

	Vector_4 operator*(double pScaleUnit, const Vector_4 &pToMultiply)
	{
		Vector_4 newVector = Vector_4((pScaleUnit * pToMultiply.mX), (pScaleUnit * pToMultiply.mY), (pScaleUnit * pToMultiply.mZ), (pScaleUnit * pToMultiply.mW));
		return newVector;
	}

	Vector_4 operator*(const Vector_4 &pToMultiply, double pScaleUnit)
	{
		Vector_4 newVector = Vector_4((pScaleUnit * pToMultiply.mX), (pScaleUnit * pToMultiply.mY), (pScaleUnit * pToMultiply.mZ), (pScaleUnit * pToMultiply.mW));
		return newVector;
	}
}
