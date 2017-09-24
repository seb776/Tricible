#pragma once

#include "../Point3.hpp"

namespace Tricible
{
	class ALight : public AObject
	{
	public:
		ALight(int color, const Point3& pos, float maxDist)
		{
			_position = pos;
			colr._color = color;
			_maxDist = maxDist;
			intensity = 2.f;
		}
		union col
		{
			int	_color;
			unsigned char channels[4];
		};
		col		colr;
		float _maxDist;
		float intensity;
	};
}