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
			_position = Tricible::Point3(55.f, 0.f, 0.f);
			//_color = 0xFF000000; // Red
			_color = 0xFF0000FF;
			Material = new Material::Material(Color::RGB(0, 0xFF, 0), Color::RGB());

		}
		Sphere::Sphere(int a)
		{

		}

		bool Sphere::IntersectsRay(const Point3 & origin, const Point3 & vec, IntersectionInfo *interInfo)
		{
			const Tricible::Point3 oc = (origin - _position);
			const float b = oc.Dot(vec);
			const float c = oc.Dot(oc) - radiusSqr;

			if (c > 0.f && b > 0.f)
				return false;
			const float discr = b * b - c;
			if (discr < 0.f)
				return false;
			float sqrtDiscr = sqrtf(discr);
			float solA = -b - sqrtDiscr;
			float solB = -b + sqrtDiscr;
			if (solA < 0.0f)
				interInfo->Distance = solB;
			else
				interInfo->Distance = min(solA, solB);
			interInfo->Direction = vec;
			interInfo->Origin = origin;
			return true;
		}
		void Sphere::ComputeNormal(const IntersectionInfo & interInfo, Point3 & normal)
		{
			normal = _position - interInfo.Intersection;
			normal.Normalize();
			if (interInfo.Direction.Dot(normal) > 0.0f)
				normal = -normal;
		}
	}
}