#pragma once

#include "Plan.hpp"

namespace Tricible
{
	class Triangle : public Plane
	{
	public:
		Point3 _a, _b, _c;

		Triangle(const Point3& a, const Point3& b, const Point3& c)
		{
			_a = a;
			_b = b;
			_c = c;
			_normal = (b - a).Cross(c - a);
			_color = 0xFF00FF00;
			position = a;
		}

		//function SameSide(p1, p2, a, b)
		//	cp1 = CrossProduct(b - a, p1 - a)
		//	cp2 = CrossProduct(b - a, p2 - a)
		//	if DotProduct(cp1, cp2) >= 0 then return true
		//	else return false

		//		function PointInTriangle(p, a, b, c)
		//		if SameSide(p, a, b, c) and SameSide(p, b, a, c)
		//			and SameSide(p, c, a, b) then return true
		//		else return false

		static bool SameSide(const Point3& p1, const Point3& p2, const Point3& a, const Point3& b)
		{
			auto cp1 = (b - a).Cross(p1 - a);
			auto cp2 = (b - a).Cross(p2 - a);
			if (cp1.Dot(cp2) >= 0.f)
				return true;
			return false;
		}
		static bool IsInside(const Point3& a, const Point3& b, const Point3& c, const Point3& point)
		{



			// Compute vectors        
			auto v0 = c - a;
			auto v1 = b - a;
			auto v2 = point - a;

			// Compute dot products
			float	dot00 = v0.Dot(v0);
			float	dot01 = v0.Dot(v1);
			float	dot02 = v0.Dot(v2);
			float	dot11 = v1.Dot(v1);
			float	dot12 = v1.Dot(v2);

			// Compute barycentric coordinates
			float invDenom = 1.f / (dot00 * dot11 - dot01 * dot01);
			float u = (dot11 * dot02 - dot01 * dot12) * invDenom;
			float v = (dot00 * dot12 - dot01 * dot02) * invDenom;

			// Check if point is in triangle
			return (u >= 0.f) && (v >= 0.f) && (u + v < 1.f);

				/*if (SameSide(point, a, b, c) && SameSide(point, b, a, c) && SameSide(point, c, a, b))
					return true;*/
					//Point3 v1 = Point3(b._y)
					//Point3 v2 = (c - b);
					//Point3 v3 = (a - c);

					//Point3 v1a = point - v1;
					//Point3 v2a = point - v2;
					//Point3 v3a = point - v3;

					//float dotA = v1.Dot(v1a);
					//float dotB = v2.Dot(v2a);
					//float dotC = v3.Dot(v3a);
					//return (dotA >= 0.f && dotB >= 0.f && dotC >= 0.f);
		}
		bool IntersectsRay(const Tricible::Point3& origin, const Tricible::Point3& vec, float& dist, int& color) override
		{
			if (this->Plane::IntersectsRay(origin, vec, dist, color))
			{
				Point3 a = origin + (vec * dist);
				//std::cout << a._x << "/" << a._y << "/" << a._z << Triangle::IsInside(_a, _b, _c, origin + (vec * dist)) << std::endl;
				return Triangle::IsInside(_a, _b, _c, origin + (vec * dist));
			}
			return false;
		}
	};
}