#pragma once

#include "../Texture/Texture.hpp"
#include "../Color/RGB.hpp"

namespace Tricible
{
	namespace Material
	{

		class Material
		{
		public:
			Color::RGB	DiffuseColor;
			Color::RGB	SpecularColor;
			float		Opacity;
			Texture		*MainTexture;

			Material() : DiffuseColor(), SpecularColor(), Opacity(1.0f), MainTexture(nullptr)
			{

			}

			Material(const Color::RGB& diffuse, const Color::RGB& specular) : 
				DiffuseColor(diffuse), 
				SpecularColor(specular), 
				Opacity(1.0f), 
				MainTexture(nullptr)
			{

			}
		};
	}
}