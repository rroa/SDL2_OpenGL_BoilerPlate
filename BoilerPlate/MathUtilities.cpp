#include "MathUtilities.hpp"


MathUtilities::MathUtilities()
{
}


MathUtilities::~MathUtilities()
{
}

const double MathUtilities::PI = 3.14159265;

int MathUtilities::FloatToInt(float number)
{
	return number+0.5;
}

int MathUtilities::FloatToEvenInt(float number)
{
	int returningInt = number + 0.5;
	if (returningInt % 2 == 0)
	{
		return returningInt;
	}
	else
	{
		return returningInt + 1;
	}
}

double MathUtilities::ToRadians(double angle)
{
	return ((angle*3.14)/180);
}

double MathUtilities::ToDegrees(double angle)
{
	return ((angle*180)/3.14);
}

bool MathUtilities::IsPowerOfTwo(int number)
{
	double value = log2(number);
	if (fmod(value, 1) == 0.0) //function that checks if the number is an integer
	{
		return true;
	}
	else
		return false;
}

double MathUtilities::AngularDistanceR(double angle1, double angle2)
{
	double result = angle1 - angle2;
	if (result < 0)
		result += (2*3.14);
	return result;
}

double MathUtilities::AngularDistanceD(double angle1, double angle2)
{
	double result = angle1 - angle2;
	if (result < 0)
		result += 360;
	return result;
}

double MathUtilities::DistanceBetweenTwoPoints(double x1, double y1, double x2, double y2)
{
	return sqrt((x2-x1)*(x2-x1) + (y2 - y1)*(y2 - y1));
}
