#include "matrix_4.hpp"
#include <cmath>

namespace Engine
{
	//Default constructor initializes the matrix with its identity
	matrix_4::matrix_4()
	{
		set_identity();
	}

	//Takes 16 parameters, assigned in column major order
	matrix_4::matrix_4(float value1, float value2, float value3, float value4, float value5, float value6, float value7, float value8, float value9, float value10, float value11, float value12, float value13, float value14, float value15, float value16)
	{
		mMatrix.mArray[0][0] = value1;
		mMatrix.mArray[1][0] = value2;
		mMatrix.mArray[2][0] = value3;
		mMatrix.mArray[3][0] = value4;

		mMatrix.mArray[0][1] = value5;
		mMatrix.mArray[1][1] = value6;
		mMatrix.mArray[2][1] = value7;
		mMatrix.mArray[3][1] = value8;

		mMatrix.mArray[0][2] = value9;
		mMatrix.mArray[1][2] = value10;
		mMatrix.mArray[2][2] = value11;
		mMatrix.mArray[3][2] = value12;

		mMatrix.mArray[0][3] = value13;
		mMatrix.mArray[1][3] = value14;
		mMatrix.mArray[2][3] = value15;
		mMatrix.mArray[3][3] = value16;
	}

	//Takes an array with 16 positions
	matrix_4::matrix_4(float pValues[16])
	{
		int arrayIndex = 0;
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				mMatrix.mArray[j][i] = pValues[arrayIndex];
				arrayIndex++;
			}
		}

	}


	matrix_4::~matrix_4()
	{
	}

	//Set the matrix to its identity
	void matrix_4::set_identity()
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				if (i == j)
				{
					mMatrix.mArray[j][i] = 1;
				}
				else
				{
					mMatrix.mArray[j][i] = 0;
				}
			}
		}
	}

	//Returns the euclidean angle os the matrix
	Vector_3 matrix_4::get_angle()
	{
		Vector_3 euclideanAngle;

		if (mMatrix.mArray[0][0] == 1.0f || mMatrix.mArray[0][0] == -1.0f)
		{
			euclideanAngle.mX = 0; //Pitch
			euclideanAngle.mY = atan2f(mMatrix.mArray[0][2], mMatrix.mArray[2][3]); //Yaw
			euclideanAngle.mZ = 0; //Roll
		}
		else
		{
			euclideanAngle.mX = asinf(mMatrix.mArray[1][0]); //Pitch
			euclideanAngle.mY = atan2f(-mMatrix.mArray[2][0], mMatrix.mArray[0][0]); //Yaw
			euclideanAngle.mZ = atan2f(-mMatrix.mArray[1][2], mMatrix.mArray[1][1]); //Roll
		}

		return euclideanAngle;
	}

	//Translate the matrix
	matrix_4 matrix_4::translate(Vector_4 pTranslation)
	{
		matrix_4 newMatrix = matrix_4();
		newMatrix[3] = pTranslation.mX;
		newMatrix[7] = pTranslation.mY;
		newMatrix[11] = pTranslation.mZ;
		return newMatrix;
	}

	//Rotates the matrix in th X axis
	matrix_4 matrix_4::rotate_x(float angle)
	{
		matrix_4 newMatrix = matrix_4();
		newMatrix[5] = std::cos(-angle);
		newMatrix[6] = -std::sin(-angle);
		newMatrix[9] = std::sin(-angle);
		newMatrix[10] = std::cos(-angle);
		return newMatrix;
	}

	//Rotates the matrix in th Y axis
	matrix_4 matrix_4::rotate_y(float angle)
	{
		matrix_4 newMatrix = matrix_4();
		newMatrix[0] = std::cos(-angle);
		newMatrix[2] = std::sin(-angle);
		newMatrix[8] = -std::sin(-angle);
		newMatrix[10] = std::cos(-angle);
		return newMatrix;
	}

	//Rotates the matrix in th Z axis
	matrix_4 matrix_4::rotate_z(float angle)
	{
		matrix_4 newMatrix = matrix_4();
		newMatrix[0] = std::cos(-angle);
		newMatrix[1] = -std::sin(-angle);
		newMatrix[4] = std::sin(-angle);
		newMatrix[5] = std::cos(-angle);
		return newMatrix;
	}

	//Returns the matrix
	matrix_4::array_2D matrix_4::get_matrix()
	{
		return mMatrix;
	}

	//Returns the inverse of the matrix
	matrix_4 matrix_4::get_invert()
	{
		float determinant;
		matrix_4 inverse, matrixCopy;
		matrixCopy.mMatrix = mMatrix;

		inverse[0] = matrixCopy[5] * matrixCopy[10] * matrixCopy[15] -
			matrixCopy[5] * matrixCopy[11] * matrixCopy[14] -
			matrixCopy[9] * matrixCopy[6] * matrixCopy[15] +
			matrixCopy[9] * matrixCopy[7] * matrixCopy[14] +
			matrixCopy[13] * matrixCopy[6] * matrixCopy[11] -
			matrixCopy[13] * matrixCopy[7] * matrixCopy[10];

		inverse[4] = -matrixCopy[4] * matrixCopy[10] * matrixCopy[15] +
			matrixCopy[4] * matrixCopy[11] * matrixCopy[14] +
			matrixCopy[8] * matrixCopy[6] * matrixCopy[15] -
			matrixCopy[8] * matrixCopy[7] * matrixCopy[14] -
			matrixCopy[12] * matrixCopy[6] * matrixCopy[11] +
			matrixCopy[12] * matrixCopy[7] * matrixCopy[10];

		inverse[8] = matrixCopy[4] * matrixCopy[9] * matrixCopy[15] -
			matrixCopy[4] * matrixCopy[11] * matrixCopy[13] -
			matrixCopy[8] * matrixCopy[5] * matrixCopy[15] +
			matrixCopy[8] * matrixCopy[7] * matrixCopy[13] +
			matrixCopy[12] * matrixCopy[5] * matrixCopy[11] -
			matrixCopy[12] * matrixCopy[7] * matrixCopy[9];

		inverse[12] = -matrixCopy[4] * matrixCopy[9] * matrixCopy[14] +
			matrixCopy[4] * matrixCopy[10] * matrixCopy[13] +
			matrixCopy[8] * matrixCopy[5] * matrixCopy[14] -
			matrixCopy[8] * matrixCopy[6] * matrixCopy[13] -
			matrixCopy[12] * matrixCopy[5] * matrixCopy[10] +
			matrixCopy[12] * matrixCopy[6] * matrixCopy[9];

		inverse[1] = -matrixCopy[1] * matrixCopy[10] * matrixCopy[15] +
			matrixCopy[1] * matrixCopy[11] * matrixCopy[14] +
			matrixCopy[9] * matrixCopy[2] * matrixCopy[15] -
			matrixCopy[9] * matrixCopy[3] * matrixCopy[14] -
			matrixCopy[13] * matrixCopy[2] * matrixCopy[11] +
			matrixCopy[13] * matrixCopy[3] * matrixCopy[10];

		inverse[5] = matrixCopy[0] * matrixCopy[10] * matrixCopy[15] -
			matrixCopy[0] * matrixCopy[11] * matrixCopy[14] -
			matrixCopy[8] * matrixCopy[2] * matrixCopy[15] +
			matrixCopy[8] * matrixCopy[3] * matrixCopy[14] +
			matrixCopy[12] * matrixCopy[2] * matrixCopy[11] -
			matrixCopy[12] * matrixCopy[3] * matrixCopy[10];

		inverse[9] = -matrixCopy[0] * matrixCopy[9] * matrixCopy[15] +
			matrixCopy[0] * matrixCopy[11] * matrixCopy[13] +
			matrixCopy[8] * matrixCopy[1] * matrixCopy[15] -
			matrixCopy[8] * matrixCopy[3] * matrixCopy[13] -
			matrixCopy[12] * matrixCopy[1] * matrixCopy[11] +
			matrixCopy[12] * matrixCopy[3] * matrixCopy[9];

		inverse[13] = matrixCopy[0] * matrixCopy[9] * matrixCopy[14] -
			matrixCopy[0] * matrixCopy[10] * matrixCopy[13] -
			matrixCopy[8] * matrixCopy[1] * matrixCopy[14] +
			matrixCopy[8] * matrixCopy[2] * matrixCopy[13] +
			matrixCopy[12] * matrixCopy[1] * matrixCopy[10] -
			matrixCopy[12] * matrixCopy[2] * matrixCopy[9];

		inverse[2] = matrixCopy[1] * matrixCopy[6] * matrixCopy[15] -
			matrixCopy[1] * matrixCopy[7] * matrixCopy[14] -
			matrixCopy[5] * matrixCopy[2] * matrixCopy[15] +
			matrixCopy[5] * matrixCopy[3] * matrixCopy[14] +
			matrixCopy[13] * matrixCopy[2] * matrixCopy[7] -
			matrixCopy[13] * matrixCopy[3] * matrixCopy[6];

		inverse[6] = -matrixCopy[0] * matrixCopy[6] * matrixCopy[15] +
			matrixCopy[0] * matrixCopy[7] * matrixCopy[14] +
			matrixCopy[4] * matrixCopy[2] * matrixCopy[15] -
			matrixCopy[4] * matrixCopy[3] * matrixCopy[14] -
			matrixCopy[12] * matrixCopy[2] * matrixCopy[7] +
			matrixCopy[12] * matrixCopy[3] * matrixCopy[6];

		inverse[10] = matrixCopy[0] * matrixCopy[5] * matrixCopy[15] -
			matrixCopy[0] * matrixCopy[7] * matrixCopy[13] -
			matrixCopy[4] * matrixCopy[1] * matrixCopy[15] +
			matrixCopy[4] * matrixCopy[3] * matrixCopy[13] +
			matrixCopy[12] * matrixCopy[1] * matrixCopy[7] -
			matrixCopy[12] * matrixCopy[3] * matrixCopy[5];

		inverse[14] = -matrixCopy[0] * matrixCopy[5] * matrixCopy[14] +
			matrixCopy[0] * matrixCopy[6] * matrixCopy[13] +
			matrixCopy[4] * matrixCopy[1] * matrixCopy[14] -
			matrixCopy[4] * matrixCopy[2] * matrixCopy[13] -
			matrixCopy[12] * matrixCopy[1] * matrixCopy[6] +
			matrixCopy[12] * matrixCopy[2] * matrixCopy[5];

		inverse[3] = -matrixCopy[1] * matrixCopy[6] * matrixCopy[11] +
			matrixCopy[1] * matrixCopy[7] * matrixCopy[10] +
			matrixCopy[5] * matrixCopy[2] * matrixCopy[11] -
			matrixCopy[5] * matrixCopy[3] * matrixCopy[10] -
			matrixCopy[9] * matrixCopy[2] * matrixCopy[7] +
			matrixCopy[9] * matrixCopy[3] * matrixCopy[6];

		inverse[7] = matrixCopy[0] * matrixCopy[6] * matrixCopy[11] -
			matrixCopy[0] * matrixCopy[7] * matrixCopy[10] -
			matrixCopy[4] * matrixCopy[2] * matrixCopy[11] +
			matrixCopy[4] * matrixCopy[3] * matrixCopy[10] +
			matrixCopy[8] * matrixCopy[2] * matrixCopy[7] -
			matrixCopy[8] * matrixCopy[3] * matrixCopy[6];

		inverse[11] = -matrixCopy[0] * matrixCopy[5] * matrixCopy[11] +
			matrixCopy[0] * matrixCopy[7] * matrixCopy[9] +
			matrixCopy[4] * matrixCopy[1] * matrixCopy[11] -
			matrixCopy[4] * matrixCopy[3] * matrixCopy[9] -
			matrixCopy[8] * matrixCopy[1] * matrixCopy[7] +
			matrixCopy[8] * matrixCopy[3] * matrixCopy[5];

		inverse[15] = matrixCopy[0] * matrixCopy[5] * matrixCopy[10] -
			matrixCopy[0] * matrixCopy[6] * matrixCopy[9] -
			matrixCopy[4] * matrixCopy[1] * matrixCopy[10] +
			matrixCopy[4] * matrixCopy[2] * matrixCopy[9] +
			matrixCopy[8] * matrixCopy[1] * matrixCopy[6] -
			matrixCopy[8] * matrixCopy[2] * matrixCopy[5];

		determinant = (matrixCopy[0] * inverse[0]) + (matrixCopy[1] * inverse[4]) + (matrixCopy[2] * inverse[8]) + (matrixCopy[3] * inverse[12]);

		if (determinant == 0)
		{
			return NULL;
		}
		else
		{
			//Calculates the inverse by multiplying the inverse of the determinant with the adjunt matrix
			determinant = 1 / determinant;
			for (int i = 0; i < 16; i++)
			{
				inverse[i] = inverse[i] * determinant;
			}

			return inverse;
		}
	}

	matrix_4 matrix_4::get_transpose()
	{
		matrix_4 transposedMatrix;

		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				transposedMatrix.mMatrix.mArray[j][i] = mMatrix.mArray[i][j];
			}
		}

		return transposedMatrix;
	}

	//To manage a single index
	float& matrix_4::operator[](const int pIndex)
	{
		int rowIndex = pIndex % 4;
		int columnIndex = pIndex / 4;
		return mMatrix.mArray[rowIndex][columnIndex];
	}

	//To print the matrix
	std::ostream & operator<<(std::ostream &pOs, const matrix_4 &matrix)
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				pOs << matrix.mMatrix.mArray[i][j] << " ";
			}
			pOs << "\n";
		}

		return pOs;
	}

	matrix_4 & matrix_4::operator=(const matrix_4 &pToEqual)
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				mMatrix.mArray[j][i] = pToEqual.mMatrix.mArray[j][i];
			}
		}

		return *this;
	}

	matrix_4 matrix_4::operator+(const matrix_4 &pToAdd) const
	{
		matrix_4 newMatrix;

		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				newMatrix.mMatrix.mArray[j][i] = mMatrix.mArray[j][i] + pToAdd.mMatrix.mArray[j][i];
			}
		}

		return newMatrix;
	}

	matrix_4 matrix_4::operator-(const matrix_4 &pToSubstract) const
	{
		matrix_4 newMatrix;

		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				newMatrix.mMatrix.mArray[j][i] = mMatrix.mArray[j][i] - pToSubstract.mMatrix.mArray[j][i];
			}
		}

		return newMatrix;
	}

	matrix_4 matrix_4::operator*(const matrix_4 &pToMultiply) const
	{
		matrix_4 newMatrix;
		int rowCounter = 0;

		while (rowCounter<4)
		{
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					newMatrix.mMatrix.mArray[rowCounter][i] += mMatrix.mArray[rowCounter][j] * pToMultiply.mMatrix.mArray[j][i];
				}
			}

			rowCounter++;
		}

		return newMatrix;
	}

	//As the divide operation does not exist in matrices, it has to be multiplied with the inverse of the multiplying matrix
	Engine::matrix_4 Engine::matrix_4::operator/(matrix_4 &pToDivide) const
	{
		matrix_4 newMatrix, toDivideInverted;

		toDivideInverted = pToDivide.get_invert();

		newMatrix = *this * toDivideInverted;

		return newMatrix;
	}
}
