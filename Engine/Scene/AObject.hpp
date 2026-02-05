#pragma once

#include "../Tools/Vector3.hpp"

namespace Tricible
{
	class AObject
	{
	protected:
		Vector3 _position;
	public:
		AObject()
		{
		}
		virtual void AddPosition(const Vector3& pos)
		{
			_position += pos;
		}
		TRICIBLE_FORCEINLINE const Vector3& getPosition() const
		{
			return this->_position;
		}
	};


}