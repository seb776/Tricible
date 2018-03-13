#pragma once

#include <string>
#include "../Color/RGB.hpp"
//#define FREEIMAGE_LIB
#include "FreeImage.h"
#include "../Tools/Tools.hpp"
#define _USE_MATH_DEFINES
#include <cmath>

namespace Tricible
{

	class Texture
	{
	public:
		int _width;
		int _height;
		FIBITMAP* _image;
	public:
		Texture()
		{

		}

		Texture(int width, int height)
		{

		}

		Texture(std::string filePath)
		{
			LoadFromPath(filePath);
		}

		bool LoadFromPath(std::string filePath)
		{
			auto imgType = FreeImage_GetFileType(filePath.c_str(), 0);
			_image = FreeImage_Load(imgType, filePath.c_str());
			_height = FreeImage_GetHeight(_image);
			_width = FreeImage_GetWidth(_image);
			return true;
		}

		Color::RGB GetPixel(uint32_t x, uint32_t y)
		{
			RGBQUAD color;
			FreeImage_GetPixelColor(_image, x, y, &color);
			Color::RGB col = Color::RGB(color.rgbRed, color.rgbGreen, color.rgbBlue);
			return col;
		}
		
		// pitch -pi/2 >= x >= pi/2
		// yaw -pi > x >= pi
		Color::RGB Get360Pixel(float pitch, float yaw)
		{
			uint32_t x;
			uint32_t y;
			RGBQUAD color;
			yaw = yaw * (yaw >= 0.0f) + (yaw + M_PI2) * (yaw < 0);
			float factX = Clamp01(yaw / M_PI2);
			float factY = Clamp01((pitch + M_PI_2) / M_PI);
			factX = 1.0f - factX;
			factY = 1.0f - factY;
			x = (uint32_t)(factX * (_width - 1U));
			y = (uint32_t)(factY * (_height - 1U));
			auto ret = FreeImage_GetPixelColor(_image, x, y, &color);
			Color::RGB col = Color::RGB(color.rgbRed, color.rgbGreen, color.rgbBlue);
			return col;
		}
	};
}