#pragma once

#include "vec2.hpp"

class mat2
{
	vec2 matrix[2];
public:
	mat2();
	mat2(float a, float b, float c, float d);
	void InitToIdentity();
	void InitToZero();
	vec2 operator*(const vec2& rhs) const;
};
