#pragma once

#include "AIntersectable.hpp"
#include "AObject.hpp"

namespace Tricible
{
	class Plane : public AObject, public AIntersectable
	{
	public:
		vec3 _normal;
	public:
		Plane() :
			AIntersectable()
		{
			_position = vec3();
			_normal = vec3(0.f, 1.f, 0.f);
			Material = new Material::Material(vec3(0xFF, 0, 0)/255.0f, vec3());
		}

		// Inherited via AIntersectable
		__declspec(dllexport) virtual bool IntersectsRay(const vec3& origin, const vec3& vec, IntersectionInfo * interInfo, float nearClip, float farClip) override;
		__declspec(dllexport) virtual void ComputeNormal(const IntersectionInfo & interInfo, vec3& normal) override;
		virtual AABB GetAABB() const override;
	};
}