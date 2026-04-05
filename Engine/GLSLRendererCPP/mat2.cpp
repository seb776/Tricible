#include "mat2.hpp"
#include "vec2.hpp"
#include "GLSLFunctions.hpp"
#include "SwizzleProxies.hpp"

mat2::mat2() 
{
	InitToIdentity();
}
mat2::mat2(float a, float b, float c, float d)
{
	matrix[0].x() = a;
	matrix[0].y() = b;
	matrix[1].x() = c;
	matrix[1].y() = d;
}
void mat2::InitToIdentity()
{
	matrix[0] = vec2(1.0, 0.0);
	matrix[1] = vec2(0.0, 1.0);
}
void mat2::InitToZero()
{
	for (int i = 0; i < 2; ++i)
		matrix[i] = vec2();
}
vec2 mat2::operator*(const vec2& rhs) const
{
	float res[2];
	for (int i = 0; i < 2; ++i)
		res[i] = dot(matrix[i], rhs);
	return vec2(res[0], res[1]);
}