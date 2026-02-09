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
		class Scene : public AObject, public AIntersectable
		{
		public:
			Texture *Skymap;

			std::vector<AIntersectable *>	Objects;
			std::vector<ALight *>	Lights;
			Camera *CurrentCamera;
			Camera DefaultCamera;
			Material::Material DefaultDiffuseMaterial;
			Vector3 BackgroundColor;

			Scene() :
				AIntersectable(),
				DefaultDiffuseMaterial(Vector3(0U, 255U, 0U)/255.0f, Vector3(30U, 30U, 30U)/255.0f),
				Skymap(nullptr),
				BackgroundColor(Vector3(1.0f, 0.2f, 0.4f)*0.7f)
			{
				CurrentCamera = &DefaultCamera;
			}

			static Scene *LoadFromObj(const std::string& filePath);

			// Inherited via AIntersectable
			virtual bool IntersectsRay(const Vector3 & origin, const Vector3 & vec, IntersectionInfo *interInfo, float nearClip, float farClip) override;
			virtual void ComputeNormal(const IntersectionInfo & interInfo, Vector3 & normal) override;
			virtual AABB GetAABB() const override;
		};
	}
}
