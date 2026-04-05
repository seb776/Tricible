#pragma once

#include <math.h>

class vec3;

class mat3
{
public:
	vec3 matrix[3];
	mat3();
	// TODO add missing ctors vec2 vec2, vec2 float float...
	void InitToIdentity();
	void InitToZero();
	vec3 operator*(const vec3& rhs) const;

	// https://fr.wikipedia.org/wiki/Matrice_de_rotation
	void SetRotationX(float roll);
	void SetRotationY(float pitch);
	void SetRotationZ(float yaw);
};