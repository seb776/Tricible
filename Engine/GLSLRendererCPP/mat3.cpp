#include "vec3.hpp"
#include "mat3.hpp"
#include "GLSLFunctions.hpp"

mat3::mat3()
{
	InitToIdentity();
}
void mat3::InitToIdentity()
{
	matrix[0] = vec3(1.0, 0.0, 0.0);
	matrix[1] = vec3(0.0, 1.0, 0.0);
	matrix[2] = vec3(0.0, 0.0, 1.0);
}
void mat3::InitToZero()
{
	for (int i = 0; i < 3; ++i)
		matrix[i] = vec3();
}

vec3 mat3::operator*(const vec3& rhs) const
{
	float res[3];
	for (int i = 0; i < 3; ++i)
		res[i] = dot(matrix[i], rhs);
	return vec3(res[0], res[1], res[2]);
}

// https://fr.wikipedia.org/wiki/Matrice_de_rotation
void mat3::SetRotationX(float roll)
{
	InitToZero();
	matrix[0]._x = 1.f;
	matrix[1]._y = matrix[2]._z = cosf(roll);
	matrix[2]._y = matrix[1]._z = sinf(roll);
	matrix[1]._z *= -1.f;
}
void mat3::SetRotationY(float pitch)
{
	mat3::InitToZero();
	matrix[0]._x = matrix[2]._z = cosf(pitch);
	matrix[1]._y = 1.f;
	matrix[2]._x = matrix[0]._z = sinf(pitch);
	matrix[2]._x *= -1.f;
}

void mat3::SetRotationZ(float yaw)
{
	InitToZero();
	matrix[0]._x = matrix[1]._y = cosf(yaw);
	matrix[1]._x = matrix[0]._y = sinf(yaw);
	matrix[2]._z = 1.f;
	matrix[0]._y *= -1.f;
}