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
			virtual bool IntersectsRay(const Point3 & origin, const Point3 & vec, IntersectionInfo *interInfo, float nearClip, float farClip) override;
			virtual void ComputeNormal(const IntersectionInfo & interInfo, Point3 & normal) override;
		};
	}
}