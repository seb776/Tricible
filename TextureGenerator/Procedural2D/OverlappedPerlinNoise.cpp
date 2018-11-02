//
// Author: Pierre COURTEILLE
//

//----------------------------------------//
// include Procedural
//----------------------------------------//
#include "PerlinNoise.hpp" // pour Procedural::SmoothNoise( ... , ... )
#include "OverlappedPerlinNoise.hpp"

namespace Procedural2D
{
	// Description
	// Pour une coordonné 2D "x" et "y", renvoie un bruit interpolé avec le bruit des 3 points alentours (x + 1 et/ou y + 1).
	// Le bruit interpolé est la résultante de plusieurs bruits superposés
	float ComputeSmoothNoise(const float x, const float y, const int octaves, const float OverlapPercent)
	{
		float sum = 0.0f;
		float amplitude = 1.0; // l'amplitude du bruit est l'écart entre la plus grande et la plus petite valeur du bruit.
		float tmpFrequency = 1.0;
		const float frequency = 2.0f; // Description : à chaque octave, on va multiplier le nombre de point qui compose la courbe incarnant le "bruit" 

		for (int i = 0; i < octaves; ++i)
		{
			sum += amplitude * Procedural2D::ComputeSmoothNoise(x * tmpFrequency, y * tmpFrequency);
			amplitude *= OverlapPercent;
			tmpFrequency *= frequency; // à chaque octave, on va multiplier le nombre de point qui compose la courbe incarnant le "bruit" 
		}
		return sum * ((1 - OverlapPercent) / (1 - amplitude));
	}

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
	void OverlappedPerlinNoise(const int NbrPointX, const int NbrPointY, const int NbrPerlinNoiseStacked, const float OverlapPercent, const int SizeBufferX, const int SizeBufferY, float * BufferNoise[])
	{
		const float scaleX = 1.0f / SizeBufferX * (NbrPointX - 1);
		const float scaleY = 1.0f / SizeBufferY * (NbrPointY - 1);

		for (int y = 0; y < SizeBufferY; ++y)
		{
			for (int x = 0; x < SizeBufferX; ++x)
			{
				(*BufferNoise)[y * SizeBufferX + x] = ComputeSmoothNoise(x * scaleX, y * scaleY, NbrPerlinNoiseStacked, OverlapPercent);
			}
		}
	}
};

// END
