#pragma once

#include <stdint.h>

class ColorRGBA
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
	ColorRGBA()
	{
		// nothing
	}

	// Copy constructor taking a const ref
	ColorRGBA(const ColorRGBA & obj)
		: _red(obj._red), _green(obj._green), _blue(obj._blue), _alpha(obj._alpha)
	{
		// nothing
	}

	// Assignment operator
	ColorRGBA & operator=(const ColorRGBA & obj)
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

	// Constructor with parameters.
	// @param r Value of the red channel.
	// @param g Value of the green channel.
	// @param b Value of the blue channel.
	ColorRGBA(uint8_t r, uint8_t g, uint8_t b, uint8_t a = 255)
		: _red(r), _green(g), _blue(b), _alpha(a)
	{
		// nothing
	}

	// Destructor [almost always virtual] 
	virtual ~ColorRGBA()
	{
		// nothing
	}

	// ----------------------------------------------------------------
	// Section : Getter + Setter
	// ----------------------------------------------------------------

	const uint8_t GetRed() const
	{
		return (_red);
	}

	void SetRed(const uint8_t red)
	{
		_red = red;
	}

	const uint8_t GetGreen() const
	{
		return (_green);
	}

	void SetGreen(const uint8_t green)
	{
		_green = green;
	}

	const uint8_t GetBlue() const
	{
		return (_blue);
	}

	void SetBlue(const uint8_t blue)
	{
		_blue = blue;
	}

	const uint8_t GetAlpha() const
	{
		return (_alpha);
	}

	void SetAlpha(const uint8_t alpha)
	{
		_alpha = alpha;
	}
};

// END
