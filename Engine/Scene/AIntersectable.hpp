#pragma once

#include "IntersectionInfo.hpp"
#include "../Material/Material.hpp"

namespace Tricible
{
	class AIntersectable
	{
	public:
		Material::Material *Material;

		virtual bool IntersectsRay(const Point3& origin, const Point3& vec, IntersectionInfo *interInfo) = 0;
		virtual void ComputeNormal(const IntersectionInfo& interInfo, Point3& normal) = 0;
	};
}
