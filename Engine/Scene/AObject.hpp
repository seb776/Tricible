#pragma once

#include "../GLSLRendererCPP/vec3.hpp"

namespace Tricible
{
	class AObject
	{
	protected:
		vec3 _position;
	public:
		AObject()
		{
		}
		virtual void AddPosition(const vec3& pos)
		{
			_position += pos;
		}
		TRICIBLE_FORCEINLINE const vec3& getPosition() const
		{
			return this->_position;
		}
	};


}