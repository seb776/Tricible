#pragma once

#include <iostream>
#include <vector>
#include "../Scene/IntersectionInfo.hpp"
#include "../Scene/Sphere.hpp"
#include "../Scene/Plane.hpp"
#include "../Scene/Triangle.hpp"
#include "../Scene/ALight.hpp"
#include "../Scene/Scene.hpp"
#include "../Scene/Camera.hpp"
#include "../Tools/Tools.hpp"

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



		Color::RGB RenderNormalizedVecAsNormal(const Point3& vecToVisualizeAsCol, const IntersectionInfo& interInfo)
		{
			return Color::RGB(static_cast<uint8_t>((vecToVisualizeAsCol._x * 0.5f + 0.5f) * 255.0f), static_cast<uint8_t>((vecToVisualizeAsCol._y * 0.5f + 0.5f) * 255.0f), static_cast<uint8_t>((vecToVisualizeAsCol._z * 0.5f + 0.5f) * 255.0f));
		}

		Color::RGB RenderFloatLessThreshold(float value, float threshold)
		{
			return Color::RGB((value < threshold ? 255U : 0U), 0U, 0U);
		}

		Color::RGB RenderFloatGreaterThreshold(float value, float threshold)
		{
			return Color::RGB((value > threshold ? 255U : 0U), 0U, 0U);
		}

		Color::RGB RenderDepth(float value, float distMax)
		{
			// displays depth
			uint8_t colDist = Clamp((int32_t)(255 * (1.0f - Clamp01(value / distMax))), 0, 255);
			return Color::RGB(colDist, colDist, colDist);
		}

		Color::RGB RenderPixel(const Point3& pixelVec, const IntersectionInfo& interInfo)
		{

			Color::RGB finalColor;
			Color::RGB diffuseColor;

			if (interInfo.Object != nullptr)
			{
				Point3 normal = Point3(1.0, 1.0, 1.0);
				interInfo.Object->ComputeNormal(interInfo, normal);

				// Texture / material lookup
				if (interInfo.Primitive->Material != nullptr)
				{
					diffuseColor = interInfo.Primitive->Material->DiffuseColor;
				}
				else
				{
					diffuseColor = this->Scene->DefaultDiffuseMaterial.DiffuseColor;
				}

				for (ALight *l : Scene->Lights)
				{
					Point3 tmp = (l->getPosition() - interInfo.Intersection);
					tmp.Normalize();
					const float mult = Clamp01(tmp.Dot(normal));
					if (mult > 0.f)
					{
						Color::RGB currentColor = diffuseColor *mult * l->intensity;
						finalColor += currentColor;
					}
				}
			}
			else
			{
				if (Scene->Skymap != nullptr)
				{
					Point3 normVec = pixelVec.Normalize();// .Normalize();
					//pixelVec.Normalize();
					auto uvw = Scene::Sphere::ComputeUV(normVec);
					finalColor = Scene->Skymap->Get360Pixel(uvw._x, uvw._y);
					//finalColor = Scene->Skymap->Get360PixelBilinearInterpolation(uvw._x, uvw._y);
				}
				else
				{
					finalColor = Scene->BackgroundColor;
				}
			}
			return finalColor;
		}

		void Render()
		{
			auto& camera = *Scene->CurrentCamera;
			for (int y = 0; y < _resY; ++y)
			{
				for (int x = 0; x < _resX; ++x)
				{
					Point3 vec;
					camera.GetRay(static_cast<int>(x - (_resX * .5f)), static_cast<int>(y - (_resY * .5f)), vec);
					vec.Normalize();
					Color::RGB finalColor = Color::RGB();
					float nearestDist = -1.f;
					// IntersectionInfo *retainedInter;
					Point3 normVec = vec;
					normVec.Normalize();
					IntersectionInfo interInfo = IntersectionInfo();

					Scene->IntersectsRay(camera.getPosition() + vec, vec, &interInfo, camera.NearClip, camera.FarClip);
					//finalColor = RenderPixel(normVec, interInfo);
					finalColor = RenderDepth(interInfo.Distance, 100.0f);
					image[x + y * _resX] = finalColor.ToInt();
				}
			}
		}
	};
}