#pragma once

#include "Plane.hpp"

namespace Tricible
{
	class Triangle : public Plane
	{
	protected:
		Point3 _a, _b, _c;

	public:
		__declspec(dllexport) Triangle(const Point3& a, const Point3& b, const Point3& c);

		__declspec(dllexport) static bool IsInside(const Point3& a, const Point3& b, const Point3& c, const Point3& point);

		// Inherited via AIntersectable
		__declspec(dllexport) virtual bool IntersectsRay(const Point3 & origin, const Point3 & vec, IntersectionInfo * interInfo, float nearClip, float farClip) override;
	};
}