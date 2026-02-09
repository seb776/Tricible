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
		virtual bool IntersectsRay(const Vector3& origin, const Vector3& vec, IntersectionInfo *interInfo, float nearClip, float farClip) = 0; // TODO const
		virtual void ComputeNormal(const IntersectionInfo& interInfo, Vector3& normal) = 0;
	};
}
