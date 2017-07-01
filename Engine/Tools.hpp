#pragma once

#include "..\TextureGenerator\ColorRGBA.hpp"

#include <type_traits>
#include <time.h>

#define M_PI 3.14159265358979323846 // not used : math.h

namespace Tricible
{
	template<typename T>
	T	max(const T a, const T b)
	{
		return (a > b ? a : b);
	}

	template<typename T>
	T	min(const T a, const T b)
	{
		return (a < b ? a : b);
	}

	template<typename T, typename = typename std::enable_if<std::is_arithmetic<T>::value, T>::type>
	T Clamp(T value, T min, T max)
	{
		if (value < min)
			return min;
		else if (value > max)
			return max;
		return value;
	}
	template<typename T, typename = typename std::enable_if<std::is_arithmetic<T>::value, T>::type>
	T Clamp01(T value)
	{
		return Clamp(value, (T)0, (T)1);
	}

	template<typename T, typename = typename std::enable_if<std::is_arithmetic<T>::value, T>::type>
	T Saturate(T value, T min, T max)
	{
		return Clamp01(value, min, max);
	}

	// ----------------------------------------------------------------
	// Section : Interpolation
	// Description : Interpolation is a method of constructing new data points within the range of a discrete set of known data points.
	// ----------------------------------------------------------------

	// Linear interpolation unclamped
	// Precise method, which guarantees v = v1 when t = 1.
	// WARNING : v0 + t * (v1 - v0) --> Imprecise method, which does not guarantee v = v1 when t = 1, due to floating-point arithmetic error
	template<typename T>
	const T UnclampedLerp(const T& a, const T& b, float value)
	{
		return a * (1.0f - value) + (b * value);
	}

	// Linear interpolation clamped
	// Precise method, which guarantees v = v1 when t = 1.
	// WARNING : v0 + t * (v1 - v0) --> Imprecise method, which does not guarantee v = v1 when t = 1, due to floating-point arithmetic error
	template<typename T>
	const T Lerp(const T& a, const T& b, float value)
	{
		const float clampedVal = Clamp01(value);
		return a * (1.0f - value) + (b * value);
	}

	template<typename T>
	const T Lerp2D(const T& a, const T& b, const T& c, const T& d, float x, float y)
	{
		const T x1 = Lerp(a, b, x);
		const T x2 = Lerp(c, d, x);
		return Lerp(x1, x2, y);
	}

	template<typename T>
	const T Cosinerp(const T& a, const T& b, float t)
	{
		float k = (1.0f - cos(t * M_PI)) * 0.5f;
		return UnclampedLerp(a, b, k);
	}

	template<typename T>
	const T Cosinerp2D(const T& a, const T& b, const T& c, const T& d, float x, float y)
	{
		const T x1 = Cosinerp(a, b, x);
		const T x2 = Cosinerp(c, d, x);
		return Cosinerp(x1, x2, y);
	}

	// TODO : Never used, be careful... bad result is possible
	template<typename T>
	const T Cubicerp(const T& p1, const T& p2, const T& p3, const T& p4, float t)
	{
		a = p4 - p3 - p1 + p2;
		b = p1 - p2 - a;
		c = p3 - p1;

		return (a * x * x * x) + (b * x * x) + (c * x) + p2; // d = p2;
	}

	// Performs linear interpolation between two 8-bit channel values
	uint8_t Channerp(const uint8_t channel0, const uint8_t channel1, const float alpha)
	{
		// Before optimization :
		//float colorLeft = (float)channel0 / 255.0;
		//float coloRight = (float)channel1 / 255.0;
		//float result = ((1.0f - alpha) * colorLeft) + (coloRight * alpha);
		//return (uint8_t)(result * 255.0f);

		// After optimization ???
		return (uint8_t)((((float)channel1 / 255.0 * alpha) + ((float)channel0 / 255.0 * (1.0f - alpha))) * 255.0f);
	}

	// Performs linear interpolation between two colors and stores the result in out
	inline void Colerp(const ColorRGBA & color0, const ColorRGBA & color1, float alpha, ColorRGBA * out)
	{
		out->SetRed(Channerp(color0.GetRed(), color1.GetRed(), alpha));
		out->SetGreen(Channerp(color0.GetGreen(), color1.GetGreen(), alpha));
		out->SetBlue(Channerp(color0.GetBlue(), color1.GetBlue(), alpha));
		out->SetAlpha(Channerp(color0.GetAlpha(), color1.GetAlpha(), alpha));
	}

	// ----------------------------------------------------------------
	// Section : Generate random number
	// Returns a pseudo-random integral/real number in the range between border left (MIN) and border right (MAX).
	// ----------------------------------------------------------------

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
		// TODO : get another random ?
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
		int tmp = Random<T, borderLeft, borderRight>(x) * 1073741823; // == 2147483647 / 2
		return Random<T, borderLeft, borderRight>(tmp + y);
	}

	// Description : Generate random number from 2 parameters
	// Return Value : An integer/real value between border left (MIN) and border right (MAX).
	// Example : Random<float, 0, 1>(123, 456, 789) -> return float with [ 0.0 ; 1.0 ] 
	template<typename T, int borderLeft, int borderRight>
	T Random(int x, int y, int z)
	{
		int tmp = Random<T, borderLeft, borderRight>(x) * 1073741823; // == 2147483647 / 2
		tmp = Random<T, borderLeft, borderRight>(tmp + y) * 1073741823; // == 2147483647 / 2
		return Random<T, borderLeft, borderRight>(tmp + z);
	}
}