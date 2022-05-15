#pragma once

#include <iostream>
#include <vector>
#include <CL/cl2.hpp>
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

		void GetAvaialableHardware()
		{
			std::vector<cl::Platform> platforms;
			cl::Platform::get(&platforms);

			int platform_id = 0;
			int device_id = 0;

			std::cout << "Number of Platforms: " << platforms.size() << std::endl;

			for (std::vector<cl::Platform>::iterator it = platforms.begin(); it != platforms.end(); ++it) {
				cl::Platform platform(*it);

				std::cout << "Platform ID: " << platform_id++ << std::endl;
				std::cout << "Platform Name: " << platform.getInfo<CL_PLATFORM_NAME>() << std::endl;
				std::cout << "Platform Vendor: " << platform.getInfo<CL_PLATFORM_VENDOR>() << std::endl;

				std::vector<cl::Device> devices;
				platform.getDevices(CL_DEVICE_TYPE_GPU | CL_DEVICE_TYPE_CPU, &devices);

				for (std::vector<cl::Device>::iterator it2 = devices.begin(); it2 != devices.end(); ++it2) {
					cl::Device device(*it2);

					std::cout << "\tDevice " << device_id++ << ": " << std::endl;
					std::cout << "\t\tDevice Name: " << device.getInfo<CL_DEVICE_NAME>() << std::endl;
					std::cout << "\t\tDevice Type: " << device.getInfo<CL_DEVICE_TYPE>();
					std::cout << " (GPU: " << CL_DEVICE_TYPE_GPU << ", CPU: " << CL_DEVICE_TYPE_CPU << ")" << std::endl;
					std::cout << "\t\tDevice Vendor: " << device.getInfo<CL_DEVICE_VENDOR>() << std::endl;
					std::cout << "\t\tDevice Max Compute Units: " << device.getInfo<CL_DEVICE_MAX_COMPUTE_UNITS>() << std::endl;
					std::cout << "\t\tDevice Global Memory: " << device.getInfo<CL_DEVICE_GLOBAL_MEM_SIZE>() << std::endl;
					std::cout << "\t\tDevice Max Clock Frequency: " << device.getInfo<CL_DEVICE_MAX_CLOCK_FREQUENCY>() << std::endl;
					std::cout << "\t\tDevice Max Allocateable Memory: " << device.getInfo<CL_DEVICE_MAX_MEM_ALLOC_SIZE>() << std::endl;
					std::cout << "\t\tDevice Local Memory: " << device.getInfo<CL_DEVICE_LOCAL_MEM_SIZE>() << std::endl;
					std::cout << "\t\tDevice Available: " << device.getInfo< CL_DEVICE_AVAILABLE>() << std::endl;
				}
				std::cout << std::endl;
			}
		}



		Color::RGB RenderNormalizedVecAsNormal(const Point3& vecToVisualizeAsCol, const IntersectionInfo& interInfo)
		{
			return Color::RGB((vecToVisualizeAsCol._x * 0.5f + 0.5f) * 255.0f, (vecToVisualizeAsCol._y * 0.5f + 0.5f) * 255.0f, (vecToVisualizeAsCol._z * 0.5f + 0.5f) * 255.0f);
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
					Point3 normVec = pixelVec.Normalize();
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
					camera.GetRay(x - (_resX * .5f), y - (_resY * .5f), vec);
					vec.Normalize();
					Color::RGB finalColor = Color::RGB();
					float nearestDist = -1.f;
					// IntersectionInfo *retainedInter;
					Point3 normVec = vec;
					normVec.Normalize();
					IntersectionInfo interInfo = IntersectionInfo();

					Scene->IntersectsRay(camera.getPosition() + vec, vec, &interInfo, camera.NearClip, camera.FarClip);
					finalColor = RenderPixel(normVec, interInfo);
					//finalColor = RenderDepth(interInfo.Distance, 100.0f);
					image[x + y * _resX] = finalColor.ToInt();
				}
			}
		}
	};
}