#include "CPURenderer.hpp"

using namespace Tricible;

CPURenderer::CPURenderer(int resX, int resY) :
	Renderer(resX, resY)
{
	_resX = resX;
	_resY = resY;
	image = new int[resX * resY];
}
void CPURenderer::Resize(int resX, int resY)
{
	Renderer::Resize(resX, resY);
	// TODO ?
}
void CPURenderer::Render()
{
	if (!Scene)
		return;
	auto& camera = *Scene->CurrentCamera;
	//for (int y = 0; y < _resY; ++y)
	concurrency::parallel_for(0, _resY, [&](int y)
		{
			for (int x = 0; x < _resX; ++x)
			{
				auto finalColor = mainShaderCall(vec4(_resX, _resY, 0., 0.));
				image[x + y * _resX] = finalColor;
			}
		});
}
#include <map>
extern std::map<std::string, void*> UniformsMap; // TODO move this ?

void CPURenderer::SetUniformFloat(std::string uniformName, float value)
{
	*static_cast<float*>(UniformsMap[uniformName]) = value;
}
void CPURenderer::SetUniformVector(std::string uniformName, const vec2& value)
{
	*static_cast<vec2*>(UniformsMap[uniformName]) = value;
}
void CPURenderer::SetUniformVector(std::string uniformName, const vec3& value)
{
	*static_cast<vec3*>(UniformsMap[uniformName]) = value;
}
void CPURenderer::SetUniformVector(std::string uniformName, const vec4& value)
{
	*static_cast<vec4*>(UniformsMap[uniformName]) = value;
}