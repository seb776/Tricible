//
// Author: Pierre COURTEILLE
//

//----------------------------------------//
// protection double inclusion
//----------------------------------------//
#pragma once

//----------------------------------------//
// include STL
//----------------------------------------//
#include <vector> // pour std::vector
#include <algorithm> // pour std::upper_bound
#include <cassert> // pour assert

//----------------------------------------//
// include Tricible
//----------------------------------------//
#include "../../../Engine/Tools/Tools.hpp"
#include "../../../Engine/Tools/Interpolation.hpp"
#include "../../../Engine/Color/RGBA.hpp"

//----------------------------------------//
// include Gradient
//----------------------------------------//
#include "PointGradient.hpp"

//----------------------------------------//
// Code
//----------------------------------------//
namespace Utility
{
	using namespace Tricible;

	// Description :
	// La classe PointGradient permet d'indiquer la position d'une couleur sur un LinearGradient.
	// Un LineraGradient est une classe permettant de représenter un dégradé de couleur linéaire.
	// Rappel : En mathématique, un gradient est un vecteur indiquant comment la valeur d'une fonction de plusieurs variables varie quand ces variables varient.
	namespace Gradient
	{
		class LinearGradient
		{

		private:

			std::vector<PointGradient> _points;	// Array that stores the gradient points.

		public:

			// ----------------------------------------------------------------
			// Section : Constructor + Destructor
			// ----------------------------------------------------------------

			// TODO : rvalue ?

			// Default constructor
			LinearGradient()
			{
				// nothing
			}

			// Copy constructor taking a const ref
			LinearGradient(const LinearGradient & obj)
				: _points(obj._points)
			{
				// nothing
			}

			// Assignment operator
			LinearGradient & operator=(const LinearGradient & obj)
			{
				if (this != &obj)
				{
					_points = obj._points;
				}
				return (*this);
			}

			// Destructor [almost always virtual] 
			virtual ~LinearGradient()
			{
				// nothing
			}

			// ----------------------------------------------------------------
			// Section : Public method
			// ----------------------------------------------------------------

			// Creates a modifiable clone of this LinearGradient, making deep copies of this object's values.
			void Clone(LinearGradient * cloneOut)
			{
				*cloneOut = *this;
			}

			void Clear()
			{
				_points.clear();
			}

			const std::vector<PointGradient> & GetGradients() const
			{
				return _points;
			}

			size_t Size() const
			{
				return _points.size();
			}

			// The insertion of an element is always sorted
			// Because the algorithm "upper_bound" which looks for the limit superior after which the element must be inserted
			void AddPoint(const PointGradient & gradient)
			{
				std::vector<PointGradient>::iterator it = std::upper_bound(_points.begin(), _points.end(), gradient);

				_points.insert(it, gradient);
			}

			// The insertion of an element is always sorted
			// Because the algorithm "upper_bound" which looks for the limit superior after which the element must be inserted
			void AddPoint(const float pos, uint8_t r, uint8_t g, uint8_t b)
			{
				Gradient::PointGradient gradient(pos, Color::RGBA(r, g, b));
				std::vector<PointGradient>::iterator it = std::upper_bound(_points.begin(), _points.end(), gradient);

				_points.insert(it, gradient);
			}

			void GetColor(float position, Color::RGBA * colorOut)
			{
				assert(_points.size() >= 2);
				assert(colorOut != nullptr);

				// Find the first element in the gradient point array that has a gradient position larger than the gradient position passed to this method.
				int indexPosition = std::upper_bound(_points.begin(), _points.end(), position) - _points.begin();

				// Find the two nearest gradient points so that we can perform linear interpolation on the color.
				int indexLeft = Tricible::Clamp<int>(indexPosition - 1, 0, _points.size() - 1);
				int indexRight = Tricible::Clamp<int>(indexPosition, 0, _points.size() - 1);

				// If some gradient points are missing (which occurs if the gradient position passed to this method is greater than the largest gradient
				// position or less than the smallest gradient position in the array), get the corresponding gradient color of the nearest gradient point and exit now.
				if (indexLeft == indexRight)
				{
					*colorOut = _points[indexRight].GetColor();
					return;
				}

				// Compute the alpha value used for linear interpolation.
				float positionLeft = _points[indexLeft].GetPosition();
				float positionRight = _points[indexRight].GetPosition();
				float alpha = (position - positionLeft) / (positionRight - positionLeft);

				// Now perform the linear interpolation given the alpha value.
				Tricible::Colerp(_points[indexLeft].GetColor(), _points[indexRight].GetColor(), alpha, colorOut);
			}
		};
	}
}

// END
