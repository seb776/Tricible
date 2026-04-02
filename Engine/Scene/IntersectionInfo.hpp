#pragma once

#include "../GLSLRendererCPP/vec3.hpp"

namespace Tricible
{
	class AIntersectable;

	class IntersectionInfo
	{
	public:
		AIntersectable *Primitive;
		AIntersectable *Object;
		float Distance;
		vec3 Origin;
		vec3 Direction;
		vec3 Intersection;

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