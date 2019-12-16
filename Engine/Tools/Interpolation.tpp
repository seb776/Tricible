#pragma once

#include <cmath>

namespace Tricible
{
#ifndef M_PI
#define M_PI 3.14159265358979323846f
#endif

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

	// Cubic interpolation
	// WARNING : Never used... be carefull !
	template<typename T>
	const T Cuberp(const T& p0, const T& p1, const T& p2, const T& p3, float t)
	{
		// Code before optimization/obfuscation :
		// float a0, a1, a2, a3, t2;
		// a0 = p3 - p2 - p0 + p1;
		// a1 = p0 - p1 - a0;
		// a2 = p2 - p0;
		// a3 = p1;
		// t2 = t * t;
		// return (a0 * t2 * t) + (a1 * t2) + (a2 * t) + a3;

		float t2 = t * t;

		return ((p3 - p2 - p0 + p1) * t2 * t) + ((p0 - p1 - a) * t2) + ((p2 - p0) * t) + p1;
	}
	}