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
			radius = 10.f;
			radiusSqr = radius * radius;
			_position = Tricible::Point3(55.f, 0.f, 0.f);
			//_color = 0xFF000000; // Red
			_color = 0xFF0000FF;
			Material = new Material::Material(Color::RGB(0, 0xFF, 0), Color::RGB());

		}
		Sphere::Sphere(int a) :
			radius(a), radiusSqr(a * a)
		{
		}

		bool Sphere::IntersectsRay(const Point3 & origin, const Point3 & vec, IntersectionInfo *interInfo, float nearClip, float farClip)
		{
			//Point3 L = _position - origin;
			//float tc = -L.Dot(vec);
			//if (tc < 0.0) return false;

			//float d = sqrt((tc*tc) - (L.LengthSquare()));
			//if (d > radius) return false;

			////solve for t1c
			//float t1c = sqrt((radius *  radius) - (d*d));

			////solve for intersection points
			//float t1 = tc - t1c;
			//float t2 = tc + t1c;

			//bool t1Out = (t1 > farClip || t1 < nearClip);
			//bool t2Out = (t2 > farClip || t2 < nearClip);
			//if (t1Out && t2Out)
			//	return false;
			//if (t1Out)
			//	interInfo->Distance = t2;
			//else
			//	interInfo->Distance = t1;
			//interInfo->Direction = vec;
			//interInfo->Origin = origin;
			//return true;

			Point3 oc = origin - _position;
			float front = -(vec.Dot(oc));
			float underSqrt = powf(vec.Dot(oc), 2.0f) - (oc.Length() * oc.Length()) + radius * radius;
			if (underSqrt < 0.0f)
				return false;

			float dA = front - sqrtf(underSqrt);
			float dB = front + sqrtf(underSqrt);
			bool t1Out = (dA > farClip || dA < nearClip);
			bool t2Out = (dB > farClip || dB < nearClip);
			if (t1Out && t2Out)
				return false;
			if (t1Out)
				interInfo->Distance = dB;
			else
				interInfo->Distance = dA;
			//interInfo->Distance = min(dA, dB);
			interInfo->Direction = vec;
			interInfo->Origin = origin;
			return true;



















			//const Tricible::Point3 oc = (origin - _position);
			//const float b = oc.Dot(vec);
			//const float c = oc.Dot(oc) - radiusSqr;

			//if (c > 0.f && b > 0.f)
			//	return false;
			//const float discr = b * b - c;
			//if (discr < 0.f)
			//	return false;

			//float sqrtDiscr = sqrtf(discr);
			//float solA = -b - sqrtDiscr;
			//float solB = -b + sqrtDiscr;
			//if (solA < 0.0f)
			//	interInfo->Distance = solB;
			//else
			//	interInfo->Distance = max(solA, solB);
			//interInfo->Direction = vec;
			//interInfo->Origin = origin;
			//return true;
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