#pragma once

#include "AObject.hpp"

namespace Tricible
{
	class Plane : public AObject, public AIntersectable
	{
	public:
		Plane()
		{
			position._z = -1.f;
			_color = 0xFFFF0000;
			_normal = Point3(0.f, 1.f, 0.f);
		}
		Point3 _normal;
		// https://en.wikipedia.org/wiki/Line%E2%80%93plane_intersection
		bool IntersectsRay(const Tricible::Point3& origin, const Tricible::Point3& vec, float& dist, int& color) override
		{
			float distL = (position - origin).Dot(_normal) / vec.Dot(_normal);

			if (distL > 0.f)
			{
				dist = distL;
				color = _color;
				return true;
			}
			return false;
		}
		void ComputeNormal(const Tricible::Point3& inter, const Tricible::Point3& incident, Tricible::Point3& normal) override
		{
			const float res = incident.Dot(_normal);
			if (res <= 0.f)
				normal = _normal.Reverse();
			else
				normal = _normal;
		}
	};
}