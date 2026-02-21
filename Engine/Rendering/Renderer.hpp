#pragma once

#include <iostream>
#include <fstream>
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

#include <vector>
#include <thread>
#include <functional>
#include <algorithm>
#include <iostream>
#include <ppl.h>

namespace Tricible
{
	class Renderer
	{
	public:
		int* image;
		int _resX;
		int _resY;
		Scene::Scene* Scene;

	public:
		Renderer(int resX, int resY, int bpp) :
			Scene(nullptr)
		{
			_resX = resX;
			_resY = resY;
			image = new int[resX * resY];
		}

		void GetAvailableHardware()
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
			const auto& exePath = GetCurrentExecutableDirectory();
			const auto& kernalFilePath = PathCombine(exePath, "./Rendering/TestRender.cl.c");
			const auto& kernelSource = ReadFile(kernalFilePath);
			cl::Program program = cl::Program("#define OPENCL_KERNEL_CODE\n" + kernelSource);
			try {
				program.build("-cl-std=CL2.0");
			}
			catch (...) {
				// Print build info for all devices
				cl_int buildErr = CL_SUCCESS;
				auto buildInfo = program.getBuildInfo<CL_PROGRAM_BUILD_LOG>(&buildErr);
				for (auto& pair : buildInfo) {
					std::cerr << pair.second << std::endl << std::endl;
				}
				return;
			}
			// TODO Allocate output buffer
			// https://github.khronos.org/OpenCL-CLHPP/index.html

			//std::vector<int> output(numElements, 0xdeadbeef);
			//cl::Buffer outputBuffer(begin(output), end(output), false);
			//cl::Pipe aPipe(sizeof(cl_int), numElements / 2);

			//// Default command queue, also passed in as a parameter
			//cl::DeviceCommandQueue defaultDeviceQueue = cl::DeviceCommandQueue::makeDefault(
			//	cl::Context::getDefault(), cl::Device::getDefault());

			//typedef struct { int* bar; } SceneExample;

			//// Then pass correct parameters
			//// Prepare call (pass parameters)
			//auto renderKernel =
			//	cl::KernelFunctor<
			//	decltype(fooPointer)&,
			//	int*,
			//	cl::coarse_svm_vector<int>&,
			//	cl::Buffer,
			//	int,
			//	cl::Pipe&,
			//	cl::DeviceCommandQueue
			//	>(program, "Render_Kernel");

			//renderKernel.setSVMPointers(anSVMInt);

			// Executes the kernel
			//cl_int error;
			//renderKernel(
			//	cl::EnqueueArgs(
			//		cl::NDRange(numElements / 2),
			//		cl::NDRange(numElements / 2)),
			//	fooPointer,
			//	inputA.data(),
			//	inputB,
			//	outputBuffer,
			//	3,
			//	aPipe,
			//	defaultDeviceQueue,
			//	error
			//);
			
		}



		Color::RGB RenderNormalizedVecAsNormal(const Vector3& vecToVisualizeAsCol, const IntersectionInfo& interInfo)
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


		Vector3 RenderPixel(const Vector3& pixelVec, const IntersectionInfo& interInfo)
		{
			if (!Scene)
				return Vector3();
			Vector3 finalColor = Vector3(0, 0, 0);
			Vector3 diffuseColor = Vector3(0, 0, 0);

			if (interInfo.Object != nullptr)
			{
				Vector3 normal = Vector3(1.0, 1.0, 1.0);
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

				for (ALight* l : Scene->Lights)
				{
					Vector3 ldir = (l->getPosition() - interInfo.Intersection);
					ldir.Normalize();
					const float LdotN = Clamp01(ldir.Dot(normal));
					if (LdotN > 0.f)
					{
						Vector3 currentColor = diffuseColor * LdotN * l->Color;
						finalColor += currentColor;
					}
				}
			}
			else
			{
				if (Scene->Skymap != nullptr)
				{
					Vector3 normVec = pixelVec.Normalize();
					auto uvw = Scene::Sphere::ComputeUV(normVec);
					finalColor = Scene->Skymap->Get360Pixel(uvw._x, uvw._y);
					//finalColor = Scene->Skymap->Get360PixelBilinearInterpolation(uvw._x, uvw._y);
				}
				else
				{
					finalColor = Scene->BackgroundColor;
				}
			}
			return finalColor + Vector3(42, 42, 42) / 255.0f;
		}

		void Render()
		{
			if (!Scene)
				return;
			auto& camera = *Scene->CurrentCamera;
			//for (int y = 0; y < _resY; ++y)
			concurrency::parallel_for(0, _resY, [&](int y)
				{
					for (int x = 0; x < _resX; ++x)
					{
						Vector3 rayDir;
						camera.GetRay(x - (_resX * .5f), y - (_resY * .5f), rayDir);
						rayDir.Normalize();

						IntersectionInfo interInfo = IntersectionInfo();
						Scene->IntersectsRay(camera.getPosition() + rayDir, rayDir, &interInfo, camera.NearClip, camera.FarClip);

						Vector3 finalColor = RenderPixel(rayDir, interInfo);
						//finalColor = RenderDepth(interInfo.Distance, 100.0f);
						image[x + y * _resX] = finalColor.ToInt();
					}
				});
		}
	};
}