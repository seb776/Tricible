#pragma once

#include "IntersectionInfo.hpp"
#include "../Material/Material.hpp"
#include "AABBB.hpp"

namespace Tricible
{
	class AIntersectable
	{
	public:
		Material::Material *Material;

		AIntersectable();

		virtual AABB GetAABB() const = 0;
		virtual bool IntersectsRay(const vec3& origin, const vec3& vec, IntersectionInfo *interInfo, float nearClip, float farClip) = 0; // TODO const
		virtual void ComputeNormal(const IntersectionInfo& interInfo, vec3& normal) = 0;
	};
}
