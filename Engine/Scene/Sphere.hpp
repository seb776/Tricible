//
// Author: Sebastien Maire
// Contribs:
//

#pragma once

#include <iostream>
#include "AObject.hpp"

namespace Scene
{
	class Sphere : public Tricible::AObject
	{
		float radiusSqr;
	public:
		//__declspec(dllexport) Sphere();
		Sphere()
		{
			radius = 5.f;
			radiusSqr = radius * radius;
			position = Tricible::Point3(55.f, 0.f, 0.f);
			//_color = 0xFF000000; // Red
			_color = 0xFF0000FF;
		}
		__declspec(dllexport) Sphere(int a);
		float radius;
		bool IntersectsRay(const Tricible::Point3& origin, const Tricible::Point3& vec, float& dist, int& color) override
		{
			const Tricible::Point3 oc = (origin - position);
			const float b = oc.Dot(vec);
			const float c = oc.Dot(oc) - radiusSqr;

			if (c > 0.f && b > 0.f)
				return false;
			const float discr = b * b - c;
			if (discr < 0.f)
				return false;

			dist = -b - sqrtf(discr);
			color = _color;
			return true;
		}
		void ComputeNormal(const Tricible::Point3& inter, const Tricible::Point3& incident, Tricible::Point3& normal) override
		{
			normal = position - inter;
			normal = normal / normal.Length();
		}
	};
}