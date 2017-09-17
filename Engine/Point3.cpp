#include "Point3.hpp"

namespace Tricible
{
	const Point3 Point3::x = Point3(1.0f, 0.0f, 0.0f);
	const Point3 Point3::y = Point3(0.0f, 1.0f, 0.0f);
	const Point3 Point3::z = Point3(0.0f, 0.0f, 1.0f);
	const Point3 Point3::forward = Point3::x;
	const Point3 Point3::backward = -Point3::x;
	const Point3 Point3::up = Point3::y;
	const Point3 Point3::down = -Point3::y;
	const Point3 Point3::right = Point3::z;
	const Point3 Point3::left = -Point3::z;
}
