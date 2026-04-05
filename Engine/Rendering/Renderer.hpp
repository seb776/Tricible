#pragma once

#include "../Scene/Scene.hpp"
#include "../GLSLRendererCPP/vec2.hpp"
#include "../GLSLRendererCPP/vec3.hpp"
#include "../GLSLRendererCPP/vec4.hpp"

struct TriangleData
{
	float A[4];
	float B[4];
	float C[4];
	// TODO normals + attributes
};
struct ObjectData
{
	unsigned int MaterialId;
	unsigned int TriangleOffset; // index into the triangle buffer
	unsigned int TriangleCount;
	unsigned int _pad;
};

namespace Tricible
{
	class Renderer
	{
	public:
		int* image;
		int _resX;
		int _resY;
		Scene::Scene *Scene;
		TriangleData *_triangles;
		size_t _trianglesCount;
		ObjectData *_objects;
		size_t _objectsCount;

	public:
		Renderer(int resX, int resY) :
			Scene(nullptr), _objects(nullptr), _triangles(nullptr)
		{
			_resX = resX;
			_resY = resY;
			image = new int[resX * resY];
		}

		virtual void UpdateInternalScene();

		virtual void SetUniformFloat(std::string uniformName, float value) = 0;
		virtual void SetUniformVector(std::string uniformName, const vec2& value) = 0;
		virtual void SetUniformVector(std::string uniformName, const vec3& value) = 0;
		virtual void SetUniformVector(std::string uniformName, const vec4& value) = 0;

		virtual void Resize(int resX, int resY);
		virtual void Render() = 0;
	};
}