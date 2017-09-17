#pragma once

#include "../Point3.hpp"

namespace Tricible
{
	class AIntersectable;

	class IntersectionInfo
	{
	public:
		AIntersectable *Object;
		float Distance;
		Point3 Origin;
		Point3 Direction;
		Point3 Intersection;

		IntersectionInfo() :
			Object(nullptr),
			Distance(0.0f),
			Direction(),
			Origin(),
			Intersection()
		{
		}
	};
}