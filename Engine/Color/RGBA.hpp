#pragma once

// Standard library header
#include <stdint.h>

namespace Tricible
{
	namespace Color
	{
		class RGBA
		{

		private:

			// TODO public + no getter ? or inline ?

			uint8_t _red;		// Value of the red channel.
			uint8_t _green;  	// Value of the green channel.
			uint8_t _blue;		// Value of the blue channel.
			uint8_t _alpha;		// Value of the alpha / transparency channel.

		public:

			// ----------------------------------------------------------------
			// Section : Constructor + Destructor
			// ----------------------------------------------------------------

			// TODO : rvalue ?

			// Default constructor
			RGBA()
			{
				// nothing
			}

			// Copy constructor taking a const ref
			RGBA(const RGBA & obj)
				: _red(obj._red), _green(obj._green), _blue(obj._blue), _alpha(obj._alpha)
			{
				// nothing
			}

			// Constructor with parameters.
			// @param r Value of the red channel.
			// @param g Value of the green channel.
			// @param b Value of the blue channel.
			RGBA(uint8_t r, uint8_t g, uint8_t b, uint8_t a = 255)
				: _red(r), _green(g), _blue(b), _alpha(a)
			{
				// nothing
			}

			// Assignment operator
			RGBA & operator=(const RGBA & obj)
			{
				if (this != &obj)
				{
					_red = obj._red;
					_green = obj._green;
					_blue = obj._blue;
					_alpha = obj._alpha;
				}
				return (*this);
			}

			// Creates a modifiable clone. Making deep copies of this object's values.
			void Clone(RGBA * colorOut)
			{
				*colorOut = *this;
			}

			void Clear()
			{
				_red = 0;
				_green = 0;
				_blue = 0;
				_alpha = 0;
			}

			// Destructor [almost always virtual] 
			virtual ~RGBA()
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

			// get alpha
			const uint8_t Alpha() const
			{
				return (_alpha);
			}

			// set alpha
			void Alpha(const uint8_t alpha)
			{
				_alpha = alpha;
			}

			// ----------------------------------------------------------------
			// Section : Comparison operators
			// ----------------------------------------------------------------

			bool operator == (const RGBA & rightValue) const
			{
				return (_red == rightValue._red && _green == rightValue._green && _blue && rightValue._blue && _alpha == rightValue._alpha);
			}

			bool operator != (const RGBA & rightValue) const
			{
				return !(*this == rightValue);
			}
		};
	}
}

// END
