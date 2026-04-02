#pragma once

#include "Plane.hpp"

namespace Tricible
{
	class Triangle : public Plane
	{
	protected:
		vec3 _a, _b, _c;

	public:
		__declspec(dllexport) Triangle(const vec3& a, const vec3& b, const vec3& c, int iCol);

		__declspec(dllexport) static bool IsInside(const vec3& a, const vec3& b, const vec3& c, const vec3& point);

		// Inherited via AIntersectable
		__declspec(dllexport) virtual bool IntersectsRay(const vec3& origin, const vec3& vec, IntersectionInfo * interInfo, float nearClip, float farClip) override;
		virtual AABB GetAABB() const override;
	};
}