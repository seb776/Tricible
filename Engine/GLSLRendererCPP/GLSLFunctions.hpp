#pragma once

// void bool int uint float 
#include "Scalars.hpp"

// vec2 vec3 vec4 bvec2 bvec3 bvec4 ivec2 ivec3 ivec4 uvec2 uvec3 uvec4 
#include "vec2.hpp"
#include "vec3.hpp"
#include "vec4.hpp"

#include "ivec2.hpp"
#include "ivec3.hpp"
#include "ivec4.hpp"

#include "uvec2.hpp"
#include "uvec3.hpp"
#include "uvec4.hpp"

#include "bvec2.hpp"
#include "bvec3.hpp"
#include "bvec4.hpp"

// Double & dvecX dmatX ? not super supported will see in the future

// mat2 mat3 mat4 
#include "mat2.hpp"
#include "mat3.hpp"
#include "mat4.hpp"

// (mat2x2) mat2x3 mat2x4 mat3x2 (mat3x3) mat3x3 mat4x2 mat4x3 (mat4x4)
// sampler2D, sampler3D, samplerCube



//reflect
//refract
//normalize
//distance
//length
//
//sin
//cos
//tan
//asin
//acos
//atan
//pow
//exp
//log
//abs
//sign
//floor
//ceil
//trunc
//round
//fract
//mod
//min
//max
//clamp
//step
//smoothstep
//
//cross
//dot
//
//all
//any
//not
//
//textures

template <typename T>
float dot(const T& left, const T& right);

template <typename T>
T clamp(const T& value, const T& min, const T& max);

TRICIBLE_FORCEINLINE vec3 cross(const vec3& lhs, const vec3& rhs);

template <typename T>
TRICIBLE_FORCEINLINE float lengthSquare(const T& vec);
template <typename T>
TRICIBLE_FORCEINLINE float length(const T& vec);

template<typename T>
struct is_allowed_type :
    std::disjunction<
    std::is_same<T, vec2>,
    std::is_same<T, vec3>,
    std::is_same<T, vec4>
    > {};

//template<typename T>
//using is_allowed_type_t = typename is_allowed_type<T>::type;
//
//template <typename T, std::enable_if<is_allowed_type_t<T>::value, int> = 0>
//TRICIBLE_FORCEINLINE T normalize(const T& vec);
//
//template <typename T>
//TRICIBLE_FORCEINLINE T abs(const T& a);
