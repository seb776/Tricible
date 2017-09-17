#pragma once

#include "../Engine/Random/RNG.hpp"
#include "../Engine/Interpolation/Interpolation.hpp"

namespace Tricible
{
	namespace PerlinNoise
	{
		#define	FREQUENCY	2.0f // Description : à chaque octave, on va multiplier le nombre de point qui compose la courbe incarnant le "bruit" 

		//
		// Description
		// Pour une coordonné "x", renvoie un bruit interpolé avec le bruit du point "x + 1"
		//
		float SmoothNoise1D(const float x)
		{
			const int integer_x = (int)x;

			const float a = Tricible::Random<float, 0, 1>(integer_x);
			const float b = Tricible::Random<float, 0, 1>(integer_x + 1);

			// TODO PCO : add mode for smooth choice
			// Tricible::Lerp
			// Tricible::Cosinerp
			// Tricible::Cubicerp ?
			return Tricible::Cosinerp(a, b, x - integer_x);
		}

		//
		// Description
		// Pour une coordonné "x", renvoie un bruit interpolé avec le bruit du point "x + 1"
		// Le bruit interpolé est la résultante de plusieurs bruits superposés
		//
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

		//
		// Description
		// Pour une coordonné 2D "x" et "y", renvoie un bruit interpolé avec le bruit des 3 points alentours (x + 1 et/ou y + 1).
		//
		float SmoothNoise2D(const float x, const float y)
		{
			const int integer_x = (int)x;
			const int integer_y = (int)y;

			const float a = Tricible::Random<float, 0, 1>(integer_x, integer_y);
			const float b = Tricible::Random<float, 0, 1>(integer_x + 1, integer_y);
			const float c = Tricible::Random<float, 0, 1>(integer_x, integer_y + 1);
			const float d = Tricible::Random<float, 0, 1>(integer_x + 1, integer_y + 1);

			// TODO PCO : add mode for smooth choice
			// Tricible::Lerp
			// Tricible::Cosinerp
			// Tricible::Cubicerp ?
			return Tricible::Cosinerp2D(a, b, c, d, x - integer_x, y - integer_y);
		}

		//
		// Description
		// Pour une coordonné 2D "x" et "y", renvoie un bruit interpolé avec le bruit des 3 points alentours (x + 1 et/ou y + 1).
		// Le bruit interpolé est la résultante de plusieurs bruits superposés
		//
		float SmoothNoise2DStacked(const float x, const float y, const int octaves, const float OverlapPercent)
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

		//
		// Description :
		// Calculer un bruit de 1 dimension.
		// Représente une courbe (axe X = const, axe Y = varie)
		//
		// Paramètre
		// NbrPoint -> Représente le nombre de point par lesquels doit passer la courbe
		// SizeBuffer -> taille du buffer passé en paramètre
		// BufferNoise -> tableau de float. Chaque float varie entre [0 ; 1]
		//
		void PerlinNoise1D(const int NbrPoint, const int SizeBuffer, float * BufferNoise[])
		{
			// TODO PCO : Check if NbrPoint is >= 2
			const float scale = 1.0f / SizeBuffer * (NbrPoint - 1); // TODO constexpr ?

			for (int x = 0; x < SizeBuffer; x++)
			{
				(*BufferNoise)[x] = SmoothNoise1D(x * scale);
			}
		}

