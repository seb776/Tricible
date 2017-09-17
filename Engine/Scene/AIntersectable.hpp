#pragma once

#include "IntersectionInfo.hpp"

namespace Tricible
{
	class AIntersectable
	{
	public:
		virtual bool IntersectsRay(const Point3& origin, const Point3& vec, IntersectionInfo *interInfo) = 0;
		virtual void ComputeNormal(const IntersectionInfo& interInfo, Point3& normal) = 0;
	};
}
