#pragma once

#include "AIntersectable.hpp"
#include "AObject.hpp"

namespace Tricible
{
	class Plane : public AObject, public AIntersectable
	{
	protected:
		Point3 _normal;
	public:
		Plane()
		{
			position._z = -1.f;
			_color = 0xFFFF0000;
			_normal = Point3(0.f, 1.f, 0.f);
		}

		// Inherited via AIntersectable
		__declspec(dllexport) virtual bool IntersectsRay(const Point3 & origin, const Point3 & vec, IntersectionInfo * interInfo) override;
		__declspec(dllexport) virtual void ComputeNormal(const IntersectionInfo & interInfo, Point3 & normal) override;
	};
}