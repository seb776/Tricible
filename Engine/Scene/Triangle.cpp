#include "IntersectionInfo.hpp"
#include "Triangle.hpp"
#include <limits>
#include <iostream>

using namespace Tricible;

bool Triangle::IntersectsRay(const Point3 & origin, const Point3 & vec, IntersectionInfo * interInfo, float nearClip, float farClip)
{
	//const float EPSILON = 0.0000001;
	//Point3 vertex0 = this->_a;
	//Point3 vertex1 = this->_b;
	//Point3 vertex2 = this->_c;
	//Point3 edge1, edge2, h, s, q;
	//float a, f, u, v;
	//edge1 = vertex1 - vertex0;
	//edge2 = vertex2 - vertex0;
	//h = vec.Cross(edge2);
	//a = edge1.Dot(h);
	//if (a > -EPSILON && a < EPSILON)
	//	return false;
	//f = 1 / a;
	//s = origin - vertex0;
	//u = f * (s.Dot(h));
	//if (u < 0.0 || u > 1.0)
	//	return false;
	//q = s.Cross(edge1);
	//v = f * vec.Dot(q);
	//if (v < 0.0 || u + v > 1.0)
	//	return false;
	//// At this stage we can compute t to find out where the intersection point is on the line.
	//float t = f * edge2.Dot(q);
	//if (t > EPSILON) // ray intersection
	//{
	//	//outIntersectionPoint = origin + vec * t;
	//	interInfo->Primitive = this;
	//	interInfo->Distance = t;
	//	interInfo->Origin = origin;
	//	interInfo->Direction = vec;
	//	interInfo->Intersection = origin + vec * t;
	//	return true;
	//}
	//else // This means that there is a line intersection but not a ray intersection.
	//	return false;
	//return false;

	if (this->Plane::IntersectsRay(origin, vec, interInfo, nearClip, farClip))
	{
		bool res = Triangle::IsInside(_a, _b, _c, interInfo->Intersection);

		if (res)
		{
			interInfo->Primitive = this;
			return true;
		}
		//Point3 a = origin + (vec * dist);
		//st d::cout << a._x << "/" << a._y << "/" << a._z << Triangle::IsInside(_a, _b, _c, origin + (vec * dist)) << std::endl;
	}
	return false;
}

Triangle::Triangle(const Point3& a, const Point3& b, const Point3& c, int iCol) :
	Plane()
{
	_a = a;
	_b = b;
	_c = c;
	_position = a;

	Point3 norm = (b - a).Cross(c - a);
	norm.Normalize();
	_normal = norm;

	Color::RGB colors[] = {
		Color::RGB(0x00, 0x00, 0x00),
		Color::RGB(0x00, 0xFF, 0x00),
		Color::RGB(0x00, 0x00, 0xFF),
		Color::RGB(0xFF, 0x00, 0x00),
		Color::RGB(0x01, 0xFF, 0xFE),
		Color::RGB(0xFF, 0xA6, 0xFE),
		Color::RGB(0xFF, 0xDB, 0x66),
		Color::RGB(0x00, 0x64, 0x01),
		Color::RGB(0x01, 0x00, 0x67),
		Color::RGB(0x95, 0x00, 0x3A),
		Color::RGB(0x00, 0x7D, 0xB5),
		Color::RGB(0xFF, 0x00, 0xF6),
		Color::RGB(0xFF, 0xEE, 0xE8),
		Color::RGB(0x77, 0x4D, 0x00),
		Color::RGB(0x90, 0xFB, 0x92),
		Color::RGB(0x00, 0x76, 0xFF),
		Color::RGB(0xD5, 0xFF, 0x00),
		Color::RGB(0xFF, 0x93, 0x7E),
		Color::RGB(0x6A, 0x82, 0x6C)
	};

	
	Material = new Material::Material(colors[iCol], Color::RGB());
	//std::cout << (uint32_t)Material->DiffuseColor.Red() << ":" << (uint32_t)Material->DiffuseColor.Green() << ":" << (uint32_t)Material->DiffuseColor.Blue() << std::endl;


}
float Sign(float sign)
{
	// TODO easily optimizable
	return (sign < 0.0f ? -1.0f : 1.0f);
}

bool SameSide(Point3 p1, Point3 p2, Point3 A, Point3 B)
{
	Point3 cp1 = (B - A).Cross(p1 - A);
	Point3 cp2 = (B - A).Cross(p2 - A);
	if (cp1.Dot(cp2) >= 0) return true;
	return false;

}

// http://blackpawn.com/texts/pointinpoly/
bool Triangle::IsInside(const Point3& a, const Point3& b, const Point3& c, const Point3& point)
{
	//if (SameSide(point, a, b, c) && SameSide(point, b, a, c) && SameSide(point, c, a, b))
	//{
	//	Point3 vc1 = (a - b).Cross((a - c));
	//	if (fabsf((a - point).Dot(vc1)) <= .01f)
	//		return true;
	//}
	//return false;


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
	float v = (dot11 * dot02 - dot01 * dot12) * invDenom;
	float w = (dot00 * dot12 - dot01 * dot02) * invDenom;
	float u = 1.0f - v - w;
	// Check if point is in triangle
	const float epsilon = std::numeric_limits<float>::epsilon();
	return (u > -epsilon) && (v > -epsilon) && (u + v < 1.f);
}



