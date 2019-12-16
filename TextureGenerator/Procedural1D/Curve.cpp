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
#include "Curve.hpp"

namespace Procedural1D
{
	// Description
	// Pour une coordonn� "x", renvoie un bruit interpol� avec le bruit du point "x + 1"
	float ComputeSmoothNoise(const float x)
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

	// Description
	// Calculer un bruit de 1 dimension.
	// Repr�sente une courbe (axe X = const, axe Y = varie)
	//
	// Param�tre
	// NbrPoint -> Repr�sente le nombre de point par lesquels doit passer la courbe
	// SizeBuffer -> taille du buffer pass� en param�tre
	// BufferNoise -> tableau de float. Chaque float varie entre [0 ; 1]
	void Curve(const int NbrPoint, const int SizeBuffer, float * BufferNoise[])
	{
		// TODO PCO : Check if NbrPoint is >= 2
		const float scale = 1.0f / SizeBuffer * (NbrPoint - 1); // TODO constexpr ?

		for (int x = 0; x < SizeBuffer; ++x)
		{
			(*BufferNoise)[x] = ComputeSmoothNoise(x * scale);
		}
	}
};

// END
