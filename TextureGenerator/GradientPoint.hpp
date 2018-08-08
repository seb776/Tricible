#pragma once

// Standard library header
#include <stdint.h>

// Tricicble
#include "../Engine/Color/RGBA.hpp"

namespace Tricible
{
	class GradientPoint
	{

	private:

		float		_position;
		Color::RGBA _color;

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

		// Constructor with parameters.
		// @param r Value of the red channel.
		// @param g Value of the green channel.
		// @param b Value of the blue channel.
		GradientPoint(const float pos, const Color::RGBA & color)
			: _position(pos), _color(color)
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

		// Creates a modifiable clone. Making deep copies of this object's values.
		void Clone(GradientPoint * gradientPointOut)
		{
			*gradientPointOut = *this;
		}

		void Clear()
		{
			_position = 0.0f;
			_color.Clear();
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

		void setColor(const Color::RGBA & color)
		{
			_color = color;
		}

		const Color::RGBA & GetColor() const
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
}

// END
