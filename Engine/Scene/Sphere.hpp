//
// Author: Sebastien Maire
// Contribs:
//

#pragma once

#include <iostream>
#include "AObject.hpp"
#include "AIntersectable.hpp"

namespace Tricible
{
	namespace Scene
	{
		class Sphere : public AObject, public AIntersectable
		{
			float radiusSqr;
		public:
			//__declspec(dllexport) Sphere();
			__declspec(dllexport) Sphere();
			__declspec(dllexport) Sphere(int a);
			float radius;

			// Inherited via AIntersectable
			virtual bool IntersectsRay(const Vector3 & origin, const Vector3 & vec, IntersectionInfo *interInfo, float nearClip, float farClip) override;
			virtual void ComputeNormal(const IntersectionInfo & interInfo, Vector3 & normal) override;

			static Vector3 ComputeUV(const Vector3& normal);

			virtual ~Sphere();
		};
	}
}