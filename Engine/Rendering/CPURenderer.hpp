#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include "Renderer.hpp"

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


#include "../GLSLRendererCPP/vec4.hpp"

int mainShaderCall(const vec4& gl_FragCoord);

namespace Tricible
{
	class CPURenderer : public Renderer
	{
	public:
		int* image;
		int _resX;
		int _resY;
		Scene::Scene* Scene;

	public:
		CPURenderer(int resX, int resY);

		void SetUniformFloat(std::string uniformName, float value) override;
		void SetUniformVector(std::string uniformName, const vec2& value) override;
		void SetUniformVector(std::string uniformName, const vec3& value) override;
		void SetUniformVector(std::string uniformName, const vec4& value) override;

		void Resize(int resX, int resY) override;
		void Render() override;
	};
}