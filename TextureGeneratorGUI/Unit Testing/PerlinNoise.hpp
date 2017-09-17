
#pragma once

#include "string"

namespace UT
{
	void PerlinNoise_1D();
	void PerlinNoise_1D_Stacked();
	void PerlinNoise_2D();
	void PerlinNoise_2D_Stacked();
	void PerlinNoise_2D_Stacked_With_Color();

	void draw_img_from_sfml(const std::string & img);
	void run_one_test(const std::string & TestTitle, void (*ptrFunction)(void));

	int run_unit_testing_perlin_noise();
}

