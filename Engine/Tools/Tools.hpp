#pragma once

#include <type_traits>
#include <time.h>
#include <string>
#include <functional>
#include <thread>
#include <vector>
#include <algorithm>

namespace Tricible
{
	template<typename T> // TODO only for numerics
	T Sign(T sign)
	{
		// TODO easily optimizable
		return (T)(sign < 0.0f ? -1.0f : 1.0f);
	}

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
	template<typename T>
	T abs(T a)
	{
		return (a < 0.0f ? -a : a);
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

	std::string GetCurrentDirectory();
	std::string GetCurrentExecutableDirectory();
	std::string PathCombine(const std::string& a, const std::string& b);
	std::string ReadFile(const std::string& fileName);

	// TODO Fix this implem
	void parallel_fora(size_t start, size_t end, std::function<void(size_t)> func, size_t num_threads = std::thread::hardware_concurrency());
}