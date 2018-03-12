#include "matrix_4.hpp"


engine::matrix_4::matrix_4()
{
	set_identity();
}

engine::matrix_4::matrix_4(float value1, float value2, float value3, float value4, float value5, float value6, float value7, float value8, float value9, float value10, float value11, float value12, float value13, float value14, float value15, float value16)
{
	mMatrix[0][0] = value1;
	mMatrix[1][0] = value2;
	mMatrix[2][0] = value3;
	mMatrix[3][0] = value4;

	mMatrix[0][1] = value5;
	mMatrix[1][1] = value6;
	mMatrix[2][1] = value7;
	mMatrix[3][1] = value8; 

	mMatrix[0][2] = value9;
	mMatrix[1][2] = value10;
	mMatrix[2][2] = value11;
	mMatrix[3][2] = value12;

	mMatrix[0][3] = value13;
	mMatrix[1][3] = value14;
	mMatrix[2][3] = value15;
	mMatrix[3][3] = value16;
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
				mMatrix[j][i] = 1;
			}
			else
			{
				mMatrix[j][i] = 0;
			}
		}
	}
}

Vector3 engine::matrix_4::get_angle()
{
	Vector3 euclideanAngle;

	if (mMatrix[0][0] == 1.0f || mMatrix[0][0] == -1.0f)
	{
	}
}

float *engine::matrix_4::get_matrix()
{
	return *mMatrix;
}

engine::matrix_4 engine::matrix_4::get_transpose()
{
	engine::matrix_4 transposedMatrix;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			transposedMatrix.mMatrix[j][i] = mMatrix[i][j];
		}
	}

	return transposedMatrix;
}

float& engine::matrix_4::operator[](const int pIndex)
{
	int rowIndex = pIndex % 4;
	int columnIndex = pIndex / 4;
	return mMatrix[rowIndex][columnIndex];
}

engine::matrix_4 & engine::matrix_4::operator=(const matrix_4 &pToEqual)
{
	matrix_4 newMatrix;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			newMatrix.mMatrix[j][i] = pToEqual.mMatrix[j][i];
		}
	}

	return newMatrix;
}

engine::matrix_4 engine::matrix_4::operator+(const matrix_4 &pToAdd) const
{
	matrix_4 newMatrix;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			newMatrix.mMatrix[j][i] = mMatrix[j][i] + pToAdd.mMatrix[j][i];
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
			newMatrix.mMatrix[j][i] = mMatrix[j][i] - pToSubstract.mMatrix[j][i];
		}
	}

	return newMatrix;
}
