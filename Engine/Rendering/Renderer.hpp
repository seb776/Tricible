#pragma once

#include "../Scene/Scene.hpp"
#include "../GLSLRendererCPP/vec2.hpp"
#include "../GLSLRendererCPP/vec3.hpp"
#include "../GLSLRendererCPP/vec4.hpp"

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
		Renderer(int resX, int resY) :
			Scene(nullptr)
		{
			_resX = resX;
			_resY = resY;
			image = new int[resX * resY];
		}

		virtual void SetUniformFloat(std::string uniformName, float value) = 0;
		virtual void SetUniformVector(std::string uniformName, const vec2& value) = 0;
		virtual void SetUniformVector(std::string uniformName, const vec3& value) = 0;
		virtual void SetUniformVector(std::string uniformName, const vec4& value) = 0;

		virtual void Resize(int resX, int resY);
		virtual void Render() = 0;
	};
}