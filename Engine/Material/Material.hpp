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
			Vector3	DiffuseColor;
			Vector3	SpecularColor;
			float		Opacity;
			Texture		*MainTexture;

			Material() : DiffuseColor(), SpecularColor(), Opacity(1.0f), MainTexture(nullptr)
			{

			}

			Material(const Vector3& diffuse, const Vector3& specular) :
				DiffuseColor(diffuse), 
				SpecularColor(specular), 
				Opacity(1.0f), 
				MainTexture(nullptr)
			{
			}
		};
	}
}