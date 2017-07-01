#pragma once

#include <stdint.h>
#include "ColorRGBA.hpp"

class GradientPoint
{

private:

	float _position;
	ColorRGBA _color;

public:

	// ----------------------------------------------------------------
	// Section : Constructor + Destructor
	// ----------------------------------------------------------------

	// TODO : rvalue ?

	// Default constructor
	GradientPoint()
	{
		// nothing
	}

	// Copy constructor taking a const ref
	GradientPoint(const GradientPoint & obj)
		: _position(obj._position), _color(obj._color)
	{
		// nothing
	}

	// Assignment operator
	GradientPoint & operator=(const GradientPoint & obj)
	{
		if (this != &obj)
		{
			_position = obj._position;
			_color = obj._color;
		}
		return (*this);
	}

	// Constructor with parameters.
	// @param r Value of the red channel.
	// @param g Value of the green channel.
	// @param b Value of the blue channel.
	GradientPoint(const float pos, const ColorRGBA & color)
		: _position(pos), _color(color)
	{
		// nothing
	}

	// Destructor [almost always virtual] 
	virtual ~GradientPoint()
	{
		// nothing
	}

	// ----------------------------------------------------------------
	// Section : Getter + Setter
	// ----------------------------------------------------------------

	void setPosition(const float position)
	{
		_position = position;
	}

	const float GetPosition() const
	{
		return (_position);
	}

	void setColor(const ColorRGBA & color)
	{
		_color = color;
	}

	const ColorRGBA & GetColor() const
	{
		return (_color);
	}

	// ----------------------------------------------------------------
	// Section : Comparison operators (GradientPoint)
	// ----------------------------------------------------------------

	bool operator < (const GradientPoint & rightValue) const
	{
		return (_position < rightValue._position);
	}

	bool operator <= (const GradientPoint & rightValue) const
	{
		return (_position <= rightValue._position);
	}

	bool operator > (const GradientPoint & rightValue) const
	{
		return (_position > rightValue._position);
	}

	bool operator >= (const GradientPoint & rightValue) const
	{
		return (_position >= rightValue._position);
	}

	// ----------------------------------------------------------------
	// Section : Comparison operators (float)
	// ----------------------------------------------------------------

	bool operator<(const float rightValue) const 
	{
		return (_position < rightValue);
	}

	bool operator <= (const float rightValue) const
	{
		return (_position <= rightValue);
	}

	bool operator > (const float rightValue) const
	{
		return (_position > rightValue);
	}

	bool operator >= (const float rightValue) const
	{
		return (_position >= rightValue);
	}
};

bool operator<(float leftValue, const GradientPoint & rightValue)
{
	return (leftValue < rightValue.GetPosition());
}

bool operator<(const GradientPoint & leftValue, float rightValue)
{
	return (leftValue.GetPosition() < rightValue);
}

bool operator>(float leftValue, const GradientPoint & rightValue)
{
	return (leftValue > rightValue.GetPosition());
}

bool operator>(const GradientPoint & leftValue, float rightValue)
{
	return (leftValue.GetPosition() > rightValue);
}