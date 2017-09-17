#pragma once

#include <vector>
#include "AObject.hpp"
#include "AIntersectable.hpp"

namespace Tricible
{
	class Scene : public AObject, public AIntersectable
	{
		std::vector<AObject *> Objects;

		// Inherited via AIntersectable
		virtual bool IntersectsRay(const Point3 & origin, const Point3 & vec, IntersectionInfo *interInfo) override;
		virtual void ComputeNormal(const IntersectionInfo & interInfo, Point3 & normal) override;
	};
}
