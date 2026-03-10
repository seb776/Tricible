#pragma once

/*
** Swizzle Proxies for vec / ivec / uvec / bvec
** 
** - swizzle1 / 2 / 3 / 4 let you do GLSL - style things like :
** v.x() = 1.0f;
** v.xy() = vec2(1, 2);
** v.xyz() += vec3(0.1f, 0.2f, 0.3f);
** 
** -Const functions return by - value(read - only).
** - Non - const functions return a proxy that stores a reference to the vector,
** so assignments update the original components directly.
** 
** - No heap, no static temps, safeand fast.
*/
#pragma once


class vec2;
class vec3;
class vec4;

// =====================================================
// swizzle1
// =====================================================
template<typename VecType, typename ScalarType, int A>
struct swizzle1
{
    using self = swizzle1<VecType, ScalarType, A>;
    VecType* vec;

    TRICIBLE_FORCEINLINE swizzle1(VecType& v);

    TRICIBLE_FORCEINLINE operator ScalarType() const;

    TRICIBLE_FORCEINLINE self& operator=(const ScalarType& rhs);
    TRICIBLE_FORCEINLINE self& operator+=(const ScalarType& rhs);
    TRICIBLE_FORCEINLINE self& operator-=(const ScalarType& rhs);
    TRICIBLE_FORCEINLINE self& operator*=(const ScalarType& rhs);
    TRICIBLE_FORCEINLINE self& operator/=(const ScalarType& rhs);
};

// =====================================================
// swizzle2
// =====================================================
template<typename VecType, typename ScalarType, int A, int B>
struct swizzle2
{
    using self = swizzle2<VecType, ScalarType, A, B>;
    VecType* vec;

    TRICIBLE_FORCEINLINE swizzle2(VecType& v);

    TRICIBLE_FORCEINLINE operator vec2() const;

    TRICIBLE_FORCEINLINE self& operator=(const vec2& rhs);
    TRICIBLE_FORCEINLINE self& operator+=(const vec2& rhs);
    TRICIBLE_FORCEINLINE self& operator-=(const vec2& rhs);
};

// =====================================================
// swizzle3
// =====================================================
template<typename VecType, typename ScalarType, int A, int B, int C>
struct swizzle3
{
    using self = swizzle3<VecType, ScalarType, A, B, C>;
    VecType* vec;

    TRICIBLE_FORCEINLINE swizzle3(VecType& v);

    TRICIBLE_FORCEINLINE operator vec3() const;

    TRICIBLE_FORCEINLINE self& operator=(const vec3& rhs);
    TRICIBLE_FORCEINLINE self& operator+=(const vec3& rhs);
    TRICIBLE_FORCEINLINE self& operator-=(const vec3& rhs);
};

// =====================================================
// swizzle4
// =====================================================
template<typename VecType, typename ScalarType, int A, int B, int C, int D>
struct swizzle4
{
    using self = swizzle4<VecType, ScalarType, A, B, C, D>;
    VecType* vec;

    TRICIBLE_FORCEINLINE swizzle4(VecType& v);

    TRICIBLE_FORCEINLINE operator vec4() const;

    TRICIBLE_FORCEINLINE self& operator=(const vec4& rhs);
    TRICIBLE_FORCEINLINE self& operator+=(const vec4& rhs);
    TRICIBLE_FORCEINLINE self& operator-=(const vec4& rhs);
};