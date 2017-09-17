#pragma once

// STL
#include <vector>
#include <algorithm>

#include <cassert>

// Tricible
#include "../Engine/Tools.hpp"
#include "../Engine/Color/RGBA.hpp"

#include "GradientPoint.hpp"

namespace Tricible
{
	class GradientsLinear
	{

	private:

		std::vector<GradientPoint> _gradientsPoint;	// Array that stores the gradient points.

	public:

		// ----------------------------------------------------------------
		// Section : Constructor + Destructor
		// ----------------------------------------------------------------

		// TODO : rvalue ?

		// Default constructor
		GradientsLinear()
		{
			// nothing
		}

		// Copy constructor taking a const ref
		GradientsLinear(const GradientsLinear & obj)
			: _gradientsPoint(obj._gradientsPoint)
		{
			// nothing
		}

		// Assignment operator
		GradientsLinear & operator=(const GradientsLinear & obj)
		{
			if (this != &obj)
			{
				_gradientsPoint = obj._gradientsPoint;
			}
			return (*this);
		}

		// Destructor [almost always virtual] 
		virtual ~GradientsLinear()
		{
			// nothing
		}

		// ----------------------------------------------------------------
		// Section : Public method
		// ----------------------------------------------------------------

		// Creates a modifiable clone of this GradientsLinear, making deep copies of this object's values.
		void Clone(GradientsLinear * cloneOut)
		{
			*cloneOut = *this;
		}

		void Clear()
		{
			_gradientsPoint.clear();
		}

		const std::vector<GradientPoint> & GetGradients() const
		{
			return _gradientsPoint;
		}

		size_t Size() const
		{
			return _gradientsPoint.size();
		}

		// The insertion of an element is always sorted
		// Because the algorithm "upper_bound" which looks for the limit superior after which the element must be inserted
		void AddGradientPoint(const GradientPoint & gradient)
		{
			std::vector<GradientPoint>::iterator it = std::upper_bound(_gradientsPoint.begin(), _gradientsPoint.end(), gradient);

			_gradientsPoint.insert(it, gradient);
		}

		void GetColor(float position, Color::RGBA * colorOut)
		{
			assert(_gradientsPoint.size() >= 2);
			assert(colorOut != nullptr);

			// Find the first element in the gradient point array that has a gradient position larger than the gradient position passed to this method.
			int indexPosition = std::upper_bound(_gradientsPoint.begin(), _gradientsPoint.end(), position) - _gradientsPoint.begin();

			// Find the two nearest gradient points so that we can perform linear interpolation on the color.
			int indexLeft = Tricible::Clamp<int>(indexPosition - 1, 0, _gradientsPoint.size() - 1);
			int indexRight = Tricible::Clamp<int>(indexPosition, 0, _gradientsPoint.size() - 1);

			// If some gradient points are missing (which occurs if the gradient position passed to this method is greater than the largest gradient
			// position or less than the smallest gradient position in the array), get the corresponding gradient color of the nearest gradient point and exit now.
			if (indexLeft == indexRight)
			{
				*colorOut = _gradientsPoint[indexRight].GetColor();
				return;
			}

			// Compute the alpha value used for linear interpolation.
			float poistionLeft = _gradientsPoint[indexLeft].GetPosition();
			float poistionRight = _gradientsPoint[indexRight].GetPosition();
			float alpha = (position - poistionLeft) / (poistionRight - poistionLeft);

			// Now perform the linear interpolation given the alpha value.
			Tricible::Colerp(_gradientsPoint[indexLeft].GetColor(), _gradientsPoint[indexRight].GetColor(), alpha, colorOut);
		}

	};
}