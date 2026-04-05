#include "Renderer.hpp"
#include "../Scene/Mesh.hpp"
#include "../Scene/Triangle.hpp"
#include <iostream>
#include <glad/gl.h>
using namespace Tricible;

void Renderer::Resize(int resX, int resY)
{
	// TODO
}

void Renderer::UpdateInternalScene()
{
	size_t totalTriangles = 0U;

	if (_objects != nullptr)
		delete _objects;
	if (_triangles != nullptr)
		delete _triangles;

	_objects = new ObjectData[Scene->Objects.size()];
	for (unsigned int i = 0; i < Scene->Objects.size(); ++i)
	{
		Tricible::Scene::Mesh* mesh = static_cast<Tricible::Scene::Mesh*>(Scene->Objects[i]);
		if (mesh != nullptr)
		{
			totalTriangles += mesh->SubMeshes.size();
			_objects[i].TriangleCount = mesh->SubMeshes.size();
			if (i == 0)
				_objects[i].TriangleOffset = 0;
			else
				_objects[i].TriangleOffset = _objects[i -1].TriangleOffset + _objects[i-1].TriangleCount;
		}
		_objects[i].MaterialId = i;
	}

	_objectsCount = Scene->Objects.size();
	_trianglesCount = totalTriangles;
	_triangles = new TriangleData[totalTriangles];
	for (int i = 0; i < _objectsCount; ++i)
	{
		Tricible::Scene::Mesh* mesh = static_cast<Tricible::Scene::Mesh*>(Scene->Objects[i]);
		if (mesh != nullptr)
		{
			for (size_t iOff = 0; iOff < mesh->SubMeshes.size(); iOff++)
			{
				Tricible::Triangle* tri = static_cast<Tricible::Triangle *>(mesh->SubMeshes[iOff]);

				_triangles[_objects[i].TriangleOffset + iOff].A[0] = tri->_a.x();
				_triangles[_objects[i].TriangleOffset + iOff].A[1] = tri->_a.y();
				_triangles[_objects[i].TriangleOffset + iOff].A[2] = tri->_a.z();

				_triangles[_objects[i].TriangleOffset + iOff].B[0] = tri->_b.x();
				_triangles[_objects[i].TriangleOffset + iOff].B[1] = tri->_b.y();
				_triangles[_objects[i].TriangleOffset + iOff].B[2] = tri->_b.z();

				_triangles[_objects[i].TriangleOffset + iOff].C[0] = tri->_c.x();
				_triangles[_objects[i].TriangleOffset + iOff].C[1] = tri->_c.y();
				_triangles[_objects[i].TriangleOffset + iOff].C[2] = tri->_c.z();

			}
		}
	}
}