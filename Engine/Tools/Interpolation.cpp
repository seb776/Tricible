// Standard library header
#include <type_traits>
#include <cmath>

// Tricible
#include "Interpolation.hpp"

// ----------------------------------------------------------------
// Tools : Interpolation
// Description : Interpolation is a method of constructing new data points within the range of a discrete set of known data points.
// ----------------------------------------------------------------

namespace Tricible
{
	#define M_PI 3.14159265358979323846

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

	// Linear interpolation between two 8-bit channel values
	uint8_t Channerp(const uint8_t channel0, const uint8_t channel1, const float alpha)
	{
		// Code before optimization/obfuscation :
		// float colorLeft = (float)channel0 / 255.0f;
		// float coloRight = (float)channel1 / 255.0f;
		// float result = ((1.0f - alpha) * colorLeft) + (coloRight * alpha);
		// return (uint8_t)(result * 255.0f);

		return (uint8_t)((((float)channel1 / 255.0f * alpha) + ((float)channel0 / 255.0f * (1.0f - alpha))) * 255.0f);
	}

	// Performs linear interpolation between two colors and stores the result in out
	void Colerp(const Color::RGB & color0, const Color::RGB & color1, float alpha, Color::RGB * colorOut)
	{
		colorOut->Red(Channerp(color0.Red(), color1.Red(), alpha));
		colorOut->Green(Channerp(color0.Green(), color1.Green(), alpha));
		colorOut->Blue(Channerp(color0.Blue(), color1.Blue(), alpha));
	}

	// Performs linear interpolation between two colors and stores the result in out
	void Colerp(const Color::RGBA & color0, const Color::RGBA & color1, float alpha, Color::RGBA * colorOut)
	{
		colorOut->Red(Channerp(color0.Red(), color1.Red(), alpha));
		colorOut->Green(Channerp(color0.Green(), color1.Green(), alpha));
		colorOut->Blue(Channerp(color0.Blue(), color1.Blue(), alpha));
		colorOut->Alpha(Channerp(color0.Alpha(), color1.Alpha(), alpha));
	}
}

// END
