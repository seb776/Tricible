//
// Author: Sebastien Maire
// Contribs:
//

#include <stdio.h>
#include "Sphere.hpp"
#include "IntersectionInfo.hpp"

namespace Tricible
{
	namespace Scene
	{
		Sphere::Sphere()
		{
			radius = 5.f;
			radiusSqr = radius * radius;
			position = Tricible::Point3(55.f, 0.f, 0.f);
			//_color = 0xFF000000; // Red
			_color = 0xFF0000FF;
		}
		Sphere::Sphere(int a)
		{

		}

		bool Sphere::IntersectsRay(const Point3 & origin, const Point3 & vec, IntersectionInfo *interInfo)
		{
			const Tricible::Point3 oc = (origin - position);
			const float b = oc.Dot(vec);
			const float c = oc.Dot(oc) - radiusSqr;

			if (c > 0.f && b > 0.f)
				return false;
			const float discr = b * b - c;
			if (discr < 0.f)
				return false;

			interInfo->Distance = -b - sqrtf(discr);
			//color = _color;
			return true;
		}
		void Sphere::ComputeNormal(const IntersectionInfo & interInfo, Point3 & normal)
		{
			normal = position - interInfo.Intersection;
			normal.Normalize();
		}
	}
}