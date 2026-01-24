#include <fstream>
#include <iostream>
#include "Triangle.hpp"
#include "Scene.hpp"
#include "Mesh.hpp"
#define TINYOBJLOADER_IMPLEMENTATION
#include "../../ext/tiny_obj_loader/tiny_obj_loader.h"

namespace Tricible
{
	namespace Scene
	{
		Scene *Scene::LoadFromObj(const std::string& filePath)
		{
			tinyobj::attrib_t attrib;
			std::vector<tinyobj::shape_t> shapes;
			std::vector<tinyobj::material_t> materials;
			std::string err;
			std::ifstream ifstream = std::ifstream(filePath);

			bool ret = tinyobj::LoadObj(&attrib, &shapes, &materials, &err, &ifstream, nullptr, true);

			if (ret)
			{
				// good
			}
			else
			{
				std::cerr << "tinyobj : fail" << std::endl;
				return nullptr;
			}
			Scene *scene = new Scene();
			int iShape = 0;

			// TODO issue is probably there 
			// Try to match this implementation
			// TODO take attributes (uv, normals...)
			// https://github.com/tinyobjloader/tinyobjloader/blob/release/examples/viewer/viewer.cc
			for (auto& shape : shapes)
			{

				Mesh *mesh = new Mesh();

				mesh->Name = shape.name;
				std::cout << "group" + shape.name << std::endl;
				size_t index_offset = 0;
				for (size_t f = 0U; f < shape.mesh.num_face_vertices.size(); ++f)
				{
					int fv = shape.mesh.num_face_vertices[f];
					if (fv == 3)
					{
						tinyobj::index_t &idx0 = shape.mesh.indices[index_offset + 0]; // v0
						tinyobj::index_t &idx1 = shape.mesh.indices[index_offset + 1]; // v1
						tinyobj::index_t &idx2 = shape.mesh.indices[index_offset + 2]; // v2
						Point3 v0 = Point3(attrib.vertices[3 * idx0.vertex_index + 0], attrib.vertices[3 * idx0.vertex_index + 1], attrib.vertices[3 * idx0.vertex_index + 2]);
						Point3 v1 = Point3(attrib.vertices[3 * idx1.vertex_index + 0], attrib.vertices[3 * idx1.vertex_index + 1], attrib.vertices[3 * idx1.vertex_index + 2]);
						Point3 v2 = Point3(attrib.vertices[3 * idx2.vertex_index + 0], attrib.vertices[3 * idx2.vertex_index + 1], attrib.vertices[3 * idx2.vertex_index + 2]);
						std::cout << "v0=> " << v0._x << ":" << v0._y << ":" << v0._z << std::endl;
						std::cout << "v1=> " << v1._x << ":" << v1._y << ":" << v1._z << std::endl;
						std::cout << "v2=> " << v2._x << ":" << v2._y << ":" << v2._z << std::endl;
						//Point3 n0 = Point3(attrib.normals[3 * idx0.normal_index], attrib.normals[3 * idx0.normal_index + 1], attrib.normals[3 * idx0.normal_index + 2]);
						Triangle *tri = nullptr;
						tri = new Triangle(v0, v1, v2, iShape);
						mesh->SubMeshes.push_back(tri);
						//tri->_normal = n0;
					}
					index_offset += fv;
				}

				scene->Objects.push_back(mesh);
				++iShape;
			}
			return scene;
		}


		bool Scene::IntersectsRay(const Point3 & origin, const Point3 & vec, IntersectionInfo *interInfo, float nearClip, float farClip)
		{
			float nearestDist = -1.0f;
			interInfo->Origin = origin;
			IntersectionInfo retainedInterInfo;

			for (Tricible::AIntersectable *o : Objects)
			{
				IntersectionInfo curInterInfo;

				if (o->IntersectsRay(origin, vec, &curInterInfo, CurrentCamera->NearClip, CurrentCamera->FarClip))
				{
					float interDist = curInterInfo.Distance;

					if ((nearestDist < 0.f || interDist < nearestDist) && 
						(interDist > CurrentCamera->NearClip && interDist < CurrentCamera->FarClip))
					{
						curInterInfo.Object = o;
						retainedInterInfo = curInterInfo;
						nearestDist = interDist;
					}
				}
			}

			retainedInterInfo.Intersection = retainedInterInfo.Origin + retainedInterInfo.Direction * retainedInterInfo.Distance;

			*interInfo = retainedInterInfo;
			return !!interInfo->Object;
		}

		void Scene::ComputeNormal(const IntersectionInfo & interInfo, Point3 & normal)
		{
			if (interInfo.Object != nullptr)
			{
				interInfo.Object->ComputeNormal(interInfo, normal);
			}
		}
	}
}
