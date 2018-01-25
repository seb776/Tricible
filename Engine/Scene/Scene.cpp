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
			std::istream *istream = new std::ifstream(filePath);
			
			bool ret = tinyobj::LoadObj(&attrib, &shapes, &materials, &err, istream);

			if (ret)
			{
				// good
			}
			else
			{
				std::cerr << "tinyobj : fail" << std::endl;
			}
			Scene *scene = new Scene();

			for (auto& shape : shapes)
			{

				Mesh *mesh = new Mesh();

				mesh->Name = shape.name;
				size_t index_offset = 0;
				for (size_t f = 0U; f < shape.mesh.num_face_vertices.size(); ++f)
				{
					int fv = shape.mesh.num_face_vertices[f];
					tinyobj::index_t &idx0 = shape.mesh.indices[index_offset + 0]; // v0
					tinyobj::index_t &idx1 = shape.mesh.indices[index_offset + 1]; // v1
					tinyobj::index_t &idx2 = shape.mesh.indices[index_offset + 2]; // v2
					Point3 v0 = Point3(attrib.vertices[3 * idx0.vertex_index + 0], attrib.vertices[3 * idx0.vertex_index + 1], attrib.vertices[3 * idx0.vertex_index + 2]);
					Point3 v1 = Point3(attrib.vertices[3 * idx1.vertex_index + 0], attrib.vertices[3 * idx1.vertex_index + 1], attrib.vertices[3 * idx1.vertex_index + 2]);
					Point3 v2 = Point3(attrib.vertices[3 * idx2.vertex_index + 0], attrib.vertices[3 * idx2.vertex_index + 1], attrib.vertices[3 * idx2.vertex_index + 2]);
					//Point3 n0 = Point3(attrib.normals[3 * idx0.normal_index], attrib.normals[3 * idx0.normal_index + 1], attrib.normals[3 * idx0.normal_index + 2]);
					Triangle *tri = new Triangle(v0, v1, v2);
					//tri->_normal = n0;
					mesh->SubMeshes.push_back(tri);
					index_offset += fv;
				}

				scene->Objects.push_back(mesh);
			}
			delete istream;
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

					if ((nearestDist < 0.f || interDist < nearestDist) && (interDist > CurrentCamera->NearClip && interDist < CurrentCamera->FarClip))
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
			auto &normalDir = interInfo.Intersection - this->_position;

			normalDir.Normalize();
			normal = normalDir;
		}
	}
}
