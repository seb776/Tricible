#pragma once

#include <vector>
#include "AObject.hpp"
#include "AIntersectable.hpp"
#include "ALight.hpp"
#include "../Scene/Camera.hpp"

namespace Tricible
{
	namespace Scene
	{
		class Mesh : public AObject, public AIntersectable
		{
		public:
			AABB BoundingBox;
			std::vector<AIntersectable *> SubMeshes;
			std::string Name;
			Mesh()
			{

			}

			// Inherited via AIntersectable
			virtual bool IntersectsRay(const Vector3 & origin, const Vector3 & vec, IntersectionInfo * interInfo, float nearClip, float farClip) override;
			virtual void ComputeNormal(const IntersectionInfo & interInfo, Vector3 & normal) override;
			virtual AABB GetAABB() const override;
		};
	}
}