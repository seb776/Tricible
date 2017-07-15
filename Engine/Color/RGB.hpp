#pragma once

// Standard library header
#include <stdint.h>

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
			RGB()
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
		};
	}
}

// END
