//
// Author: Pierre COURTEILLE
//

//----------------------------------------//
// include Tricible
//----------------------------------------//
#include "../../Engine/Tools/RNG.hpp" // Pour Random
#include "../../Engine/Tools/Interpolation.hpp" // Pour Cosinerp2D

//----------------------------------------//
// include Procedural
//----------------------------------------//
#include "PerlinNoise.hpp"

namespace Procedural2D
{
	// Description
	// Pour une coordonné 2D "x" et "y", renvoie un bruit interpolé avec le bruit des 3 points alentours (x + 1 et/ou y + 1).
	float ComputeSmoothNoise(const float x, const float y)
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
	void PerlinNoise(const int NbrPointX, const int NbrPointY, const int SizeBufferX, const int SizeBufferY, float * BufferNoise[])
	{
		const float scaleX = 1.0f / SizeBufferX * (NbrPointX - 1);
		const float scaleY = 1.0f / SizeBufferY * (NbrPointY - 1);

		for (int y = 0; y < SizeBufferY; ++y)
		{
			for (int x = 0; x < SizeBufferX; ++x)
			{
				(*BufferNoise)[y * SizeBufferX + x] = ComputeSmoothNoise(x * scaleX, y * scaleY);
			}
		}
	}
}

// END
