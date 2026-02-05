#pragma once

#include "../Tools/Vector3.hpp"

namespace Tricible
{
	class AIntersectable;

	class IntersectionInfo
	{
	public:
		AIntersectable *Primitive;
		AIntersectable *Object;
		float Distance;
		Vector3 Origin;
		Vector3 Direction;
		Vector3 Intersection;

		IntersectionInfo() :
			Object(nullptr),
			Distance(0.0f),
			Direction(),
			Origin(),
			Intersection(),
			Primitive(nullptr)
		{
		}
	};
}