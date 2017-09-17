#include "IntersectionInfo.hpp"
#include "Plane.hpp"

namespace Tricible
{
	// https://en.wikipedia.org/wiki/Line%E2%80%93plane_intersection
	bool Plane::IntersectsRay(const Point3 & origin, const Point3 & vec, IntersectionInfo * interInfo)
	{
		float distL = (position - origin).Dot(_normal) / vec.Dot(_normal);

		if (distL > 0.f)
		{
			interInfo->Distance = distL;
			//color = _color;
			return true;
		}
		return false;
	}

	void Plane::ComputeNormal(const IntersectionInfo & interInfo, Point3 & normal)
	{
		const float res = interInfo.Direction.Dot(_normal);
		if (res <= 0.f)
			normal = _normal.Reverse();
		else
			normal = _normal;
	}
}

