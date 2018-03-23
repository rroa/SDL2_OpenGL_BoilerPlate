#pragma once

#ifndef MATH_UTILITIES_HPP
#define MATH_UTILITIES_HPP

#include <algorithm>
#include <math.h>
#include <vector>

namespace Engine 
{
	class Math_Utilities
	{
	public:
		const static double PI;

		Math_Utilities();

		int float_to_int(float); //rounds to the nearest integer
		int float_to_even_int(float); //rounds to the nearest even number
		double to_radians(double); //converts from degrees to radians	
		double to_degrees(double); //converts fron radians to degrees
		bool is_power_of_two(int); //checks if a number is a power of two
		double angular_distance_r(double, double); //calculates the angular distance in radians
		double angular_distance_d(double, double); //calculates the angular distance in degrees
		double distance_between_two_points(double, double, double, double);


		//clamps a number to the range specified
		template <typename type>
		type clamp(type pNumber, type pMinimum, type pMaximum)
		{
			if (pNumber < pMinimum)
				pNumber = pMinimum;
			else if (pNumber > pMaximum)
				pNumber = pMaximum;

			return pNumber;
		}

		//returns maximum number of two given
		template <typename type>
		type get_max_number(type pNumber1, type pNumber2)
		{
			if (pNumber1 > pNumber2)
				return pNumber1;
			else
				return pNumber2;
		}

		//returns maximum number of three given
		template <typename type>
		type get_max_number(type pNumber1, type pNumber2, type pNumber3)
		{
			type values[] = { pNumber1, pNumber2, pNumber3 };
			sort(values, values + 3);

			return values[2];
		}

		//returns maximum number of four given
		template <typename type>
		type get_max_number(type pNumber1, type pNumber2, type pNumber3, type pNumber4)
		{
			type values[] = { pNumber1, pNumber2, pNumber3, pNumber4 };
			sort(values, values + 4);
			return values[3];
		}

		//returns minimum number of two given
		template <typename type>
		type get_min_number(type pNumber1, type pNumber2)
		{
			if (pNumber1 < pNumber2)
				return pNumber1;
			else
				return pNumber2;
		}

		//returns minimum number of three given
		template <typename type>
		type get_min_number(type pNumber1, type pNumber2, type pNumber3)
		{
			type values[] = { pNumber1, pNumber2, pNumber3 };
			sort(values, values + 3);

			return values[0];
		}

		//returns minimum number of four given
		template <typename type>
		type get_min_number(type pNumber1, type pNumber2, type pNumber3, type pNumber4)
		{
			type values[] = { pNumber1, pNumber2, pNumber3, pNumber4 };
			sort(values, values + 4);
			return values[0];
		}

		//interpolates a number between a start and an end value;
		template <typename type>
		type interpolate(type pNumber, type pBegin, type pEnd)
		{
			return (pNumber*(pEnd - pBegin)) - pBegin;
		}
	};
}
#endif // _MATH_UTILITES_H_