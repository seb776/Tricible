#pragma once

#include "../Tools/Vector3.hpp"

namespace Tricible
{
	class ALight : public AObject
	{
	public:
		ALight(Vector3 color, const Vector3& pos, float maxDist)
		{
			_position = pos;
			Color = color;
			_maxDist = maxDist;
		}
		Vector3 Color;
		float _maxDist;
	};
}