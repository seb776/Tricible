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
		Sphere::Sphere() :
			Sphere(10)
		{

			//Material = new Material::Material(Color::RGB(0, 0xFF, 0), Color::RGB());

		}
		Sphere::Sphere(int a) :
			radius(a), radiusSqr(a * a)
		{
			_position = Tricible::Point3(55.f, 0.f, 0.f);
			this->Material = nullptr;
		}

		bool Sphere::IntersectsRay(const Point3 & origin, const Point3 & vec, IntersectionInfo *interInfo, float nearClip, float farClip)
		{
			Point3 oc = origin - _position;
			float ocl = oc.Length();
			//oc.Normalize();
			float frontDot = vec.Dot(oc);
			float front = -frontDot;
			float underSqrt = POW2(frontDot) - POW2(ocl) + radiusSqr;
			if (underSqrt < 0.0f)
				return false;

			float intersectionDist = sqrtf(underSqrt);
			float dA = front - intersectionDist;
			float dB = front + intersectionDist;
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
		}

		Point3 Sphere::ComputeUV(const Point3& normal)
		{
			Point3 uvw((atan2f(normal._x, normal._z) + M_PI) / M_PI2, (asinf(normal._y) / M_PI_2) * 0.5f + 0.5f, 0.0f);
			
			return uvw;
		}

		void Sphere::ComputeNormal(const IntersectionInfo & interInfo, Point3 & normal)
		{
			normal = _position - interInfo.Intersection;
			normal.Normalize();
			if (interInfo.Direction.Dot(normal) > 0.0f)
				normal = -normal;
		}

		Sphere::~Sphere()
		{
			if (Material != nullptr)
			{
				delete Material;
			}
		}
	}
}