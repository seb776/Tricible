#pragma once

#include <vector>
#include <algorithm>

#include <cassert>

#include "../Engine/Tools.hpp"

#include "GradientPoint.hpp"
#include "ColorRGBA.hpp"

class GradientCollection
{

private:

	std::vector<GradientPoint> _gradientPoints;	// Array that stores the gradient points.

public:

	// ----------------------------------------------------------------
	// Section : Constructor + Destructor
	// ----------------------------------------------------------------

	// TODO : rvalue ?

	// Default constructor
	GradientCollection()
	{
		// nothing
	}

	// Copy constructor taking a const ref
	GradientCollection(const GradientCollection & obj)
		: _gradientPoints(obj._gradientPoints)
	{
		// nothing
	}

	// Assignment operator
	GradientCollection & operator=(const GradientCollection & obj)
	{
		if (this != &obj)
		{
			_gradientPoints = obj._gradientPoints;
		}
		return (*this);
	}

	// Destructor [almost always virtual] 
	virtual ~GradientCollection()
	{
		// nothing
	}

	// ----------------------------------------------------------------
	// Section : Public method
	// ----------------------------------------------------------------

	const std::vector<GradientPoint> & GetGradients() const
	{
		return _gradientPoints;
	}

	size_t Size() const
	{
		return _gradientPoints.size();
	}

	void Clear()
	{
		_gradientPoints.clear();
	}

	// The insertion of an element is always sorted
	// Because the algorithm "upper_bound" which looks for the limit superior after which the element must be inserted
	void AddGradientPoint(const GradientPoint & gradient)
	{
		std::vector<GradientPoint>::iterator it = std::upper_bound(_gradientPoints.begin(), _gradientPoints.end(), gradient);

		_gradientPoints.insert(it, gradient);
	}

	void GetColorRGBA(float position, ColorRGBA * color)
	{
		assert(_gradientPoints.size() >= 2);
		assert(color != nullptr);

		// Find the first element in the gradient point array that has a gradient position larger than the gradient position passed to this method.
		int indexPosition = std::upper_bound(_gradientPoints.begin(), _gradientPoints.end(), position) - _gradientPoints.begin();

		// Find the two nearest gradient points so that we can perform linear interpolation on the color.
		int indexLeft = Tricible::Clamp<int>(indexPosition - 1, 0, _gradientPoints.size() - 1);
		int indexRight = Tricible::Clamp<int>(indexPosition, 0, _gradientPoints.size() - 1);

		// If some gradient points are missing (which occurs if the gradient position passed to this method is greater than the largest gradient
		// position or less than the smallest gradient position in the array), get the corresponding gradient color of the nearest gradient point and exit now.
		if (indexLeft == indexRight)
		{
			*color = _gradientPoints[indexRight].GetColor();
			return;
		}

		// Compute the alpha value used for linear interpolation.
		float poistionLeft = _gradientPoints[indexLeft].GetPosition();
		float poistionRight = _gradientPoints[indexRight].GetPosition();
		float alpha = (position - poistionLeft) / (poistionRight - poistionLeft);

		// Now perform the linear interpolation given the alpha value.
		Tricible::Colerp(_gradientPoints[indexLeft].GetColor(), _gradientPoints[indexRight].GetColor(), alpha, color);
	}

};