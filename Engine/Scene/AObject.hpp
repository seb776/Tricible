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

	};

	class AIntersectable
	{
	public:
		virtual bool IntersectsRay(const Point3& origin, const Point3& vec, float& dist, int& color) = 0;
		virtual void ComputeNormal(const Point3& inter, const Point3& incident, Point3& normal) = 0;
	};
}