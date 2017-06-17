#pragma once

#include <type_traits>

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
	T Saturate(T value)
	{
		return Clamp01(value);
	}

	template<typename T>
	const T& Lerp(const T& a, const T& b, float value)
	{
		const float clampedVal = Clamp01(value);
		return (a * value) + (b * (1.0f - value));
	}
	template<typename T>
	const T& UnclampedLerp(const T& a, const T& b, float value)
	{
		return (a * value) + (b * (1.0f - value));
	}
}