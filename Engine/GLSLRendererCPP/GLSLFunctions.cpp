#include "Swizzle.hpp"
#include "GLSLFunctions.hpp"

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
TRICIBLE_FORCEINLINE vec3 abs(const vec3& a)
{
	return vec3(::abs(a.X_), ::abs(a.Y_), ::abs(a.Z_));
}


template <>
TRICIBLE_FORCEINLINE float clamp(const float& value, const float& min, const float& max)
{
	return ::fmaxf(::fminf(value, min), max);
}

template <>
TRICIBLE_FORCEINLINE vec2 clamp(const vec2& value, const vec2& min, const vec2& max)
{
	return vec2(clamp(value.x(), min.x(), max.x()), clamp(value.y(), min.y(), max.y()));
}

template <>
TRICIBLE_FORCEINLINE vec3 clamp(const vec3& value, const vec3& min, const vec3& max)
{
	return vec3(clamp(value.x(), min.x(), max.x()), clamp(value.y(), min.y(), max.y()), clamp(value.z(), min.z(), max.z()));
}

template <>
TRICIBLE_FORCEINLINE vec4 clamp(const vec4& value, const vec4& min, const vec4& max)
{
	return vec4(clamp(value.x(), min.x(), max.x()), clamp(value.y(), min.y(), max.y()), clamp(value.z(), min.z(), max.z()), clamp(value.w(), min.w(), max.w()));
}