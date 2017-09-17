#pragma once

#include "../Engine/Tools.hpp"
#include <math.h>

namespace PerlinNoise2D
{
	template<typename T>
	const T& Cosinerp(const T& a, const T& b, float t)
	{
		const T c = (1.0f - cos(t * M_PI)) * 0.5f;
		return c * b + a * (1.0f - c);
	}

	template<typename T>
	const T& Cubicerp(const T& p1, const T& p2, const T& p3, const T& p4, float t)
	{
		//Calcul des coefficients de notre polynôme
		const T a3 = -0.5f * p1 + 1.5f * p2 - 1.5f * p3 + 0.5f * p4;
		const T a2 = p1 - 2.5f * p2 + 2.0f * p3 - 0.5f  *p4;
		const T a1 = -0.5f * p1 + 0.5f * p3;

		//Calcul de la valeur de ce polynôme en t
		return (a3 * t * t * t) + (a2 * t * t) + (a1 * t) + p2; // a0 == p2;
	}

	//Fournit une valeur aléatoire entre -1 et 1
	template<int bornLeft, int bornRight>
	float GetRandomNoise1D(int x)
	{
		constexpr float Threshold = 2147483647 / (bornRight - bornLeft); // 2147483647 == 2 ^ 31 

		x = (x << 13) ^ x;
		x = x * (x * x * 15731 + 789221) + 1376312589;

		if (bornLeft == 0)
			return (x & 0x7fffffff) / Threshold;
		else
			return (x & 0x7fffffff) / Threshold + bornLeft;
	}

	//On pourra obtenir une valeur entre 0 et 1 en utilisant
	//la formule : (rand_noise(t) + 1.) / 2.

	float GetRandomNoise2D(int x, int y)
	{
		//Bruit du point précédent :
		int tmp = GetRandomNoise1D<0, 1>(x) * 850000;
		//Bruit du point suivant :
		return GetRandomNoise1D<0, 1>(tmp + y);
	}

	float smooth_noise_1D_with_linear(float x)
	{
		//Extraire la partie entière : Ent(x)
		int integer_x = (int)x;

		//Bruit du point précédent :
		float a = GetRandomNoise1D<0, 1>(integer_x);
		//Bruit du point suivant :
		float b = GetRandomNoise1D<0, 1>(integer_x + 1);

		//Interpolation :
		return Tricible::UnclampedLerp(a, b, x - integer_x); //Partie fractionnaire : x - Ent(x)
	}

	//public:
	// TODO add param : type of prcedurale texture ?
	void Generate(char *img, int width, int height)
	{
		int color;

		for (int x = 0; x < width; ++x)
		{
			color = smooth_noise_1D_with_linear(x) * 255;
		}
	}
};