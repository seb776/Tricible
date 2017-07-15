#pragma once

#include "../Engine/Random/RNG.hpp"
#include "../Engine/Interpolation/Interpolation.hpp"

#define	FREQUENCY	2.0f // Description : à chaque octave, on va multiplier le nombre de point qui compose la courbe incarnant le "bruit" 

namespace PerlinNoise
{
	float SmoothNoise1D(const float x)
	{
		const int integer_x = (int)x;

		const float a = Tricible::Random<float, 0, 1>(integer_x);
		const float b = Tricible::Random<float, 0, 1>(integer_x + 1);

		// TODO : add mode for smooth choice
		// Tricible::Lerp
		// Tricible::Cosinerp
		// Tricible::Cubicerp ?
		return Tricible::Cosinerp(a, b, x - integer_x);
	}

	float SmoothNoise1DStacked(const float x, const int octaves, const float OverlapPercent)
	{
		float sum = 0.0f;
		float amplitude = 1.0; // l'amplitude du bruit est l'écart entre la plus grande et la plus petite valeur du bruit.
		float tmpFrequency = 1.0;

		for (int i = 0; i < octaves; i++)
		{
			sum += amplitude * SmoothNoise1D(x * tmpFrequency);
			amplitude *= OverlapPercent;
			tmpFrequency *= FREQUENCY; // à chaque octave, on va multiplier le nombre de point qui compose la courbe incarnant le "bruit" 
		}
		return sum * ((1 - OverlapPercent) / (1 - amplitude));
	}

	float SmoothNoise2D(float x, float y)
	{
		const int integer_x = (int)x;
		const int integer_y = (int)y;

		const float a = Tricible::Random<float, 0, 1>(integer_x, integer_y);
		const float b = Tricible::Random<float, 0, 1>(integer_x + 1, integer_y);
		const float c = Tricible::Random<float, 0, 1>(integer_x, integer_y + 1);
		const float d = Tricible::Random<float, 0, 1>(integer_x + 1, integer_y + 1);

		// TODO : add mode for smooth choice
		// Tricible::Lerp
		// Tricible::Cosinerp
		// Tricible::Cubicerp ?
		return Tricible::Cosinerp2D(a, b, c, d, x - integer_x, y - integer_y);
	}

	float SmoothNoise2DStacked(float x, float y, const int octaves, const float OverlapPercent)
	{
		float sum = 0.0f;
		float amplitude = 1.0; // l'amplitude du bruit est l'écart entre la plus grande et la plus petite valeur du bruit.
		float tmpFrequency = 1.0;

		for (int i = 0; i < octaves; i++)
		{
			sum += amplitude * SmoothNoise2D(x * tmpFrequency, y * tmpFrequency);
			amplitude *= OverlapPercent;
			tmpFrequency *= FREQUENCY; // à chaque octave, on va multiplier le nombre de point qui compose la courbe incarnant le "bruit" 
		}
		return sum * ((1 - OverlapPercent) / (1 - amplitude));
	}

	// TODO : Check NbrPoint is >= 2
	// BufferNoise -> Elem between : [0 ; 1]
	void PerlinNoise1D(float BufferNoise [], const int SizeBuffer, const int NbrPoint)
	{
		const float scale = 1.0f / SizeBuffer * (NbrPoint - 1); // TODO constexpr ?
		for (int x = 0; x < SizeBuffer; x++)
		{
			BufferNoise[x] = SmoothNoise1D(x * scale);
		}
	}

	// TODO : Check NbrPoint is >= 2
	// BufferNoise -> Elem between : [0 ; 1]
	// NbrPerlinNoiseStacked : [ 1 ; 1024 ]. nombre de perlin que l'on va superposer (reviens à dire le nombre de fois qu'on appelle la fonction "bruit 1D".
	// OverlapPercent -> Pourcentage de superposition de chaque bruit de perlin que l'on rajoute. Si 1.0f, alors 100% de superposition, si 0.1f, alors 10% de superposition
	void PerlinNoise1DStacked(float * BufferNoise, const int SizeBuffer, const int NbrPoint, const int NbrPerlinNoiseStacked, const float OverlapPercent)
	{
		const float scale = 1.0f / SizeBuffer * (NbrPoint - 1); // TODO constexpr ?
		
		for (int x = 0; x < SizeBuffer; x++)
		{
			BufferNoise[x] = SmoothNoise1DStacked(x * scale, NbrPerlinNoiseStacked, OverlapPercent);
		}
	}

	void PerlinNoise2D(float * BufferNoise, const int SizeBufferX, const int SizeBufferY, const int NbrPointX, const int NbrPointY)
	{
		const float scaleX = 1.0f / SizeBufferX * (NbrPointX - 1);
		const float scaleY = 1.0f / SizeBufferY * (NbrPointY - 1);

		for (int y = 0; y < SizeBufferY; y++)
		{
			for (int x = 0; x < SizeBufferX; x++)
			{
				BufferNoise[y * SizeBufferX + x] = SmoothNoise2D(x * scaleX, y * scaleY);
			}
		}
	}

	void PerlinNoise2DStacked(float * BufferNoise, const int SizeBufferX, const int SizeBufferY, const int NbrPointX, const int NbrPointY, const int NbrPerlinNoiseStacked, const float OverlapPercent)
	{
		const float scaleX = 1.0f / SizeBufferX * (NbrPointX - 1);
		const float scaleY = 1.0f / SizeBufferY * (NbrPointY - 1);

		for (int y = 0; y < SizeBufferY; y++)
		{
			for (int x = 0; x < SizeBufferX; x++)
			{
				BufferNoise[y * SizeBufferX + x] = SmoothNoise2DStacked(x * scaleX, y * scaleY, NbrPerlinNoiseStacked, OverlapPercent);
			}
		}
	}
};