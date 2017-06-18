#pragma once

#include "../Engine/Tools.hpp"
#include <time.h>

namespace PerlinNoise2D
{
	#define D_PERSISTANCE 0.5f
	#define D_PAS 64

	template<int bornLeft, int bornRight>
	float GetRandomNoise1D(int x)
	{
		// TODO : get another random ?
		constexpr float Threshold = 2147483647 / (bornRight - bornLeft); // TODO auto -> 2147483647 == 2 ^ 31 ???

		x = (x << 13) ^ x;
		x = x * (x * x * 15731 + 789221) + 1376312589;

		if (bornLeft == 0)
			return (x & 0x7fffffff) / Threshold;
		else
			return (x & 0x7fffffff) / Threshold + bornLeft;
	}

	float GetRandomNoise2D(int x, int y)
	{
		//Bruit du point précédent :
		int tmp = GetRandomNoise1D<0, 1>(x) * 850000;
		//Bruit du point suivant :
		return GetRandomNoise1D<0, 1>(tmp + y);
	}

	float GenerateSmoothNoise1D(const float x)
	{
		const int integer_x = (int)x;

		const float a = GetRandomNoise1D<0, 1>(integer_x);
		const float b = GetRandomNoise1D<0, 1>(integer_x + 1);

		// TODO : add mode for smooth choice
		// Tricible::Lerp
		// Tricible::Cosinerp
		// Tricible::Cubicerp ?
		return Tricible::Cosinerp(a, b, x - integer_x);
	}

	float GenerateSmoothNoise1DStacked(const float x, const int octaves, const float OverlapPercent, const float frequency)
	{
		float sum = 0.0f;
		float amplitude = 1.0; // l'amplitude du bruit est l'écart entre la plus grande et la plus petite valeur du bruit.
		float tmpFrequency = 1.0;

		for (int i = 0; i < octaves; i++)
		{
			sum += amplitude * PerlinNoise2D::GenerateSmoothNoise1D(x * tmpFrequency);
			amplitude *= OverlapPercent;
			tmpFrequency *= frequency; // à chaque octave, on va multiplier le nombre de point qui compose la courbe incarnant le "bruit" 
		}
		return sum * ((1 - OverlapPercent) / (1 - amplitude));
	}

	float GenerateSmoothNoise2D(float x, float y)
	{
		const int integer_x = (int)x;
		const int integer_y = (int)y;

		const float a = GetRandomNoise2D(integer_x, integer_y);
		const float b = GetRandomNoise2D(integer_x + 1, integer_y);
		const float c = GetRandomNoise2D(integer_x, integer_y + 1);
		const float d = GetRandomNoise2D(integer_x + 1, integer_y + 1);

		return Tricible::Cosinerp2D(a, b, c, d, x - integer_x, y - integer_y);
	}

	// TODO : Check NbrPoint is >= 2
	// BufferNoise -> Elem between : [0 ; 1]
	void PerlinNoise1D(float BufferNoise [], const int SizeBuffer, const int NbrPoint)
	{
		const float scale = 1.0f / SizeBuffer * (NbrPoint - 1); // TODO constexpr ?
		for (int x = 0; x < SizeBuffer; x++)
		{
			BufferNoise[x] = PerlinNoise2D::GenerateSmoothNoise1D(x * scale);
		}
	}


	// TODO : Check NbrPoint is >= 2
	// BufferNoise -> Elem between : [0 ; 1]
	// NbrPerlinNoiseStacked : [ 1 ; 1024 ]. nombre de perlin que l'on va superposer (reviens à dire le nombre de fois qu'on appelle la fonction "bruit 1D".
	// OverlapPercent -> Pourcentage de superposition de chaque bruit de perlin que l'on rajoute. Si 1.0f, alors 100% de superposition, si 0.1f, alors 10% de superposition
	void PerlinNoise1DStacked(float * BufferNoise, const int SizeBuffer, const int NbrPoint, const int NbrPerlinNoiseStacked, const float OverlapPercent, const float frequency)
	{
		const float scale = 1.0f / SizeBuffer * (NbrPoint - 1); // TODO constexpr ?
		
		for (int x = 0; x < SizeBuffer; x++)
		{
			BufferNoise[x] = PerlinNoise2D::GenerateSmoothNoise1DStacked(x * scale, NbrPerlinNoiseStacked, OverlapPercent, frequency);
		}
	}

	void PerlinNoise2D(float * BufferNoise, const int SizeBufferX, const int SizeBufferY, const int NbrPoint)
	{
		const float scaleX = 1.0f / SizeBufferX * (NbrPoint - 1);
		const float scaleY = 1.0f / SizeBufferY * (NbrPoint - 1);

		for (int y = 0; y < SizeBufferY; y++)
		{
			for (int x = 0; x < SizeBufferX; x++)
			{
				BufferNoise[y * SizeBufferX + x] = PerlinNoise2D::GenerateSmoothNoise2D(x * scaleX, y * scaleY);
			}
		}
	}
};