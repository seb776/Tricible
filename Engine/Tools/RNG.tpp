#pragma once

#include <time.h>

// ----------------------------------------------------------------
// Tools : Generate random number
// Returns a pseudo-random integral/real number in the range between border left (MIN) and border right (MAX).
// ----------------------------------------------------------------

// TODO Doc :
// 2147483647 == 2^31 == 0x7fffffff == 1111111111111111111111111111111
// 1073741824 == 2^30 == 0x40000000 == 1000000000000000000000000000000
// 15731 and 789221 -> is prime

namespace Tricible
{
	// TODO : Optimisation borderLeft --> Use (greater-than) inside a template parameter

	// Description : Generate random number (no parameter)
	// Return Value : An integer/real value between border left (MIN) and border right (MAX).
	// Example : Random<float, 0, 1>() -> return float with [ 0.0 ; 1.0 ]
	template<typename T, int borderLeft, int borderRight>
	T Random()
	{
		// TODO : limit auto -> 2147483647 == 2 ^ 31 ???
		constexpr float Threshold = 2147483647 / (borderRight - borderLeft);
		int x = time(NULL);

		// some bitwise operations
		x = (x << 13) ^ x;
		x = x * (x * x * 15731 + 789221) + 1376312589;

		if (borderLeft == 0)
			return (x & 0x7fffffff) / Threshold;
		else
			return (x & 0x7fffffff) / Threshold + borderLeft;
	}

	// Description : Generate random number from 1 parameters
	// Return Value : An integer/real value between border left (MIN) and border right (MAX).
	// Example : Random<float, 0, 1>(123) -> return float with [ 0.0 ; 1.0 ]
	template<typename T, int borderLeft, int borderRight>
	T Random(int x)
	{
		// TODO : limit auto -> 2147483647 == 2 ^ 31 ???
		constexpr float Threshold = 2147483647 / (borderRight - borderLeft);

		// some bitwise operations
		x = (x << 13) ^ x;
		x = x * (x * x * 15731 + 789221) + 1376312589;

		if (borderLeft == 0)
			return (x & 0x7fffffff) / Threshold;
		else
			return (x & 0x7fffffff) / Threshold + borderLeft;
	}

	// Description : Generate random number from 2 parameters
	// Return Value : An integer/real value between border left (MIN) and border right (MAX).
	// Example : Random<float, 0, 1>(123, 456) -> return float with [ 0.0 ; 1.0 ] 
	template<typename T, int borderLeft, int borderRight>
	T Random(int x, int y)
	{
		int tmp = Random<T, borderLeft, borderRight>(x) * 1073741823;

		return Random<T, borderLeft, borderRight>(tmp + y);
	}

	// Description : Generate random number from 2 parameters
	// Return Value : An integer/real value between border left (MIN) and border right (MAX).
	// Example : Random<float, 0, 1>(123, 456, 789) -> return float with [ 0.0 ; 1.0 ] 
	template<typename T, int borderLeft, int borderRight>
	T Random(int x, int y, int z)
	{
		int tmp = Random<T, borderLeft, borderRight>(x) * 1073741823;

		tmp = Random<T, borderLeft, borderRight>(tmp + y) * 1073741823;
		return Random<T, borderLeft, borderRight>(tmp + z);
	}
}

// END
