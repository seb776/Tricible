#define GLAD_GL_IMPLEMENTATION
#include <glad/gl.h>
#include "Swizzle.glsl.hpp"
#include "GLSLFunctions.hpp"
#include "SwizzleProxies.hpp"


TRICIBLE_FORCEINLINE vec3 abs(const vec3& a)
{
	return vec3(::abs(a.X_), ::abs(a.Y_), ::abs(a.Z_));
}

template <>
TRICIBLE_FORCEINLINE float clamp<float>(const float& value, const float& min, const float& max)
{
	return ::fmaxf(::fminf(value, max), min);
}
#define _max(a, b) ((a) > (b) ? (a) : (b))
#define _min(a, b) ((a) < (b) ? (a) : (b))
template <>
TRICIBLE_FORCEINLINE unsigned int clamp<unsigned int>(unsigned int const& value, unsigned int const& min_, unsigned int const& max_)
{

	return _max((_min(value, max_)), min_);
}

template <>
TRICIBLE_FORCEINLINE vec2 clamp<vec2>(const vec2& value, const vec2& min, const vec2& max)
{
	return vec2(clamp(value.x(), min.x(), max.x()), clamp(value.y(), min.y(), max.y()));
}

template <>
TRICIBLE_FORCEINLINE vec3 clamp<vec3>(const vec3& value, const vec3& min, const vec3& max)
{
	return vec3(clamp(value.x(), min.x(), max.x()), clamp(value.y(), min.y(), max.y()), clamp(value.z(), min.z(), max.z()));
}

template <>
TRICIBLE_FORCEINLINE vec4 clamp<vec4>(const vec4& value, const vec4& min, const vec4& max)
{
	return vec4(clamp(value.x(), min.x(), max.x()), clamp(value.y(), min.y(), max.y()), clamp(value.z(), min.z(), max.z()), clamp(value.w(), min.w(), max.w()));
}

template <typename T>
float dot(const T& left, const T& right)
{
	return 0.0f;
	// Throw 
}

template<>
TRICIBLE_FORCEINLINE float dot<vec2>(const vec2& left, const vec2& right)
{
	return (left.X_ * right.X_) + (left.Y_ * right.Y_);
}

template<>
TRICIBLE_FORCEINLINE float dot<vec3>(const vec3& left, const vec3& right)
{
	return (left.X_ * right.X_) + (left.Y_ * right.Y_) + (left.Z_ * right.Z_);
}

template<>
TRICIBLE_FORCEINLINE float dot<vec4>(const vec4& left, const vec4& right)
{
	return (left.X_ * right.X_) + (left.Y_ * right.Y_) + (left.Z_ * right.Z_) + (left.W_ * right.W_);
}

float length(vec3 v)
{
	return sqrt(v.x() * v.x() + v.y() * v.y() + v.z() * v.z());
}
vec3 normalize(vec3 v)
{
	float l = length(v);
	return v / l;
}