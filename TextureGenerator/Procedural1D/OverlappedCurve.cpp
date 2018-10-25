//
// Author: Pierre COURTEILLE
//

//----------------------------------------//
// include Procedural
//----------------------------------------//
#include "Curve.hpp" // Pour le smoothNoise simple
#include "OverlappedCurve.hpp"

namespace Procedural1D
{
	// Description
	// Pour une coordonné "x", renvoie un bruit interpolé avec le bruit du point "x + 1"
	// Le bruit interpolé est la résultante de plusieurs bruits superposés
	float ComputeSmoothNoise(const float x, const int octaves, const float OverlapPercent)
	{
		float sum = 0.0f;
		float amplitude = 1.0; // l'amplitude du bruit est l'écart entre la plus grande et la plus petite valeur du bruit.
		float tmpFrequency = 1.0;
		const float frequency = 2.0f; // Description : à chaque octave, on va multiplier le nombre de point qui compose la courbe incarnant le "bruit" 

		for (int i = 0; i < octaves; ++i)
		{
			sum += amplitude * Procedural1D::ComputeSmoothNoise(x * tmpFrequency);
			amplitude *= OverlapPercent;
			tmpFrequency *= frequency;
		}
		return sum * ((1 - OverlapPercent) / (1 - amplitude));
	}

	// Description
	// Calculer un bruit de 1 dimension. Le résultat est issu de plusieurs bruits superposés.
	// Représente une courbe (axe X = const, axe Y = varie)
	//
	// Paramètre :
	// NbrPoint -> Représente le nombre de point par lesquels doit passer la courbe  
	// NbrPerlinNoiseStacked -> nombre de couche de bruit superposé (chaque nouvelle couche augmente le nombre de point -> multiplié par FREQUENCY)
	// OverlapPercent -> Pourcentage de superposition de chaque bruit de perlin que l'on rajoute. Si 1.0f, alors 100% de superposition, si 0.1f, alors 10% de superposition
	// SizeBuffer -> Taille du buffer passé en paramètre
	// BufferNoise -> tableau de float. Chaque float varie entre [0 ; 1]
	void OverlappedCurve(const int NbrPoint, const int NbrNoiseStacked, const float OverlapPercent, const int SizeBuffer, float * BufferNoise[])
	{
		// TODO PCO : Check if NbrPoint is >= 2
		// TODO PCO : Limiter NbrPerlinNoiseStacked de [2 ; 1024] (1 refusé car reviens à faire PerlinNoise1D(...)
		const float scale = 1.0f / SizeBuffer * (NbrPoint - 1); // TODO PCO constexpr ?

		for (int x = 0; x < SizeBuffer; ++x)
		{
			(*BufferNoise)[x] = ComputeSmoothNoise(x * scale, NbrNoiseStacked, OverlapPercent);
		}
	}
};

// END