		//
		// Description :
		// Calculer un bruit de 1 dimension. Le résultat est issu de plusieurs bruits superposés.
		// Représente une courbe (axe X = const, axe Y = varie)
		//
		// Paramètre :
		// NbrPoint -> Représente le nombre de point par lesquels doit passer la courbe  
		// NbrPerlinNoiseStacked -> nombre de couche de bruit superposé (chaque nouvelle couche augmente le nombre de point -> multiplié par FREQUENCY)
		// OverlapPercent -> Pourcentage de superposition de chaque bruit de perlin que l'on rajoute. Si 1.0f, alors 100% de superposition, si 0.1f, alors 10% de superposition
		// SizeBuffer -> Taille du buffer passé en paramètre
		// BufferNoise -> tableau de float. Chaque float varie entre [0 ; 1]
		//
		void PerlinNoise1DStacked(const int NbrPoint, const int NbrPerlinNoiseStacked, const float OverlapPercent, const int SizeBuffer, float * BufferNoise[])
		{
			// TODO PCO : Check if NbrPoint is >= 2
			// TODO PCO : Limiter NbrPerlinNoiseStacked de [2 ; 1024] (1 refusé car reviens à faire PerlinNoise1D(...)
			const float scale = 1.0f / SizeBuffer * (NbrPoint - 1); // TODO PCO constexpr ?

			for (int x = 0; x < SizeBuffer; x++)
			{
				(*BufferNoise)[x] = SmoothNoise1DStacked(x * scale, NbrPerlinNoiseStacked, OverlapPercent);
			}
		}

		//
		// Description :
		// Calculer un bruit de 2 dimensions.
		// Représente un nuage de gris (dégradé : blanc <-> noir)
		//
		// Paramètre :
		// NbrPointX -> Représente le nombre de point par lesquels doit passer la courbe (axe X uniquement)
		// NbrPointY -> Représente le nombre de point par lesquels doit passer la courbe (axe Y uniquement)  
		// SizeBufferX -> Taille du buffer passé en paramètre (axe X uniquement)
		// SizeBufferY -> Taille du buffer passé en paramètre (axe Y uniquement)
		// BufferNoise -> tableau de float. Chaque float varie entre [0 ; 1]
		//
		void PerlinNoise2D(const int NbrPointX, const int NbrPointY, const int SizeBufferX, const int SizeBufferY, float * BufferNoise[])
		{
			const float scaleX = 1.0f / SizeBufferX * (NbrPointX - 1);
			const float scaleY = 1.0f / SizeBufferY * (NbrPointY - 1);

			for (int y = 0; y < SizeBufferY; y++)
			{
				for (int x = 0; x < SizeBufferX; x++)
				{
					(*BufferNoise)[y * SizeBufferX + x] = SmoothNoise2D(x * scaleX, y * scaleY);
				}
			}
		}

		//
		// Description :
		// Calculer un bruit de 2 dimension. Le résultat est issu de plusieurs bruits superposés.
		// Représente un nuage de gris (dégradé : blanc <-> noir)
		//
		// Paramètre :
		// NbrPoint -> Représente le nombre de point par lesquels doit passer la courbe  
		// NbrPerlinNoiseStacked -> nombre de couche de bruit superposé (chaque nouvelle couche augmente le nombre de point -> multiplié par FREQUENCY)
		// OverlapPercent -> Pourcentage de superposition de chaque bruit de perlin que l'on rajoute. Si 1.0f, alors 100% de superposition, si 0.1f, alors 10% de superposition
		// SizeBuffer -> Taille du buffer passé en paramètre
		// BufferNoise -> tableau de float. Chaque float varie entre [0 ; 1]
		//
		void PerlinNoise2DStacked(const int NbrPointX, const int NbrPointY, const int NbrPerlinNoiseStacked, const float OverlapPercent, const int SizeBufferX, const int SizeBufferY, float * BufferNoise[])
		{
			const float scaleX = 1.0f / SizeBufferX * (NbrPointX - 1);
			const float scaleY = 1.0f / SizeBufferY * (NbrPointY - 1);

			for (int y = 0; y < SizeBufferY; y++)
			{
				for (int x = 0; x < SizeBufferX; x++)
				{
					(*BufferNoise)[y * SizeBufferX + x] = SmoothNoise2DStacked(x * scaleX, y * scaleY, NbrPerlinNoiseStacked, OverlapPercent);
				}
			}
		}
	}
};