#pragma once

#include <vector>
#include "AObject.hpp"

namespace Tricible
{
	class IntersectionInfo
	{
		AObject *Object;
		float Distance;
	};
	class Scene : public AObject, public AIntersectable
	{
		std::vector<AObject *> Objects;

		bool IntersectsRays(AObject *interObj, const Point3 & origin, const Point3 & vec, float & dist)
		{

		}

		// Inherited via AIntersectable
		virtual bool IntersectsRay(const Point3 & origin, const Point3 & vec, float & dist, int & color) override
		{

		}
		virtual void ComputeNormal(const Point3 & inter, const Point3 & incident, Point3 & normal) override
		{

		}
	};
}
