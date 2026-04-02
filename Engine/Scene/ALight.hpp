#pragma once

#include "../Tools/Vector3.hpp"

namespace Tricible
{
	class ALight : public AObject
	{
	public:
		ALight(vec3 color, const vec3& pos, float maxDist)
		{
			_position = pos;
			Color = color;
			_maxDist = maxDist;
		}
		vec3 Color;
		float _maxDist;
	};
}