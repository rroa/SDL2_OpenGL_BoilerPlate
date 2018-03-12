#include "Math_Utilities.hpp"

namespace Engine
{
	const double Math_Utilities::PI = 3.14159265;

	Math_Utilities::Math_Utilities()
	{
	}

	int Math_Utilities::float_to_int(float pNumber)
	{
		return pNumber + 0.5;
	}

	int Math_Utilities::float_to_even_int(float pNumber)
	{
		int returningInt = pNumber + 0.5;
		if (returningInt % 2 == 0)
		{
			return returningInt;
		}
		else
		{
			return returningInt + 1;
		}
	}

	double Math_Utilities::to_radians(double pAngle)
	{
		return ((pAngle*3.14) / 180);
	}

	double Math_Utilities::to_degrees(double pAngle)
	{
		return ((pAngle * 180) / 3.14);
	}

	bool Math_Utilities::is_power_of_two(int pNumber)
	{
		double value = log2(pNumber);
		if (fmod(value, 1) == 0.0) //function that checks if the number is an integer
		{
			return true;
		}
		else
			return false;
	}

	double Math_Utilities::angular_distance_r(double pAngle1, double pAngle2)
	{
		double result = pAngle1 - pAngle2;
		if (result < 0)
			result += (2 * 3.14);
		return result;
	}

	double Math_Utilities::angular_distance_d(double pAngle1, double pAngle2)
	{
		double result = pAngle1 - pAngle2;
		if (result < 0)
			result += 360;
		return result;
	}

	double Math_Utilities::distance_between_two_points(double pX1, double pY1, double pX2, double pY2)
	{
		return sqrt((pX2 - pX1)*(pX2 - pX1) + (pY2 - pY1)*(pY2 - pY1));
	}
}

