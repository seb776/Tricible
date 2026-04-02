#pragma once

#include "../Texture/Texture.hpp"
#include "../GLSLRendererCPP/vec3.hpp"

namespace Tricible
{
	namespace Material
	{

		class Material
		{
		public:
			vec3	DiffuseColor;
			vec3	SpecularColor;
			float		Opacity;
			Texture		*MainTexture;

			Material() : DiffuseColor(), SpecularColor(), Opacity(1.0f), MainTexture(nullptr)
			{

			}

			Material(const vec3& diffuse, const vec3& specular) :
				DiffuseColor(diffuse), 
				SpecularColor(specular), 
				Opacity(1.0f), 
				MainTexture(nullptr)
			{
			}
		};
	}
}