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
