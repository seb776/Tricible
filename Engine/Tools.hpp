#pragma once

#include <type_traits>
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

	template<typename T>
	const T UnclampedLerp(const T& a, const T& b, float value)
	{
		return a * (1.0f - value) + (b * value);
	}

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
}