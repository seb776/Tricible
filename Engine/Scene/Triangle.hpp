#pragma once

#include "Plane.hpp"

namespace Tricible
{
	class Triangle : public Plane
	{
	protected:
		Vector3 _a, _b, _c;

	public:
		__declspec(dllexport) Triangle(const Vector3& a, const Vector3& b, const Vector3& c, int iCol);

		__declspec(dllexport) static bool IsInside(const Vector3& a, const Vector3& b, const Vector3& c, const Vector3& point);

		// Inherited via AIntersectable
		__declspec(dllexport) virtual bool IntersectsRay(const Vector3 & origin, const Vector3 & vec, IntersectionInfo * interInfo, float nearClip, float farClip) override;
		virtual AABB GetAABB() const override;
	};
}