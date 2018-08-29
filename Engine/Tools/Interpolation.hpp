#pragma once

#include <cstdint>

#include "../Color/RGB.hpp"
#include "../Color/RGBA.hpp"

namespace Tricible
{
	template<typename T> const T UnclampedLerp(const T& a, const T& b, float value);
	template<typename T> const T Lerp(const T& a, const T& b, float value);
	template<typename T> const T Lerp2D(const T& a, const T& b, const T& c, const T& d, float x, float y);
	template<typename T> const T Cosinerp(const T& a, const T& b, float t);
	template<typename T> const T Cosinerp2D(const T& a, const T& b, const T& c, const T& d, float x, float y);
	template<typename T> const T Cuberp(const T& p0, const T& p1, const T& p2, const T& p3, float t);
	uint8_t Channerp(const uint8_t channel0, const uint8_t channel1, const float alpha);
	void Colerp(const Color::RGB & color0, const Color::RGB & color1, float alpha, Color::RGB * colorOut);
	void Colerp(const Color::RGBA & color0, const Color::RGBA & color1, float alpha, Color::RGBA * colorOut);
}

// END
