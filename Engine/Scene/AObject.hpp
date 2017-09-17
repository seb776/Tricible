#pragma once

#include "../Point3.hpp"

namespace Tricible
{
	class AObject
	{
	protected:
		Point3 position;
		int _color;
	public:
		AObject()
		{
		}
		virtual void AddPosition(const Point3& pos)
		{
			position += pos;
		}
		TRICIBLE_FORCEINLINE const Point3& getPosition() const
		{
			return this->position;
		}
	};


}