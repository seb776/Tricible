#pragma once

#include "../Tools/Point3.hpp"

namespace Tricible
{
	class AObject
	{
	protected:
		Point3 _position;
	public:
		AObject()
		{
		}
		virtual void AddPosition(const Point3& pos)
		{
			_position += pos;
		}
		TRICIBLE_FORCEINLINE const Point3& getPosition() const
		{
			return this->_position;
		}
	};


}