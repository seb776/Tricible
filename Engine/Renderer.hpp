#pragma once

#include <iostream>
#include <vector>
#include "Scene\IntersectionInfo.hpp"
#include "Scene/Sphere.hpp"
#include "Scene/Plane.hpp"
#include "Scene/Triangle.hpp"
#include "Scene/ALight.hpp"
#include "Scene/Scene.hpp"
#include "../Engine/Tools.hpp"
#include "Camera.hpp"

namespace Tricible
{
	class Renderer
	{
	public:
		int *image;
		int _resX;
		int _resY;
		Scene::Scene *Scene;
		/*	std::vector<AIntersectable *>	_objects;
			std::vector<ALight *>	_lights;
			Camera _camera;*/
	public:
		Renderer(int resX, int resY, int bpp, Scene::Scene *scene) :Scene(scene)
		{
			_resX = resX;
			_resY = resY;
			image = new int[resX * resY];
		}

		void Render()
		{
			auto& camera = *Scene->CurrentCamera;
			for (int y = 0; y < _resY; ++y)
			{
				for (int x = 0; x < _resX; ++x)
				{
					Point3 vec;
					camera.GetRay(x - (_resX * .5f), y - (_resY * .5f), vec);
					vec.Normalize();
					Color::RGB finalColor;
					float nearestDist = -1.f;
					// IntersectionInfo *retainedInter;
					IntersectionInfo interInfo;

					if (Scene->IntersectsRay(camera.getPosition() + vec, vec, &interInfo))
					{
						Color::RGB diffuseColor;
						if (interInfo.Object->Material != nullptr)
						{
							diffuseColor = interInfo.Object->Material->DiffuseColor;
						}
						Point3 normal;
						interInfo.Object->ComputeNormal(interInfo, normal);
						for (ALight *l : Scene->Lights)
						{
							Point3 tmp = (l->getPosition() - interInfo.Intersection);
							tmp = tmp / tmp.Length();
							const float mult = tmp.Dot(normal);
							if (mult > 0.f)
							{
								Color::RGB currentColor = diffuseColor *mult * l->intensity;
								finalColor += currentColor;
							}
						}
					}
					image[x + y * _resX] = finalColor.ToInt();
				}
			}
		}
	};
}