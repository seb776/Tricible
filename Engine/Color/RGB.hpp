#pragma once

// Standard library header
#include <stdint.h>
#include "../Tools/Tools.hpp"

namespace Tricible
{
	namespace Color
	{
		class RGB
		{

		private:

			// TODO public + no getter ? or inline ?

			uint8_t _red;		// Value of the red channel.
			uint8_t _green;  	// Value of the green channel.
			uint8_t _blue;		// Value of the blue channel.

		public:

			// ----------------------------------------------------------------
			// Section : Constructor + Destructor
			// ----------------------------------------------------------------

			// TODO : rvalue ?

			// Default constructor
			RGB() : _red(0U), _green(0U), _blue(0U)
			{
				// nothing
			}

			// Copy constructor taking a const ref
			RGB(const RGB & obj)
				: _red(obj._red), _green(obj._green), _blue(obj._blue)
			{
				// nothing
			}

			// Constructor with parameters.
			// @param r Value of the red channel.
			// @param g Value of the green channel.
			// @param b Value of the blue channel.
			RGB(uint8_t r, uint8_t g, uint8_t b)
				: _red(r), _green(g), _blue(b)
			{
				// nothing
			}

			// Assignment operator
			RGB & operator=(const RGB & obj)
			{
				if (this != &obj)
				{
					_red = obj._red;
					_green = obj._green;
					_blue = obj._blue;
				}
				return (*this);
			}

			// Creates a modifiable clone. Making deep copies of this object's values.
			void Clone(RGB * colorOut)
			{
				*colorOut = *this;
			}

			void Clear()
			{
				_red = 0;
				_green = 0;
				_blue = 0;
			}

			// Destructor [almost always virtual] 
			virtual ~RGB()
			{
				// nothing
			}

			// ----------------------------------------------------------------
			// Section : Getter + Setter
			// ----------------------------------------------------------------

			// get red
			const uint8_t Red() const
			{
				return (_red);
			}

			// set red
			void Red(const uint8_t red)
			{
				_red = red;
			}

			// get green
			const uint8_t Green() const
			{
				return (_green);
			}

			// set green
			void Green(const uint8_t green)
			{
				_green = green;
			}

			// get blue
			const uint8_t Blue() const
			{
				return (_blue);
			}

			// set blue
			void Blue(const uint8_t blue)
			{
				_blue = blue;
			}

			// ----------------------------------------------------------------
			// Section : Comparison operators
			// ----------------------------------------------------------------

			bool operator == (const RGB & rightValue) const
			{
				return (_red == rightValue._red && _green == rightValue._green && _blue && rightValue._blue);
			}

			bool operator != (const RGB & rightValue) const
			{
				return !(*this == rightValue);
			}

			RGB operator*(float rightValue) const
			{
				RGB copy = *this;

				copy._red = (uint32_t)(Clamp((float)copy._red * rightValue, 0.0f, 255.0f));
				copy._green = (uint32_t)(Clamp((float)copy._green * rightValue, 0.0f, 255.0f));
				copy._blue = (uint32_t)(Clamp((float)copy._blue * rightValue, 0.0f, 255.0f));
				return copy;
			}

			const RGB& operator+=(const RGB& rightValue)
			{
				this->_red = Clamp((uint32_t)this->_red + (uint32_t)rightValue._red, 0U, 255U);
				this->_green = Clamp((uint32_t)this->_green + (uint32_t)rightValue._green, 0U, 255U);
				this->_blue = Clamp((uint32_t)this->_blue + (uint32_t)rightValue._blue, 0U, 255U);
				return *this;
			}

			RGB operator+(const RGB& rightValue)
			{
				Color::RGB col;
				col._red = Clamp((uint32_t)this->_red + (uint32_t)rightValue._red, 0U, 255U);
				col._green = Clamp((uint32_t)this->_green + (uint32_t)rightValue._green, 0U, 255U);
				col._blue = Clamp((uint32_t)this->_blue + (uint32_t)rightValue._blue, 0U, 255U);
				return col;
			}

			// TODO Rename to Uint32_t
			uint32_t ToInt()
			{
				//return (_red << 24) + (_green << 16) + (_blue << 8) + 0xFF;
				return 0xFF000000 + _red + (_green << 8) + (_blue << 16);
			}
		};

		class HDRARGB
		{
		public:
			float A;
			float R;
			float G;
			float B;
			HDRARGB() :
				HDRARGB(1.0f,0.0f,0.0f, 0.0f)
			{}

			HDRARGB(float a, float r, float g, float b) :
				A(a),
				R(r),
				G(g),
				B(b)
			{}

			operator RGB() const {
				return RGB(static_cast<int8_t>(R * 255.f), static_cast<int8_t>(G * 255.f), static_cast<int8_t>(B * 255.f));
			}
		};
	}
}

// END
