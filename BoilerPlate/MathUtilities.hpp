#pragma once
#include <vector>
#include <algorithm>
#include <math.h>

//Class that contains different math functions
class MathUtilities
{
public:

	const static double PI;

	MathUtilities();
	~MathUtilities();
	int FloatToInt(float); //rounds to the nearest integer
	int FloatToEvenInt(float); //rounds to the nearest even number
	double ToRadians(double); //converts from degrees to radians	
	double ToDegrees(double); //converts fron radians to degrees
	bool IsPowerOfTwo(int); //checks if a number is a power of two
	double AngularDistanceR(double, double); //calculates the angular distance in radians
	double AngularDistanceD(double, double); //calculates the angular distance in degrees
	double DistanceBetweenTwoPoints(double, double, double, double); 


	//clamps a number to the range specified
	template <typename type>
	type clamp(type number, type minimum, type maximum)
	{
		if (number < minimum)
			number= minimum;
		else if(number > maximum)
			number= maximum;

		return number;
	}

	//returns maximum number of two given
	template <typename type> 
	type getMaxNumber(type number1, type number2)
	{
		if (number1 > number2)
			return number1;
		else
			return number2;
	}

	//returns maximum number of three given
	template <typename type>
	type getMaxNumber(type number1, type number2, type number3)
	{
		type values[] = { number1, number2, number3 };
		sort(values, values+3);
		
		return values[2];
	}

	//returns maximum number of four given
	template <typename type>
	type getMaxNumber(type number1, type number2, type number3, type number4)
	{
		type values[] = { number1, number2, number3, number4 };
		sort(values, values + 4);
		return values[3];
	}

	//returns minimum number of two given
	template <typename type>
	type getMinNumber(type number1, type number2)
	{
		if (number1 < number2)
			return number1;
		else
			return number2;
	}

	//returns minimum number of three given
	template <typename type>
	type getMinNumber(type number1, type number2, type number3)
	{
		type values[] = { number1, number2, number3 };
		sort(values, values + 3);

		return values[0];
	}

	//returns minimum number of four given
	template <typename type>
	type getMinNumber(type number1, type number2, type number3, type number4)
	{
		type values[] = { number1, number2, number3, number4 };
		sort(values, values + 4);
		return values[0];
	}

	//interpolates a number between a start and an end value;
	template <typename type>
	type interpolate(type number, type begin, type end)
	{
		return (number*(end - begin)) - begin;
	}
};

