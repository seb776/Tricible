#include "Vector3.hpp"

namespace Tricible
{
	const Vector3 Vector3::x = Vector3(1.0f, 0.0f, 0.0f);
	const Vector3 Vector3::y = Vector3(0.0f, 1.0f, 0.0f);
	const Vector3 Vector3::z = Vector3(0.0f, 0.0f, 1.0f);
	const Vector3 Vector3::forward = Vector3::x;
	const Vector3 Vector3::backward = -Vector3::x;
	const Vector3 Vector3::up = Vector3::y;
	const Vector3 Vector3::down = -Vector3::y;
	const Vector3 Vector3::right = Vector3::z;
	const Vector3 Vector3::left = -Vector3::z;
}
