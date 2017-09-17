#pragma once

#include <iostream>
#include <vector>
#include "Scene\IntersectionInfo.hpp"
#include "Scene/Sphere.hpp"
#include "Scene/Plane.hpp"
#include "Scene/Triangle.hpp"
#include "Scene/ALight.hpp"
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
		std::vector<AIntersectable *>	_objects;
		std::vector<ALight *>	_lights;
		Camera _camera;
	public:
		Renderer(int resX, int resY, int bpp)
		{
			_resX = resX;
			_resY = resY;
			image = new int[resX * resY];
			_objects.push_back((Tricible::AIntersectable *)new Scene::Sphere());
			_objects.push_back((Tricible::AIntersectable *)new Plane());
			_objects.push_back((Tricible::AIntersectable *)new Triangle(Point3(25.f, 0.f, 0.f), Point3(25.f, 0.f,5.f), Point3(25.f, 2.5f, 2.5f)));
			_lights.push_back(new ALight(0xFF424242, Point3(0.f, 25.f, 0.f), 150.f));
			//_lights.push_back(new ALight(0xFFFF00FF, Point3(50.f, 0.f, 75.f), 150.f));
		}

		void Render()
		{
			for (int y = 0; y < _resY; ++y)
			{
				for (int x = 0; x < _resX; ++x)
				{
					Point3 vec;
					_camera.GetRay(x - (_resX * .5f), y - (_resY * .5f), vec);
					vec.Normalize();
					int retainedColor = 0xFF000000;
					float dist = -1.f;
					AIntersectable *prim = nullptr;
					IntersectionInfo interInfo;


					for (Tricible::AIntersectable *o : _objects)
					{
						float itDist = 0.f;
						int color = 0;
						if (o->IntersectsRay(_camera.getPosition() + vec, vec, &interInfo))
						{
							if (itDist > _camera.NearClip && itDist < _camera.FarClip)
							{
								if (dist < 0.f || itDist < dist)
								{
									retainedColor = color;
									dist = itDist;
									prim = o;
								}
							}
						}
					}
					if (prim)
					{
						Point3 normal;
						prim->ComputeNormal(interInfo, normal);
						for (ALight *l : _lights)
						{
							Point3 tmp = (interInfo.Intersection - l->getPosition());
							tmp = tmp / tmp.Length();
							float mult = tmp.Dot(normal);
							if (mult < 0.f)
								mult = 0.f;
							mult *= l->intensity;
							unsigned char r = retainedColor & 0xFF;
							unsigned char g = (retainedColor >> 8) & 0xFF;
							unsigned char b = (retainedColor >> 16) & 0xFF;
							//std::cout << l->colr.channels[1] << "/" << l->colr.channels[2] << "/" << l->colr.channels[3] << std::endl;
							r = (unsigned char)(min((float)r * mult * (float)l->colr.channels[1] / 255.f, 255.f));
							g = (unsigned char)(min((float)g * mult * (float)l->colr.channels[2] / 255.f, 255.f));
							b = (unsigned char)(min((float)b * mult * (float)l->colr.channels[3] / 255.f, 255.f));
							for (AIntersectable *o : _objects) if (false)
							{
								Point3 ray = (l->getPosition() - interInfo.Intersection);
								IntersectionInfo interInfoShadow;
								//ray = ray / ray.Length();
								float dist = 0;
								int col = 0;
								if (o != prim && o->IntersectsRay(interInfo.Intersection, ray, &interInfoShadow))
								{
									r = (unsigned char)((float)r / 2.f);
									g = (unsigned char)((float)g / 2.f);
									b = (unsigned char)((float)b / 2.f);
									break;
								}
							}
							retainedColor = 0xFF000000 + r + (g << 8) + (b << 16);
						}
					}
					image[x + y * _resX] = retainedColor;

				}
			}
		}
	};
}