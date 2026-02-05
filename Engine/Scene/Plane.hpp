#pragma once

#include "AIntersectable.hpp"
#include "AObject.hpp"

namespace Tricible
{
	class Plane : public AObject, public AIntersectable
	{
	public:
		Vector3 _normal;
	public:
		Plane() :
			AIntersectable()
		{
			_position = Vector3();
			_normal = Vector3(0.f, 1.f, 0.f);
			Material = new Material::Material(Color::RGB(0xFF, 0, 0), Color::RGB());
		}

		// Inherited via AIntersectable
		__declspec(dllexport) virtual bool IntersectsRay(const Vector3 & origin, const Vector3 & vec, IntersectionInfo * interInfo, float nearClip, float farClip) override;
		__declspec(dllexport) virtual void ComputeNormal(const IntersectionInfo & interInfo, Vector3 & normal) override;
	};
}