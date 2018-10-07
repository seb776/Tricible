#pragma once

#include <string>
#include "../Color/RGB.hpp"
//#define FREEIMAGE_LIB
#include <FreeImage.h>
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

		Texture(int width, int height) :
			_width(width), _height(height)
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

		Color::RGB Get360Pixel(float u, float v)
		{
			uint32_t x;
			uint32_t y;
			RGBQUAD color;
			float factX = 1.0f - u;
			float factY = v;
			x = (uint32_t)(factX * (_width - 1U));
			y = (uint32_t)(factY * (_height - 1U));
			auto ret = FreeImage_GetPixelColor(_image, x, y, &color);
			Color::RGB col = Color::RGB(color.rgbRed, color.rgbGreen, color.rgbBlue);
			return col;
		}

		Color::RGB Get360PixelBilinearInterpolation(float u, float v)
		{
			u = u * this->_width - 0.5f;
			v = v * this->_height - 0.5f;
			int32_t x = static_cast<int32_t>(floor(u));
			int32_t y = static_cast<int32_t>(floor(v));
			float u_ratio = u - x;
			float v_ratio = v - y;
			float u_opposite = 1.0f - u_ratio;
			float v_opposite = 1.0f - v_ratio;

			Color::RGB outColor = (GetPixel(x, y) * u_opposite + GetPixel(x + 1, y) * u_ratio) * v_opposite +
				(GetPixel(x, y + 1) * u_opposite + GetPixel(x + 1, y + 1) * u_ratio) * v_ratio;

			return outColor;
		}
	};
}