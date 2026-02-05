#pragma once

#include "IntersectionInfo.hpp"
#include "../Material/Material.hpp"

namespace Tricible
{
	class AIntersectable
	{
	public:
		Material::Material *Material;

		AIntersectable();

		virtual bool IntersectsRay(const Vector3& origin, const Vector3& vec, IntersectionInfo *interInfo, float nearClip, float farClip) = 0;
		virtual void ComputeNormal(const IntersectionInfo& interInfo, Vector3& normal) = 0;
	};
}
