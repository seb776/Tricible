//
// Author: Pierre COURTEILLE
//

//----------------------------------------//
// protection double inclusion
//----------------------------------------//
#pragma once

//----------------------------------------//
// include Tricible
//----------------------------------------//
#include "../../../Engine/Color/RGBA.hpp"

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
		class PointGradient
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
			PointGradient()
			{
				// nothing
			}

			// Copy constructor taking a const ref
			PointGradient(const PointGradient & obj)
				: _position(obj._position), _color(obj._color)
			{
				// nothing
			}

			// Constructor with parameters.
			// @param r Value of the red channel.
			// @param g Value of the green channel.
			// @param b Value of the blue channel.
			PointGradient(const float pos, const Color::RGBA & color)
				: _position(pos), _color(color)
			{
				// nothing
			}

			// Assignment operator
			PointGradient & operator=(const PointGradient & obj)
			{
				if (this != &obj)
				{
					_position = obj._position;
					_color = obj._color;
				}
				return (*this);
			}

			// Creates a modifiable clone. Making deep copies of this object's values.
			void Clone(PointGradient * PointGradientOut)
			{
				*PointGradientOut = *this;
			}

			void Clear()
			{
				_position = 0.0f;
				_color.Clear();
			}

			// Destructor [almost always virtual] 
			virtual ~PointGradient()
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
			// Section : Comparison operators (PointGradient)
			// ----------------------------------------------------------------

			bool operator < (const PointGradient & rightValue) const
			{
				return (_position < rightValue._position);
			}

			bool operator <= (const PointGradient & rightValue) const
			{
				return (_position <= rightValue._position);
			}

			bool operator > (const PointGradient & rightValue) const
			{
				return (_position > rightValue._position);
			}

			bool operator >= (const PointGradient & rightValue) const
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

		bool operator<(float leftValue, const PointGradient & rightValue)
		{
			return (leftValue < rightValue.GetPosition());
		}

		bool operator<(const PointGradient & leftValue, float rightValue)
		{
			return (leftValue.GetPosition() < rightValue);
		}

		bool operator>(float leftValue, const PointGradient & rightValue)
		{
			return (leftValue > rightValue.GetPosition());
		}

		bool operator>(const PointGradient & leftValue, float rightValue)
		{
			return (leftValue.GetPosition() > rightValue);
		}
	}
}

// END
