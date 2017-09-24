#include "IntersectionInfo.hpp"
#include "Triangle.hpp"

using namespace Tricible;

bool Triangle::IntersectsRay(const Point3 & origin, const Point3 & vec, IntersectionInfo * interInfo)
{
	if (this->Plane::IntersectsRay(origin, vec, interInfo))
	{
		interInfo->Intersection = origin + vec * interInfo->Distance;
		//Point3 a = origin + (vec * dist);
		//std::cout << a._x << "/" << a._y << "/" << a._z << Triangle::IsInside(_a, _b, _c, origin + (vec * dist)) << std::endl;
		return Triangle::IsInside(_a, _b, _c, interInfo->Intersection);
	}
	return false;
}

void Triangle::ComputeNormal(const IntersectionInfo & interInfo, Point3 & normal)
{
}
Triangle::Triangle(const Point3& a, const Point3& b, const Point3& c)
{
	_a = a;
	_b = b;
	_c = c;
	_normal = (b - a).Cross(c - a);
	_color = 0xFF00FF00;
	_position = a;
	Material = new Material::Material(Color::RGB(0, 0, 0xFF), Color::RGB());

}
// http://blackpawn.com/texts/pointinpoly/
bool Triangle::IsInside(const Point3& a, const Point3& b, const Point3& c, const Point3& point)
{
	// Compute vectors        
	auto v0 = c - a;
	auto v1 = b - a;
	auto v2 = point - a;

	// Compute dot products
	const float	dot00 = v0.Dot(v0);
	const float	dot01 = v0.Dot(v1);
	const float	dot02 = v0.Dot(v2);
	const float	dot11 = v1.Dot(v1);
	const float	dot12 = v1.Dot(v2);

	// Compute barycentric coordinates
	float invDenom = 1.f / (dot00 * dot11 - dot01 * dot01);
	float u = (dot11 * dot02 - dot01 * dot12) * invDenom;
	float v = (dot00 * dot12 - dot01 * dot02) * invDenom;

	// Check if point is in triangle
	return (u >= 0.f) && (v >= 0.f) && (u + v < 1.f);
}

