#include "matrix_4.hpp"
#include <cmath>

engine::matrix_4::matrix_4()
{
	set_identity();
}

engine::matrix_4::matrix_4(float value1, float value2, float value3, float value4, float value5, float value6, float value7, float value8, float value9, float value10, float value11, float value12, float value13, float value14, float value15, float value16)
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

engine::matrix_4::matrix_4(float values[])
{

}


engine::matrix_4::~matrix_4()
{
}

void engine::matrix_4::set_identity()
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

Vector3 engine::matrix_4::get_angle()
{
	Vector3 euclideanAngle;

	if (mMatrix.mArray[0][0] == 1.0f || mMatrix.mArray[0][0] == -1.0f)
	{
		euclideanAngle.x = 0;
		euclideanAngle.y = atan2f(mMatrix.mArray[0][2], mMatrix.mArray[2][3]);
		euclideanAngle.z = 0;
	}
	else
	{
		euclideanAngle.x = asinf(mMatrix.mArray[1][0]);
		euclideanAngle.y = atan2f(-mMatrix.mArray[2][0], mMatrix.mArray[0][0]);
		euclideanAngle.z = atan2f(-mMatrix.mArray[1][2], mMatrix.mArray[1][1]);
	}

	return euclideanAngle;
}

engine::matrix_4::array_2D engine::matrix_4::get_matrix()
{
	return mMatrix;
}

engine::matrix_4 engine::matrix_4::get_transpose()
{
	engine::matrix_4 transposedMatrix;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			transposedMatrix.mMatrix.mArray[j][i] = mMatrix.mArray[i][j];
		}
	}

	return transposedMatrix;
}

float& engine::matrix_4::operator[](const int pIndex)
{
	int rowIndex = pIndex % 4;
	int columnIndex = pIndex / 4;
	return mMatrix.mArray[rowIndex][columnIndex];
}

std::ostream & engine::operator<<(std::ostream &pOs, const matrix_4 &matrix)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			pOs << matrix.mMatrix.mArray[i][j]<< " ";
		}
		pOs << "\n";
	}

	return pOs;
}

engine::matrix_4 & engine::matrix_4::operator=(const matrix_4 &pToEqual)
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

engine::matrix_4 engine::matrix_4::operator+(const matrix_4 &pToAdd) const
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

engine::matrix_4 engine::matrix_4::operator-(const matrix_4 &pToSubstract) const
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

engine::matrix_4 engine::matrix_4::operator*(const matrix_4 &pToMultiply) const
{
	matrix_4 newMatrix;
	int rowCounter = 0;

	while (rowCounter<4)
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				newMatrix.mMatrix.mArray[rowCounter][i] = 0;
				newMatrix.mMatrix.mArray[rowCounter][i] += mMatrix.mArray[rowCounter][j] * pToMultiply.mMatrix.mArray[j][i];
			}
		}

		rowCounter++;
	}

	return newMatrix;
}
