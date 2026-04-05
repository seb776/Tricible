#pragma once

#include <string>
#include "../Tools/Macros.hpp"
class vec2;
class vec3;

template<typename VecType, typename ScalarType, int A>
struct swizzle1;
template<typename VecType, typename ScalarType, int A, int B>
struct swizzle2;
template<typename VecType, typename ScalarType, int A, int B, int C>
struct swizzle3;
template<typename VecType, typename ScalarType, int A, int B, int C, int D>
struct swizzle4;

class vec4
{
public:
	float _x;
	float _y;
	float _z;
	float _w;


public:
	vec4();
	vec4(const vec4& rhs);
	vec4(const vec2& a, const vec2& b);
	vec4(const vec2& a, float z_, float w_);
	vec4(float x_, const vec2& a, float w_);
	vec4(float x_, float y_, const vec2& a);
	vec4(float x_, const vec3& a);
	vec4(const vec3& a, float w_);
	explicit vec4(float x_, float y_, float z_, float w_);
	explicit vec4(float x_);

	// ------------------------------
// Array-style access (non-const)
// ------------------------------
	float& operator[](int i)
	{
		// Optional: assert index is in range
		// assert(i >= 0 && i < 4);
		return *(&_x + i);
	}

	// ------------------------------
	// Array-style access (const)
	// ------------------------------
	const float& operator[](int i) const
	{
		// assert(i >= 0 && i < 4);
		return *(&_x + i);
	}

	TRICIBLE_FORCEINLINE vec4 operator-() const;
	TRICIBLE_FORCEINLINE vec4 operator+(const vec4& rhs) const;
	TRICIBLE_FORCEINLINE vec4 operator-(const vec4& rhs) const;
	TRICIBLE_FORCEINLINE vec4 operator*(const vec4& rhs) const;
	TRICIBLE_FORCEINLINE vec4 operator*(const float rhs) const;
	TRICIBLE_FORCEINLINE vec4 operator/(const vec4& rhs) const;
	TRICIBLE_FORCEINLINE vec4 operator/(const float rhs) const;

	TRICIBLE_FORCEINLINE vec4 operator=(const vec4& rhs);

	TRICIBLE_FORCEINLINE vec4 operator+=(const vec4& rhs);
	TRICIBLE_FORCEINLINE vec4 operator-=(const vec4& rhs);
	TRICIBLE_FORCEINLINE vec4 operator*=(const vec4& rhs);
	TRICIBLE_FORCEINLINE vec4 operator/=(const vec4& rhs);
	TRICIBLE_FORCEINLINE vec4 operator*=(const float rhs);
	TRICIBLE_FORCEINLINE vec4 operator/=(const float rhs);

	TRICIBLE_FORCEINLINE std::string ToString() const;
	unsigned int ToInt();

	// vec4 with 1 components.
	TRICIBLE_FORCEINLINE float x() const; // readonly
	TRICIBLE_FORCEINLINE swizzle1<vec4, float, 0> x(); // Assignable
	TRICIBLE_FORCEINLINE float y() const; // readonly
	TRICIBLE_FORCEINLINE swizzle1<vec4, float, 1> y(); // Assignable
	TRICIBLE_FORCEINLINE float z() const; // readonly
	TRICIBLE_FORCEINLINE swizzle1<vec4, float, 2> z(); // Assignable
	TRICIBLE_FORCEINLINE float w() const; // readonly
	TRICIBLE_FORCEINLINE swizzle1<vec4, float, 3> w(); // Assignable

	// vec4 with 2 components.
	TRICIBLE_FORCEINLINE vec2 xx() const; // readonly
	TRICIBLE_FORCEINLINE vec2 yx() const; // readonly
	TRICIBLE_FORCEINLINE swizzle2<vec4, float, 1, 0> yx(); // Assignable
	TRICIBLE_FORCEINLINE vec2 zx() const; // readonly
	TRICIBLE_FORCEINLINE swizzle2<vec4, float, 2, 0> zx(); // Assignable
	TRICIBLE_FORCEINLINE vec2 wx() const; // readonly
	TRICIBLE_FORCEINLINE swizzle2<vec4, float, 3, 0> wx(); // Assignable
	TRICIBLE_FORCEINLINE vec2 xy() const; // readonly
	TRICIBLE_FORCEINLINE swizzle2<vec4, float, 0, 1> xy(); // Assignable
	TRICIBLE_FORCEINLINE vec2 yy() const; // readonly
	TRICIBLE_FORCEINLINE vec2 zy() const; // readonly
	TRICIBLE_FORCEINLINE swizzle2<vec4, float, 2, 1> zy(); // Assignable
	TRICIBLE_FORCEINLINE vec2 wy() const; // readonly
	TRICIBLE_FORCEINLINE swizzle2<vec4, float, 3, 1> wy(); // Assignable
	TRICIBLE_FORCEINLINE vec2 xz() const; // readonly
	TRICIBLE_FORCEINLINE swizzle2<vec4, float, 0, 2> xz(); // Assignable
	TRICIBLE_FORCEINLINE vec2 yz() const; // readonly
	TRICIBLE_FORCEINLINE swizzle2<vec4, float, 1, 2> yz(); // Assignable
	TRICIBLE_FORCEINLINE vec2 zz() const; // readonly
	TRICIBLE_FORCEINLINE vec2 wz() const; // readonly
	TRICIBLE_FORCEINLINE swizzle2<vec4, float, 3, 2> wz(); // Assignable
	TRICIBLE_FORCEINLINE vec2 xw() const; // readonly
	TRICIBLE_FORCEINLINE swizzle2<vec4, float, 0, 3> xw(); // Assignable
	TRICIBLE_FORCEINLINE vec2 yw() const; // readonly
	TRICIBLE_FORCEINLINE swizzle2<vec4, float, 1, 3> yw(); // Assignable
	TRICIBLE_FORCEINLINE vec2 zw() const; // readonly
	TRICIBLE_FORCEINLINE swizzle2<vec4, float, 2, 3> zw(); // Assignable
	TRICIBLE_FORCEINLINE vec2 ww() const; // readonly

	// vec4 with 3 components.
	TRICIBLE_FORCEINLINE vec3 xxx() const; // readonly
	TRICIBLE_FORCEINLINE vec3 yxx() const; // readonly
	TRICIBLE_FORCEINLINE vec3 zxx() const; // readonly
	TRICIBLE_FORCEINLINE vec3 wxx() const; // readonly
	TRICIBLE_FORCEINLINE vec3 xyx() const; // readonly
	TRICIBLE_FORCEINLINE vec3 yyx() const; // readonly
	TRICIBLE_FORCEINLINE vec3 zyx() const; // readonly
	TRICIBLE_FORCEINLINE swizzle3<vec4, float, 2, 1, 0> zyx(); // Assignable
	TRICIBLE_FORCEINLINE vec3 wyx() const; // readonly
	TRICIBLE_FORCEINLINE swizzle3<vec4, float, 3, 1, 0> wyx(); // Assignable
	TRICIBLE_FORCEINLINE vec3 xzx() const; // readonly
	TRICIBLE_FORCEINLINE vec3 yzx() const; // readonly
	TRICIBLE_FORCEINLINE swizzle3<vec4, float, 1, 2, 0> yzx(); // Assignable
	TRICIBLE_FORCEINLINE vec3 zzx() const; // readonly
	TRICIBLE_FORCEINLINE vec3 wzx() const; // readonly
	TRICIBLE_FORCEINLINE swizzle3<vec4, float, 3, 2, 0> wzx(); // Assignable
	TRICIBLE_FORCEINLINE vec3 xwx() const; // readonly
	TRICIBLE_FORCEINLINE vec3 ywx() const; // readonly
	TRICIBLE_FORCEINLINE swizzle3<vec4, float, 1, 3, 0> ywx(); // Assignable
	TRICIBLE_FORCEINLINE vec3 zwx() const; // readonly
	TRICIBLE_FORCEINLINE swizzle3<vec4, float, 2, 3, 0> zwx(); // Assignable
	TRICIBLE_FORCEINLINE vec3 wwx() const; // readonly
	TRICIBLE_FORCEINLINE vec3 xxy() const; // readonly
	TRICIBLE_FORCEINLINE vec3 yxy() const; // readonly
	TRICIBLE_FORCEINLINE vec3 zxy() const; // readonly
	TRICIBLE_FORCEINLINE swizzle3<vec4, float, 2, 0, 1> zxy(); // Assignable
	TRICIBLE_FORCEINLINE vec3 wxy() const; // readonly
	TRICIBLE_FORCEINLINE swizzle3<vec4, float, 3, 0, 1> wxy(); // Assignable
	TRICIBLE_FORCEINLINE vec3 xyy() const; // readonly
	TRICIBLE_FORCEINLINE vec3 yyy() const; // readonly
	TRICIBLE_FORCEINLINE vec3 zyy() const; // readonly
	TRICIBLE_FORCEINLINE vec3 wyy() const; // readonly
	TRICIBLE_FORCEINLINE vec3 xzy() const; // readonly
	TRICIBLE_FORCEINLINE swizzle3<vec4, float, 0, 2, 1> xzy(); // Assignable
	TRICIBLE_FORCEINLINE vec3 yzy() const; // readonly
	TRICIBLE_FORCEINLINE vec3 zzy() const; // readonly
	TRICIBLE_FORCEINLINE vec3 wzy() const; // readonly
	TRICIBLE_FORCEINLINE swizzle3<vec4, float, 3, 2, 1> wzy(); // Assignable
	TRICIBLE_FORCEINLINE vec3 xwy() const; // readonly
	TRICIBLE_FORCEINLINE swizzle3<vec4, float, 0, 3, 1> xwy(); // Assignable
	TRICIBLE_FORCEINLINE vec3 ywy() const; // readonly
	TRICIBLE_FORCEINLINE vec3 zwy() const; // readonly
	TRICIBLE_FORCEINLINE swizzle3<vec4, float, 2, 3, 1> zwy(); // Assignable
	TRICIBLE_FORCEINLINE vec3 wwy() const; // readonly
	TRICIBLE_FORCEINLINE vec3 xxz() const; // readonly
	TRICIBLE_FORCEINLINE vec3 yxz() const; // readonly
	TRICIBLE_FORCEINLINE swizzle3<vec4, float, 1, 0, 2> yxz(); // Assignable
	TRICIBLE_FORCEINLINE vec3 zxz() const; // readonly
	TRICIBLE_FORCEINLINE vec3 wxz() const; // readonly
	TRICIBLE_FORCEINLINE swizzle3<vec4, float, 3, 0, 2> wxz(); // Assignable
	TRICIBLE_FORCEINLINE vec3 xyz() const; // readonly
	TRICIBLE_FORCEINLINE swizzle3<vec4, float, 0, 1, 2> xyz(); // Assignable
	TRICIBLE_FORCEINLINE vec3 yyz() const; // readonly
	TRICIBLE_FORCEINLINE vec3 zyz() const; // readonly
	TRICIBLE_FORCEINLINE vec3 wyz() const; // readonly
	TRICIBLE_FORCEINLINE swizzle3<vec4, float, 3, 1, 2> wyz(); // Assignable
	TRICIBLE_FORCEINLINE vec3 xzz() const; // readonly
	TRICIBLE_FORCEINLINE vec3 yzz() const; // readonly
	TRICIBLE_FORCEINLINE vec3 zzz() const; // readonly
	TRICIBLE_FORCEINLINE vec3 wzz() const; // readonly
	TRICIBLE_FORCEINLINE vec3 xwz() const; // readonly
	TRICIBLE_FORCEINLINE swizzle3<vec4, float, 0, 3, 2> xwz(); // Assignable
	TRICIBLE_FORCEINLINE vec3 ywz() const; // readonly
	TRICIBLE_FORCEINLINE swizzle3<vec4, float, 1, 3, 2> ywz(); // Assignable
	TRICIBLE_FORCEINLINE vec3 zwz() const; // readonly
	TRICIBLE_FORCEINLINE vec3 wwz() const; // readonly
	TRICIBLE_FORCEINLINE vec3 xxw() const; // readonly
	TRICIBLE_FORCEINLINE vec3 yxw() const; // readonly
	TRICIBLE_FORCEINLINE swizzle3<vec4, float, 1, 0, 3> yxw(); // Assignable
	TRICIBLE_FORCEINLINE vec3 zxw() const; // readonly
	TRICIBLE_FORCEINLINE swizzle3<vec4, float, 2, 0, 3> zxw(); // Assignable
	TRICIBLE_FORCEINLINE vec3 wxw() const; // readonly
	TRICIBLE_FORCEINLINE vec3 xyw() const; // readonly
	TRICIBLE_FORCEINLINE swizzle3<vec4, float, 0, 1, 3> xyw(); // Assignable
	TRICIBLE_FORCEINLINE vec3 yyw() const; // readonly
	TRICIBLE_FORCEINLINE vec3 zyw() const; // readonly
	TRICIBLE_FORCEINLINE swizzle3<vec4, float, 2, 1, 3> zyw(); // Assignable
	TRICIBLE_FORCEINLINE vec3 wyw() const; // readonly
	TRICIBLE_FORCEINLINE vec3 xzw() const; // readonly
	TRICIBLE_FORCEINLINE swizzle3<vec4, float, 0, 2, 3> xzw(); // Assignable
	TRICIBLE_FORCEINLINE vec3 yzw() const; // readonly
	TRICIBLE_FORCEINLINE swizzle3<vec4, float, 1, 2, 3> yzw(); // Assignable
	TRICIBLE_FORCEINLINE vec3 zzw() const; // readonly
	TRICIBLE_FORCEINLINE vec3 wzw() const; // readonly
	TRICIBLE_FORCEINLINE vec3 xww() const; // readonly
	TRICIBLE_FORCEINLINE vec3 yww() const; // readonly
	TRICIBLE_FORCEINLINE vec3 zww() const; // readonly
	TRICIBLE_FORCEINLINE vec3 www() const; // readonly

	// vec4 with 4 components.
	TRICIBLE_FORCEINLINE vec4 xxxx() const; // readonly
	TRICIBLE_FORCEINLINE vec4 yxxx() const; // readonly
	TRICIBLE_FORCEINLINE vec4 zxxx() const; // readonly
	TRICIBLE_FORCEINLINE vec4 wxxx() const; // readonly
	TRICIBLE_FORCEINLINE vec4 xyxx() const; // readonly
	TRICIBLE_FORCEINLINE vec4 yyxx() const; // readonly
	TRICIBLE_FORCEINLINE vec4 zyxx() const; // readonly
	TRICIBLE_FORCEINLINE vec4 wyxx() const; // readonly
	TRICIBLE_FORCEINLINE vec4 xzxx() const; // readonly
	TRICIBLE_FORCEINLINE vec4 yzxx() const; // readonly
	TRICIBLE_FORCEINLINE vec4 zzxx() const; // readonly
	TRICIBLE_FORCEINLINE vec4 wzxx() const; // readonly
	TRICIBLE_FORCEINLINE vec4 xwxx() const; // readonly
	TRICIBLE_FORCEINLINE vec4 ywxx() const; // readonly
	TRICIBLE_FORCEINLINE vec4 zwxx() const; // readonly
	TRICIBLE_FORCEINLINE vec4 wwxx() const; // readonly
	TRICIBLE_FORCEINLINE vec4 xxyx() const; // readonly
	TRICIBLE_FORCEINLINE vec4 yxyx() const; // readonly
	TRICIBLE_FORCEINLINE vec4 zxyx() const; // readonly
	TRICIBLE_FORCEINLINE vec4 wxyx() const; // readonly
	TRICIBLE_FORCEINLINE vec4 xyyx() const; // readonly
	TRICIBLE_FORCEINLINE vec4 yyyx() const; // readonly
	TRICIBLE_FORCEINLINE vec4 zyyx() const; // readonly
	TRICIBLE_FORCEINLINE vec4 wyyx() const; // readonly
	TRICIBLE_FORCEINLINE vec4 xzyx() const; // readonly
	TRICIBLE_FORCEINLINE vec4 yzyx() const; // readonly
	TRICIBLE_FORCEINLINE vec4 zzyx() const; // readonly
	TRICIBLE_FORCEINLINE vec4 wzyx() const; // readonly
	TRICIBLE_FORCEINLINE swizzle4<vec4, float, 3, 2, 1, 0> wzyx(); // Assignable
	TRICIBLE_FORCEINLINE vec4 xwyx() const; // readonly
	TRICIBLE_FORCEINLINE vec4 ywyx() const; // readonly
	TRICIBLE_FORCEINLINE vec4 zwyx() const; // readonly
	TRICIBLE_FORCEINLINE swizzle4<vec4, float, 2, 3, 1, 0> zwyx(); // Assignable
	TRICIBLE_FORCEINLINE vec4 wwyx() const; // readonly
	TRICIBLE_FORCEINLINE vec4 xxzx() const; // readonly
	TRICIBLE_FORCEINLINE vec4 yxzx() const; // readonly
	TRICIBLE_FORCEINLINE vec4 zxzx() const; // readonly
	TRICIBLE_FORCEINLINE vec4 wxzx() const; // readonly
	TRICIBLE_FORCEINLINE vec4 xyzx() const; // readonly
	TRICIBLE_FORCEINLINE vec4 yyzx() const; // readonly
	TRICIBLE_FORCEINLINE vec4 zyzx() const; // readonly
	TRICIBLE_FORCEINLINE vec4 wyzx() const; // readonly
	TRICIBLE_FORCEINLINE swizzle4<vec4, float, 3, 1, 2, 0> wyzx(); // Assignable
	TRICIBLE_FORCEINLINE vec4 xzzx() const; // readonly
	TRICIBLE_FORCEINLINE vec4 yzzx() const; // readonly
	TRICIBLE_FORCEINLINE vec4 zzzx() const; // readonly
	TRICIBLE_FORCEINLINE vec4 wzzx() const; // readonly
	TRICIBLE_FORCEINLINE vec4 xwzx() const; // readonly
	TRICIBLE_FORCEINLINE vec4 ywzx() const; // readonly
	TRICIBLE_FORCEINLINE swizzle4<vec4, float, 1, 3, 2, 0> ywzx(); // Assignable
	TRICIBLE_FORCEINLINE vec4 zwzx() const; // readonly
	TRICIBLE_FORCEINLINE vec4 wwzx() const; // readonly
	TRICIBLE_FORCEINLINE vec4 xxwx() const; // readonly
	TRICIBLE_FORCEINLINE vec4 yxwx() const; // readonly
	TRICIBLE_FORCEINLINE vec4 zxwx() const; // readonly
	TRICIBLE_FORCEINLINE vec4 wxwx() const; // readonly
	TRICIBLE_FORCEINLINE vec4 xywx() const; // readonly
	TRICIBLE_FORCEINLINE vec4 yywx() const; // readonly
	TRICIBLE_FORCEINLINE vec4 zywx() const; // readonly
	TRICIBLE_FORCEINLINE swizzle4<vec4, float, 2, 1, 3, 0> zywx(); // Assignable
	TRICIBLE_FORCEINLINE vec4 wywx() const; // readonly
	TRICIBLE_FORCEINLINE vec4 xzwx() const; // readonly
	TRICIBLE_FORCEINLINE vec4 yzwx() const; // readonly
	TRICIBLE_FORCEINLINE swizzle4<vec4, float, 1, 2, 3, 0> yzwx(); // Assignable
	TRICIBLE_FORCEINLINE vec4 zzwx() const; // readonly
	TRICIBLE_FORCEINLINE vec4 wzwx() const; // readonly
	TRICIBLE_FORCEINLINE vec4 xwwx() const; // readonly
	TRICIBLE_FORCEINLINE vec4 ywwx() const; // readonly
	TRICIBLE_FORCEINLINE vec4 zwwx() const; // readonly
	TRICIBLE_FORCEINLINE vec4 wwwx() const; // readonly
	TRICIBLE_FORCEINLINE vec4 xxxy() const; // readonly
	TRICIBLE_FORCEINLINE vec4 yxxy() const; // readonly
	TRICIBLE_FORCEINLINE vec4 zxxy() const; // readonly
	TRICIBLE_FORCEINLINE vec4 wxxy() const; // readonly
	TRICIBLE_FORCEINLINE vec4 xyxy() const; // readonly
	TRICIBLE_FORCEINLINE vec4 yyxy() const; // readonly
	TRICIBLE_FORCEINLINE vec4 zyxy() const; // readonly
	TRICIBLE_FORCEINLINE vec4 wyxy() const; // readonly
	TRICIBLE_FORCEINLINE vec4 xzxy() const; // readonly
	TRICIBLE_FORCEINLINE vec4 yzxy() const; // readonly
	TRICIBLE_FORCEINLINE vec4 zzxy() const; // readonly
	TRICIBLE_FORCEINLINE vec4 wzxy() const; // readonly
	TRICIBLE_FORCEINLINE swizzle4<vec4, float, 3, 2, 0, 1> wzxy(); // Assignable
	TRICIBLE_FORCEINLINE vec4 xwxy() const; // readonly
	TRICIBLE_FORCEINLINE vec4 ywxy() const; // readonly
	TRICIBLE_FORCEINLINE vec4 zwxy() const; // readonly
	TRICIBLE_FORCEINLINE swizzle4<vec4, float, 2, 3, 0, 1> zwxy(); // Assignable
	TRICIBLE_FORCEINLINE vec4 wwxy() const; // readonly
	TRICIBLE_FORCEINLINE vec4 xxyy() const; // readonly
	TRICIBLE_FORCEINLINE vec4 yxyy() const; // readonly
	TRICIBLE_FORCEINLINE vec4 zxyy() const; // readonly
	TRICIBLE_FORCEINLINE vec4 wxyy() const; // readonly
	TRICIBLE_FORCEINLINE vec4 xyyy() const; // readonly
	TRICIBLE_FORCEINLINE vec4 yyyy() const; // readonly
	TRICIBLE_FORCEINLINE vec4 zyyy() const; // readonly
	TRICIBLE_FORCEINLINE vec4 wyyy() const; // readonly
	TRICIBLE_FORCEINLINE vec4 xzyy() const; // readonly
	TRICIBLE_FORCEINLINE vec4 yzyy() const; // readonly
	TRICIBLE_FORCEINLINE vec4 zzyy() const; // readonly
	TRICIBLE_FORCEINLINE vec4 wzyy() const; // readonly
	TRICIBLE_FORCEINLINE vec4 xwyy() const; // readonly
	TRICIBLE_FORCEINLINE vec4 ywyy() const; // readonly
	TRICIBLE_FORCEINLINE vec4 zwyy() const; // readonly
	TRICIBLE_FORCEINLINE vec4 wwyy() const; // readonly
	TRICIBLE_FORCEINLINE vec4 xxzy() const; // readonly
	TRICIBLE_FORCEINLINE vec4 yxzy() const; // readonly
	TRICIBLE_FORCEINLINE vec4 zxzy() const; // readonly
	TRICIBLE_FORCEINLINE vec4 wxzy() const; // readonly
	TRICIBLE_FORCEINLINE swizzle4<vec4, float, 3, 0, 2, 1> wxzy(); // Assignable
	TRICIBLE_FORCEINLINE vec4 xyzy() const; // readonly
	TRICIBLE_FORCEINLINE vec4 yyzy() const; // readonly
	TRICIBLE_FORCEINLINE vec4 zyzy() const; // readonly
	TRICIBLE_FORCEINLINE vec4 wyzy() const; // readonly
	TRICIBLE_FORCEINLINE vec4 xzzy() const; // readonly
	TRICIBLE_FORCEINLINE vec4 yzzy() const; // readonly
	TRICIBLE_FORCEINLINE vec4 zzzy() const; // readonly
	TRICIBLE_FORCEINLINE vec4 wzzy() const; // readonly
	TRICIBLE_FORCEINLINE vec4 xwzy() const; // readonly
	TRICIBLE_FORCEINLINE swizzle4<vec4, float, 0, 3, 2, 1> xwzy(); // Assignable
	TRICIBLE_FORCEINLINE vec4 ywzy() const; // readonly
	TRICIBLE_FORCEINLINE vec4 zwzy() const; // readonly
	TRICIBLE_FORCEINLINE vec4 wwzy() const; // readonly
	TRICIBLE_FORCEINLINE vec4 xxwy() const; // readonly
	TRICIBLE_FORCEINLINE vec4 yxwy() const; // readonly
	TRICIBLE_FORCEINLINE vec4 zxwy() const; // readonly
	TRICIBLE_FORCEINLINE swizzle4<vec4, float, 2, 0, 3, 1> zxwy(); // Assignable
	TRICIBLE_FORCEINLINE vec4 wxwy() const; // readonly
	TRICIBLE_FORCEINLINE vec4 xywy() const; // readonly
	TRICIBLE_FORCEINLINE vec4 yywy() const; // readonly
	TRICIBLE_FORCEINLINE vec4 zywy() const; // readonly
	TRICIBLE_FORCEINLINE vec4 wywy() const; // readonly
	TRICIBLE_FORCEINLINE vec4 xzwy() const; // readonly
	TRICIBLE_FORCEINLINE swizzle4<vec4, float, 0, 2, 3, 1> xzwy(); // Assignable
	TRICIBLE_FORCEINLINE vec4 yzwy() const; // readonly
	TRICIBLE_FORCEINLINE vec4 zzwy() const; // readonly
	TRICIBLE_FORCEINLINE vec4 wzwy() const; // readonly
	TRICIBLE_FORCEINLINE vec4 xwwy() const; // readonly
	TRICIBLE_FORCEINLINE vec4 ywwy() const; // readonly
	TRICIBLE_FORCEINLINE vec4 zwwy() const; // readonly
	TRICIBLE_FORCEINLINE vec4 wwwy() const; // readonly
	TRICIBLE_FORCEINLINE vec4 xxxz() const; // readonly
	TRICIBLE_FORCEINLINE vec4 yxxz() const; // readonly
	TRICIBLE_FORCEINLINE vec4 zxxz() const; // readonly
	TRICIBLE_FORCEINLINE vec4 wxxz() const; // readonly
	TRICIBLE_FORCEINLINE vec4 xyxz() const; // readonly
	TRICIBLE_FORCEINLINE vec4 yyxz() const; // readonly
	TRICIBLE_FORCEINLINE vec4 zyxz() const; // readonly
	TRICIBLE_FORCEINLINE vec4 wyxz() const; // readonly
	TRICIBLE_FORCEINLINE swizzle4<vec4, float, 3, 1, 0, 2> wyxz(); // Assignable
	TRICIBLE_FORCEINLINE vec4 xzxz() const; // readonly
	TRICIBLE_FORCEINLINE vec4 yzxz() const; // readonly
	TRICIBLE_FORCEINLINE vec4 zzxz() const; // readonly
	TRICIBLE_FORCEINLINE vec4 wzxz() const; // readonly
	TRICIBLE_FORCEINLINE vec4 xwxz() const; // readonly
	TRICIBLE_FORCEINLINE vec4 ywxz() const; // readonly
	TRICIBLE_FORCEINLINE swizzle4<vec4, float, 1, 3, 0, 2> ywxz(); // Assignable
	TRICIBLE_FORCEINLINE vec4 zwxz() const; // readonly
	TRICIBLE_FORCEINLINE vec4 wwxz() const; // readonly
	TRICIBLE_FORCEINLINE vec4 xxyz() const; // readonly
	TRICIBLE_FORCEINLINE vec4 yxyz() const; // readonly
	TRICIBLE_FORCEINLINE vec4 zxyz() const; // readonly
	TRICIBLE_FORCEINLINE vec4 wxyz() const; // readonly
	TRICIBLE_FORCEINLINE swizzle4<vec4, float, 3, 0, 1, 2> wxyz(); // Assignable
	TRICIBLE_FORCEINLINE vec4 xyyz() const; // readonly
	TRICIBLE_FORCEINLINE vec4 yyyz() const; // readonly
	TRICIBLE_FORCEINLINE vec4 zyyz() const; // readonly
	TRICIBLE_FORCEINLINE vec4 wyyz() const; // readonly
	TRICIBLE_FORCEINLINE vec4 xzyz() const; // readonly
	TRICIBLE_FORCEINLINE vec4 yzyz() const; // readonly
	TRICIBLE_FORCEINLINE vec4 zzyz() const; // readonly
	TRICIBLE_FORCEINLINE vec4 wzyz() const; // readonly
	TRICIBLE_FORCEINLINE vec4 xwyz() const; // readonly
	TRICIBLE_FORCEINLINE swizzle4<vec4, float, 0, 3, 1, 2> xwyz(); // Assignable
	TRICIBLE_FORCEINLINE vec4 ywyz() const; // readonly
	TRICIBLE_FORCEINLINE vec4 zwyz() const; // readonly
	TRICIBLE_FORCEINLINE vec4 wwyz() const; // readonly
	TRICIBLE_FORCEINLINE vec4 xxzz() const; // readonly
	TRICIBLE_FORCEINLINE vec4 yxzz() const; // readonly
	TRICIBLE_FORCEINLINE vec4 zxzz() const; // readonly
	TRICIBLE_FORCEINLINE vec4 wxzz() const; // readonly
	TRICIBLE_FORCEINLINE vec4 xyzz() const; // readonly
	TRICIBLE_FORCEINLINE vec4 yyzz() const; // readonly
	TRICIBLE_FORCEINLINE vec4 zyzz() const; // readonly
	TRICIBLE_FORCEINLINE vec4 wyzz() const; // readonly
	TRICIBLE_FORCEINLINE vec4 xzzz() const; // readonly
	TRICIBLE_FORCEINLINE vec4 yzzz() const; // readonly
	TRICIBLE_FORCEINLINE vec4 zzzz() const; // readonly
	TRICIBLE_FORCEINLINE vec4 wzzz() const; // readonly
	TRICIBLE_FORCEINLINE vec4 xwzz() const; // readonly
	TRICIBLE_FORCEINLINE vec4 ywzz() const; // readonly
	TRICIBLE_FORCEINLINE vec4 zwzz() const; // readonly
	TRICIBLE_FORCEINLINE vec4 wwzz() const; // readonly
	TRICIBLE_FORCEINLINE vec4 xxwz() const; // readonly
	TRICIBLE_FORCEINLINE vec4 yxwz() const; // readonly
	TRICIBLE_FORCEINLINE swizzle4<vec4, float, 1, 0, 3, 2> yxwz(); // Assignable
	TRICIBLE_FORCEINLINE vec4 zxwz() const; // readonly
	TRICIBLE_FORCEINLINE vec4 wxwz() const; // readonly
	TRICIBLE_FORCEINLINE vec4 xywz() const; // readonly
	TRICIBLE_FORCEINLINE swizzle4<vec4, float, 0, 1, 3, 2> xywz(); // Assignable
	TRICIBLE_FORCEINLINE vec4 yywz() const; // readonly
	TRICIBLE_FORCEINLINE vec4 zywz() const; // readonly
	TRICIBLE_FORCEINLINE vec4 wywz() const; // readonly
	TRICIBLE_FORCEINLINE vec4 xzwz() const; // readonly
	TRICIBLE_FORCEINLINE vec4 yzwz() const; // readonly
	TRICIBLE_FORCEINLINE vec4 zzwz() const; // readonly
	TRICIBLE_FORCEINLINE vec4 wzwz() const; // readonly
	TRICIBLE_FORCEINLINE vec4 xwwz() const; // readonly
	TRICIBLE_FORCEINLINE vec4 ywwz() const; // readonly
	TRICIBLE_FORCEINLINE vec4 zwwz() const; // readonly
	TRICIBLE_FORCEINLINE vec4 wwwz() const; // readonly
	TRICIBLE_FORCEINLINE vec4 xxxw() const; // readonly
	TRICIBLE_FORCEINLINE vec4 yxxw() const; // readonly
	TRICIBLE_FORCEINLINE vec4 zxxw() const; // readonly
	TRICIBLE_FORCEINLINE vec4 wxxw() const; // readonly
	TRICIBLE_FORCEINLINE vec4 xyxw() const; // readonly
	TRICIBLE_FORCEINLINE vec4 yyxw() const; // readonly
	TRICIBLE_FORCEINLINE vec4 zyxw() const; // readonly
	TRICIBLE_FORCEINLINE swizzle4<vec4, float, 2, 1, 0, 3> zyxw(); // Assignable
	TRICIBLE_FORCEINLINE vec4 wyxw() const; // readonly
	TRICIBLE_FORCEINLINE vec4 xzxw() const; // readonly
	TRICIBLE_FORCEINLINE vec4 yzxw() const; // readonly
	TRICIBLE_FORCEINLINE swizzle4<vec4, float, 1, 2, 0, 3> yzxw(); // Assignable
	TRICIBLE_FORCEINLINE vec4 zzxw() const; // readonly
	TRICIBLE_FORCEINLINE vec4 wzxw() const; // readonly
	TRICIBLE_FORCEINLINE vec4 xwxw() const; // readonly
	TRICIBLE_FORCEINLINE vec4 ywxw() const; // readonly
	TRICIBLE_FORCEINLINE vec4 zwxw() const; // readonly
	TRICIBLE_FORCEINLINE vec4 wwxw() const; // readonly
	TRICIBLE_FORCEINLINE vec4 xxyw() const; // readonly
	TRICIBLE_FORCEINLINE vec4 yxyw() const; // readonly
	TRICIBLE_FORCEINLINE vec4 zxyw() const; // readonly
	TRICIBLE_FORCEINLINE swizzle4<vec4, float, 2, 0, 1, 3> zxyw(); // Assignable
	TRICIBLE_FORCEINLINE vec4 wxyw() const; // readonly
	TRICIBLE_FORCEINLINE vec4 xyyw() const; // readonly
	TRICIBLE_FORCEINLINE vec4 yyyw() const; // readonly
	TRICIBLE_FORCEINLINE vec4 zyyw() const; // readonly
	TRICIBLE_FORCEINLINE vec4 wyyw() const; // readonly
	TRICIBLE_FORCEINLINE vec4 xzyw() const; // readonly
	TRICIBLE_FORCEINLINE swizzle4<vec4, float, 0, 2, 1, 3> xzyw(); // Assignable
	TRICIBLE_FORCEINLINE vec4 yzyw() const; // readonly
	TRICIBLE_FORCEINLINE vec4 zzyw() const; // readonly
	TRICIBLE_FORCEINLINE vec4 wzyw() const; // readonly
	TRICIBLE_FORCEINLINE vec4 xwyw() const; // readonly
	TRICIBLE_FORCEINLINE vec4 ywyw() const; // readonly
	TRICIBLE_FORCEINLINE vec4 zwyw() const; // readonly
	TRICIBLE_FORCEINLINE vec4 wwyw() const; // readonly
	TRICIBLE_FORCEINLINE vec4 xxzw() const; // readonly
	TRICIBLE_FORCEINLINE vec4 yxzw() const; // readonly
	TRICIBLE_FORCEINLINE swizzle4<vec4, float, 1, 0, 2, 3> yxzw(); // Assignable
	TRICIBLE_FORCEINLINE vec4 zxzw() const; // readonly
	TRICIBLE_FORCEINLINE vec4 wxzw() const; // readonly
	TRICIBLE_FORCEINLINE vec4 xyzw() const; // readonly
	TRICIBLE_FORCEINLINE swizzle4<vec4, float, 0, 1, 2, 3> xyzw(); // Assignable
	TRICIBLE_FORCEINLINE vec4 yyzw() const; // readonly
	TRICIBLE_FORCEINLINE vec4 zyzw() const; // readonly
	TRICIBLE_FORCEINLINE vec4 wyzw() const; // readonly
	TRICIBLE_FORCEINLINE vec4 xzzw() const; // readonly
	TRICIBLE_FORCEINLINE vec4 yzzw() const; // readonly
	TRICIBLE_FORCEINLINE vec4 zzzw() const; // readonly
	TRICIBLE_FORCEINLINE vec4 wzzw() const; // readonly
	TRICIBLE_FORCEINLINE vec4 xwzw() const; // readonly
	TRICIBLE_FORCEINLINE vec4 ywzw() const; // readonly
	TRICIBLE_FORCEINLINE vec4 zwzw() const; // readonly
	TRICIBLE_FORCEINLINE vec4 wwzw() const; // readonly
	TRICIBLE_FORCEINLINE vec4 xxww() const; // readonly
	TRICIBLE_FORCEINLINE vec4 yxww() const; // readonly
	TRICIBLE_FORCEINLINE vec4 zxww() const; // readonly
	TRICIBLE_FORCEINLINE vec4 wxww() const; // readonly
	TRICIBLE_FORCEINLINE vec4 xyww() const; // readonly
	TRICIBLE_FORCEINLINE vec4 yyww() const; // readonly
	TRICIBLE_FORCEINLINE vec4 zyww() const; // readonly
	TRICIBLE_FORCEINLINE vec4 wyww() const; // readonly
	TRICIBLE_FORCEINLINE vec4 xzww() const; // readonly
	TRICIBLE_FORCEINLINE vec4 yzww() const; // readonly
	TRICIBLE_FORCEINLINE vec4 zzww() const; // readonly
	TRICIBLE_FORCEINLINE vec4 wzww() const; // readonly
	TRICIBLE_FORCEINLINE vec4 xwww() const; // readonly
	TRICIBLE_FORCEINLINE vec4 ywww() const; // readonly
	TRICIBLE_FORCEINLINE vec4 zwww() const; // readonly
	TRICIBLE_FORCEINLINE vec4 wwww() const; // readonly

	// vec4 with 1 components.
	TRICIBLE_FORCEINLINE float r() const; // readonly
	TRICIBLE_FORCEINLINE swizzle1<vec4, float, 0> r(); // Assignable
	TRICIBLE_FORCEINLINE float g() const; // readonly
	TRICIBLE_FORCEINLINE swizzle1<vec4, float, 1> g(); // Assignable
	TRICIBLE_FORCEINLINE float b() const; // readonly
	TRICIBLE_FORCEINLINE swizzle1<vec4, float, 2> b(); // Assignable
	TRICIBLE_FORCEINLINE float a() const; // readonly
	TRICIBLE_FORCEINLINE swizzle1<vec4, float, 3> a(); // Assignable

	// vec4 with 2 components.
	TRICIBLE_FORCEINLINE vec2 rr() const; // readonly
	TRICIBLE_FORCEINLINE vec2 gr() const; // readonly
	TRICIBLE_FORCEINLINE swizzle2<vec4, float, 1, 0> gr(); // Assignable
	TRICIBLE_FORCEINLINE vec2 br() const; // readonly
	TRICIBLE_FORCEINLINE swizzle2<vec4, float, 2, 0> br(); // Assignable
	TRICIBLE_FORCEINLINE vec2 ar() const; // readonly
	TRICIBLE_FORCEINLINE swizzle2<vec4, float, 3, 0> ar(); // Assignable
	TRICIBLE_FORCEINLINE vec2 rg() const; // readonly
	TRICIBLE_FORCEINLINE swizzle2<vec4, float, 0, 1> rg(); // Assignable
	TRICIBLE_FORCEINLINE vec2 gg() const; // readonly
	TRICIBLE_FORCEINLINE vec2 bg() const; // readonly
	TRICIBLE_FORCEINLINE swizzle2<vec4, float, 2, 1> bg(); // Assignable
	TRICIBLE_FORCEINLINE vec2 ag() const; // readonly
	TRICIBLE_FORCEINLINE swizzle2<vec4, float, 3, 1> ag(); // Assignable
	TRICIBLE_FORCEINLINE vec2 rb() const; // readonly
	TRICIBLE_FORCEINLINE swizzle2<vec4, float, 0, 2> rb(); // Assignable
	TRICIBLE_FORCEINLINE vec2 gb() const; // readonly
	TRICIBLE_FORCEINLINE swizzle2<vec4, float, 1, 2> gb(); // Assignable
	TRICIBLE_FORCEINLINE vec2 bb() const; // readonly
	TRICIBLE_FORCEINLINE vec2 ab() const; // readonly
	TRICIBLE_FORCEINLINE swizzle2<vec4, float, 3, 2> ab(); // Assignable
	TRICIBLE_FORCEINLINE vec2 ra() const; // readonly
	TRICIBLE_FORCEINLINE swizzle2<vec4, float, 0, 3> ra(); // Assignable
	TRICIBLE_FORCEINLINE vec2 ga() const; // readonly
	TRICIBLE_FORCEINLINE swizzle2<vec4, float, 1, 3> ga(); // Assignable
	TRICIBLE_FORCEINLINE vec2 ba() const; // readonly
	TRICIBLE_FORCEINLINE swizzle2<vec4, float, 2, 3> ba(); // Assignable
	TRICIBLE_FORCEINLINE vec2 aa() const; // readonly

	// vec4 with 3 components.
	TRICIBLE_FORCEINLINE vec3 rrr() const; // readonly
	TRICIBLE_FORCEINLINE vec3 grr() const; // readonly
	TRICIBLE_FORCEINLINE vec3 brr() const; // readonly
	TRICIBLE_FORCEINLINE vec3 arr() const; // readonly
	TRICIBLE_FORCEINLINE vec3 rgr() const; // readonly
	TRICIBLE_FORCEINLINE vec3 ggr() const; // readonly
	TRICIBLE_FORCEINLINE vec3 bgr() const; // readonly
	TRICIBLE_FORCEINLINE swizzle3<vec4, float, 2, 1, 0> bgr(); // Assignable
	TRICIBLE_FORCEINLINE vec3 agr() const; // readonly
	TRICIBLE_FORCEINLINE swizzle3<vec4, float, 3, 1, 0> agr(); // Assignable
	TRICIBLE_FORCEINLINE vec3 rbr() const; // readonly
	TRICIBLE_FORCEINLINE vec3 gbr() const; // readonly
	TRICIBLE_FORCEINLINE swizzle3<vec4, float, 1, 2, 0> gbr(); // Assignable
	TRICIBLE_FORCEINLINE vec3 bbr() const; // readonly
	TRICIBLE_FORCEINLINE vec3 abr() const; // readonly
	TRICIBLE_FORCEINLINE swizzle3<vec4, float, 3, 2, 0> abr(); // Assignable
	TRICIBLE_FORCEINLINE vec3 rar() const; // readonly
	TRICIBLE_FORCEINLINE vec3 gar() const; // readonly
	TRICIBLE_FORCEINLINE swizzle3<vec4, float, 1, 3, 0> gar(); // Assignable
	TRICIBLE_FORCEINLINE vec3 bar() const; // readonly
	TRICIBLE_FORCEINLINE swizzle3<vec4, float, 2, 3, 0> bar(); // Assignable
	TRICIBLE_FORCEINLINE vec3 aar() const; // readonly
	TRICIBLE_FORCEINLINE vec3 rrg() const; // readonly
	TRICIBLE_FORCEINLINE vec3 grg() const; // readonly
	TRICIBLE_FORCEINLINE vec3 brg() const; // readonly
	TRICIBLE_FORCEINLINE swizzle3<vec4, float, 2, 0, 1> brg(); // Assignable
	TRICIBLE_FORCEINLINE vec3 arg() const; // readonly
	TRICIBLE_FORCEINLINE swizzle3<vec4, float, 3, 0, 1> arg(); // Assignable
	TRICIBLE_FORCEINLINE vec3 rgg() const; // readonly
	TRICIBLE_FORCEINLINE vec3 ggg() const; // readonly
	TRICIBLE_FORCEINLINE vec3 bgg() const; // readonly
	TRICIBLE_FORCEINLINE vec3 agg() const; // readonly
	TRICIBLE_FORCEINLINE vec3 rbg() const; // readonly
	TRICIBLE_FORCEINLINE swizzle3<vec4, float, 0, 2, 1> rbg(); // Assignable
	TRICIBLE_FORCEINLINE vec3 gbg() const; // readonly
	TRICIBLE_FORCEINLINE vec3 bbg() const; // readonly
	TRICIBLE_FORCEINLINE vec3 abg() const; // readonly
	TRICIBLE_FORCEINLINE swizzle3<vec4, float, 3, 2, 1> abg(); // Assignable
	TRICIBLE_FORCEINLINE vec3 rag() const; // readonly
	TRICIBLE_FORCEINLINE swizzle3<vec4, float, 0, 3, 1> rag(); // Assignable
	TRICIBLE_FORCEINLINE vec3 gag() const; // readonly
	TRICIBLE_FORCEINLINE vec3 bag() const; // readonly
	TRICIBLE_FORCEINLINE swizzle3<vec4, float, 2, 3, 1> bag(); // Assignable
	TRICIBLE_FORCEINLINE vec3 aag() const; // readonly
	TRICIBLE_FORCEINLINE vec3 rrb() const; // readonly
	TRICIBLE_FORCEINLINE vec3 grb() const; // readonly
	TRICIBLE_FORCEINLINE swizzle3<vec4, float, 1, 0, 2> grb(); // Assignable
	TRICIBLE_FORCEINLINE vec3 brb() const; // readonly
	TRICIBLE_FORCEINLINE vec3 arb() const; // readonly
	TRICIBLE_FORCEINLINE swizzle3<vec4, float, 3, 0, 2> arb(); // Assignable
	TRICIBLE_FORCEINLINE vec3 rgb() const; // readonly
	TRICIBLE_FORCEINLINE swizzle3<vec4, float, 0, 1, 2> rgb(); // Assignable
	TRICIBLE_FORCEINLINE vec3 ggb() const; // readonly
	TRICIBLE_FORCEINLINE vec3 bgb() const; // readonly
	TRICIBLE_FORCEINLINE vec3 agb() const; // readonly
	TRICIBLE_FORCEINLINE swizzle3<vec4, float, 3, 1, 2> agb(); // Assignable
	TRICIBLE_FORCEINLINE vec3 rbb() const; // readonly
	TRICIBLE_FORCEINLINE vec3 gbb() const; // readonly
	TRICIBLE_FORCEINLINE vec3 bbb() const; // readonly
	TRICIBLE_FORCEINLINE vec3 abb() const; // readonly
	TRICIBLE_FORCEINLINE vec3 rab() const; // readonly
	TRICIBLE_FORCEINLINE swizzle3<vec4, float, 0, 3, 2> rab(); // Assignable
	TRICIBLE_FORCEINLINE vec3 gab() const; // readonly
	TRICIBLE_FORCEINLINE swizzle3<vec4, float, 1, 3, 2> gab(); // Assignable
	TRICIBLE_FORCEINLINE vec3 bab() const; // readonly
	TRICIBLE_FORCEINLINE vec3 aab() const; // readonly
	TRICIBLE_FORCEINLINE vec3 rra() const; // readonly
	TRICIBLE_FORCEINLINE vec3 gra() const; // readonly
	TRICIBLE_FORCEINLINE swizzle3<vec4, float, 1, 0, 3> gra(); // Assignable
	TRICIBLE_FORCEINLINE vec3 bra() const; // readonly
	TRICIBLE_FORCEINLINE swizzle3<vec4, float, 2, 0, 3> bra(); // Assignable
	TRICIBLE_FORCEINLINE vec3 ara() const; // readonly
	TRICIBLE_FORCEINLINE vec3 rga() const; // readonly
	TRICIBLE_FORCEINLINE swizzle3<vec4, float, 0, 1, 3> rga(); // Assignable
	TRICIBLE_FORCEINLINE vec3 gga() const; // readonly
	TRICIBLE_FORCEINLINE vec3 bga() const; // readonly
	TRICIBLE_FORCEINLINE swizzle3<vec4, float, 2, 1, 3> bga(); // Assignable
	TRICIBLE_FORCEINLINE vec3 aga() const; // readonly
	TRICIBLE_FORCEINLINE vec3 rba() const; // readonly
	TRICIBLE_FORCEINLINE swizzle3<vec4, float, 0, 2, 3> rba(); // Assignable
	TRICIBLE_FORCEINLINE vec3 gba() const; // readonly
	TRICIBLE_FORCEINLINE swizzle3<vec4, float, 1, 2, 3> gba(); // Assignable
	TRICIBLE_FORCEINLINE vec3 bba() const; // readonly
	TRICIBLE_FORCEINLINE vec3 aba() const; // readonly
	TRICIBLE_FORCEINLINE vec3 raa() const; // readonly
	TRICIBLE_FORCEINLINE vec3 gaa() const; // readonly
	TRICIBLE_FORCEINLINE vec3 baa() const; // readonly
	TRICIBLE_FORCEINLINE vec3 aaa() const; // readonly

	// vec4 with 4 components.
	TRICIBLE_FORCEINLINE vec4 rrrr() const; // readonly
	TRICIBLE_FORCEINLINE vec4 grrr() const; // readonly
	TRICIBLE_FORCEINLINE vec4 brrr() const; // readonly
	TRICIBLE_FORCEINLINE vec4 arrr() const; // readonly
	TRICIBLE_FORCEINLINE vec4 rgrr() const; // readonly
	TRICIBLE_FORCEINLINE vec4 ggrr() const; // readonly
	TRICIBLE_FORCEINLINE vec4 bgrr() const; // readonly
	TRICIBLE_FORCEINLINE vec4 agrr() const; // readonly
	TRICIBLE_FORCEINLINE vec4 rbrr() const; // readonly
	TRICIBLE_FORCEINLINE vec4 gbrr() const; // readonly
	TRICIBLE_FORCEINLINE vec4 bbrr() const; // readonly
	TRICIBLE_FORCEINLINE vec4 abrr() const; // readonly
	TRICIBLE_FORCEINLINE vec4 rarr() const; // readonly
	TRICIBLE_FORCEINLINE vec4 garr() const; // readonly
	TRICIBLE_FORCEINLINE vec4 barr() const; // readonly
	TRICIBLE_FORCEINLINE vec4 aarr() const; // readonly
	TRICIBLE_FORCEINLINE vec4 rrgr() const; // readonly
	TRICIBLE_FORCEINLINE vec4 grgr() const; // readonly
	TRICIBLE_FORCEINLINE vec4 brgr() const; // readonly
	TRICIBLE_FORCEINLINE vec4 argr() const; // readonly
	TRICIBLE_FORCEINLINE vec4 rggr() const; // readonly
	TRICIBLE_FORCEINLINE vec4 gggr() const; // readonly
	TRICIBLE_FORCEINLINE vec4 bggr() const; // readonly
	TRICIBLE_FORCEINLINE vec4 aggr() const; // readonly
	TRICIBLE_FORCEINLINE vec4 rbgr() const; // readonly
	TRICIBLE_FORCEINLINE vec4 gbgr() const; // readonly
	TRICIBLE_FORCEINLINE vec4 bbgr() const; // readonly
	TRICIBLE_FORCEINLINE vec4 abgr() const; // readonly
	TRICIBLE_FORCEINLINE swizzle4<vec4, float, 3, 2, 1, 0> abgr(); // Assignable
	TRICIBLE_FORCEINLINE vec4 ragr() const; // readonly
	TRICIBLE_FORCEINLINE vec4 gagr() const; // readonly
	TRICIBLE_FORCEINLINE vec4 bagr() const; // readonly
	TRICIBLE_FORCEINLINE swizzle4<vec4, float, 2, 3, 1, 0> bagr(); // Assignable
	TRICIBLE_FORCEINLINE vec4 aagr() const; // readonly
	TRICIBLE_FORCEINLINE vec4 rrbr() const; // readonly
	TRICIBLE_FORCEINLINE vec4 grbr() const; // readonly
	TRICIBLE_FORCEINLINE vec4 brbr() const; // readonly
	TRICIBLE_FORCEINLINE vec4 arbr() const; // readonly
	TRICIBLE_FORCEINLINE vec4 rgbr() const; // readonly
	TRICIBLE_FORCEINLINE vec4 ggbr() const; // readonly
	TRICIBLE_FORCEINLINE vec4 bgbr() const; // readonly
	TRICIBLE_FORCEINLINE vec4 agbr() const; // readonly
	TRICIBLE_FORCEINLINE swizzle4<vec4, float, 3, 1, 2, 0> agbr(); // Assignable
	TRICIBLE_FORCEINLINE vec4 rbbr() const; // readonly
	TRICIBLE_FORCEINLINE vec4 gbbr() const; // readonly
	TRICIBLE_FORCEINLINE vec4 bbbr() const; // readonly
	TRICIBLE_FORCEINLINE vec4 abbr() const; // readonly
	TRICIBLE_FORCEINLINE vec4 rabr() const; // readonly
	TRICIBLE_FORCEINLINE vec4 gabr() const; // readonly
	TRICIBLE_FORCEINLINE swizzle4<vec4, float, 1, 3, 2, 0> gabr(); // Assignable
	TRICIBLE_FORCEINLINE vec4 babr() const; // readonly
	TRICIBLE_FORCEINLINE vec4 aabr() const; // readonly
	TRICIBLE_FORCEINLINE vec4 rrar() const; // readonly
	TRICIBLE_FORCEINLINE vec4 grar() const; // readonly
	TRICIBLE_FORCEINLINE vec4 brar() const; // readonly
	TRICIBLE_FORCEINLINE vec4 arar() const; // readonly
	TRICIBLE_FORCEINLINE vec4 rgar() const; // readonly
	TRICIBLE_FORCEINLINE vec4 ggar() const; // readonly
	TRICIBLE_FORCEINLINE vec4 bgar() const; // readonly
	TRICIBLE_FORCEINLINE swizzle4<vec4, float, 2, 1, 3, 0> bgar(); // Assignable
	TRICIBLE_FORCEINLINE vec4 agar() const; // readonly
	TRICIBLE_FORCEINLINE vec4 rbar() const; // readonly
	TRICIBLE_FORCEINLINE vec4 gbar() const; // readonly
	TRICIBLE_FORCEINLINE swizzle4<vec4, float, 1, 2, 3, 0> gbar(); // Assignable
	TRICIBLE_FORCEINLINE vec4 bbar() const; // readonly
	TRICIBLE_FORCEINLINE vec4 abar() const; // readonly
	TRICIBLE_FORCEINLINE vec4 raar() const; // readonly
	TRICIBLE_FORCEINLINE vec4 gaar() const; // readonly
	TRICIBLE_FORCEINLINE vec4 baar() const; // readonly
	TRICIBLE_FORCEINLINE vec4 aaar() const; // readonly
	TRICIBLE_FORCEINLINE vec4 rrrg() const; // readonly
	TRICIBLE_FORCEINLINE vec4 grrg() const; // readonly
	TRICIBLE_FORCEINLINE vec4 brrg() const; // readonly
	TRICIBLE_FORCEINLINE vec4 arrg() const; // readonly
	TRICIBLE_FORCEINLINE vec4 rgrg() const; // readonly
	TRICIBLE_FORCEINLINE vec4 ggrg() const; // readonly
	TRICIBLE_FORCEINLINE vec4 bgrg() const; // readonly
	TRICIBLE_FORCEINLINE vec4 agrg() const; // readonly
	TRICIBLE_FORCEINLINE vec4 rbrg() const; // readonly
	TRICIBLE_FORCEINLINE vec4 gbrg() const; // readonly
	TRICIBLE_FORCEINLINE vec4 bbrg() const; // readonly
	TRICIBLE_FORCEINLINE vec4 abrg() const; // readonly
	TRICIBLE_FORCEINLINE swizzle4<vec4, float, 3, 2, 0, 1> abrg(); // Assignable
	TRICIBLE_FORCEINLINE vec4 rarg() const; // readonly
	TRICIBLE_FORCEINLINE vec4 garg() const; // readonly
	TRICIBLE_FORCEINLINE vec4 barg() const; // readonly
	TRICIBLE_FORCEINLINE swizzle4<vec4, float, 2, 3, 0, 1> barg(); // Assignable
	TRICIBLE_FORCEINLINE vec4 aarg() const; // readonly
	TRICIBLE_FORCEINLINE vec4 rrgg() const; // readonly
	TRICIBLE_FORCEINLINE vec4 grgg() const; // readonly
	TRICIBLE_FORCEINLINE vec4 brgg() const; // readonly
	TRICIBLE_FORCEINLINE vec4 argg() const; // readonly
	TRICIBLE_FORCEINLINE vec4 rggg() const; // readonly
	TRICIBLE_FORCEINLINE vec4 gggg() const; // readonly
	TRICIBLE_FORCEINLINE vec4 bggg() const; // readonly
	TRICIBLE_FORCEINLINE vec4 aggg() const; // readonly
	TRICIBLE_FORCEINLINE vec4 rbgg() const; // readonly
	TRICIBLE_FORCEINLINE vec4 gbgg() const; // readonly
	TRICIBLE_FORCEINLINE vec4 bbgg() const; // readonly
	TRICIBLE_FORCEINLINE vec4 abgg() const; // readonly
	TRICIBLE_FORCEINLINE vec4 ragg() const; // readonly
	TRICIBLE_FORCEINLINE vec4 gagg() const; // readonly
	TRICIBLE_FORCEINLINE vec4 bagg() const; // readonly
	TRICIBLE_FORCEINLINE vec4 aagg() const; // readonly
	TRICIBLE_FORCEINLINE vec4 rrbg() const; // readonly
	TRICIBLE_FORCEINLINE vec4 grbg() const; // readonly
	TRICIBLE_FORCEINLINE vec4 brbg() const; // readonly
	TRICIBLE_FORCEINLINE vec4 arbg() const; // readonly
	TRICIBLE_FORCEINLINE swizzle4<vec4, float, 3, 0, 2, 1> arbg(); // Assignable
	TRICIBLE_FORCEINLINE vec4 rgbg() const; // readonly
	TRICIBLE_FORCEINLINE vec4 ggbg() const; // readonly
	TRICIBLE_FORCEINLINE vec4 bgbg() const; // readonly
	TRICIBLE_FORCEINLINE vec4 agbg() const; // readonly
	TRICIBLE_FORCEINLINE vec4 rbbg() const; // readonly
	TRICIBLE_FORCEINLINE vec4 gbbg() const; // readonly
	TRICIBLE_FORCEINLINE vec4 bbbg() const; // readonly
	TRICIBLE_FORCEINLINE vec4 abbg() const; // readonly
	TRICIBLE_FORCEINLINE vec4 rabg() const; // readonly
	TRICIBLE_FORCEINLINE swizzle4<vec4, float, 0, 3, 2, 1> rabg(); // Assignable
	TRICIBLE_FORCEINLINE vec4 gabg() const; // readonly
	TRICIBLE_FORCEINLINE vec4 babg() const; // readonly
	TRICIBLE_FORCEINLINE vec4 aabg() const; // readonly
	TRICIBLE_FORCEINLINE vec4 rrag() const; // readonly
	TRICIBLE_FORCEINLINE vec4 grag() const; // readonly
	TRICIBLE_FORCEINLINE vec4 brag() const; // readonly
	TRICIBLE_FORCEINLINE swizzle4<vec4, float, 2, 0, 3, 1> brag(); // Assignable
	TRICIBLE_FORCEINLINE vec4 arag() const; // readonly
	TRICIBLE_FORCEINLINE vec4 rgag() const; // readonly
	TRICIBLE_FORCEINLINE vec4 ggag() const; // readonly
	TRICIBLE_FORCEINLINE vec4 bgag() const; // readonly
	TRICIBLE_FORCEINLINE vec4 agag() const; // readonly
	TRICIBLE_FORCEINLINE vec4 rbag() const; // readonly
	TRICIBLE_FORCEINLINE swizzle4<vec4, float, 0, 2, 3, 1> rbag(); // Assignable
	TRICIBLE_FORCEINLINE vec4 gbag() const; // readonly
	TRICIBLE_FORCEINLINE vec4 bbag() const; // readonly
	TRICIBLE_FORCEINLINE vec4 abag() const; // readonly
	TRICIBLE_FORCEINLINE vec4 raag() const; // readonly
	TRICIBLE_FORCEINLINE vec4 gaag() const; // readonly
	TRICIBLE_FORCEINLINE vec4 baag() const; // readonly
	TRICIBLE_FORCEINLINE vec4 aaag() const; // readonly
	TRICIBLE_FORCEINLINE vec4 rrrb() const; // readonly
	TRICIBLE_FORCEINLINE vec4 grrb() const; // readonly
	TRICIBLE_FORCEINLINE vec4 brrb() const; // readonly
	TRICIBLE_FORCEINLINE vec4 arrb() const; // readonly
	TRICIBLE_FORCEINLINE vec4 rgrb() const; // readonly
	TRICIBLE_FORCEINLINE vec4 ggrb() const; // readonly
	TRICIBLE_FORCEINLINE vec4 bgrb() const; // readonly
	TRICIBLE_FORCEINLINE vec4 agrb() const; // readonly
	TRICIBLE_FORCEINLINE swizzle4<vec4, float, 3, 1, 0, 2> agrb(); // Assignable
	TRICIBLE_FORCEINLINE vec4 rbrb() const; // readonly
	TRICIBLE_FORCEINLINE vec4 gbrb() const; // readonly
	TRICIBLE_FORCEINLINE vec4 bbrb() const; // readonly
	TRICIBLE_FORCEINLINE vec4 abrb() const; // readonly
	TRICIBLE_FORCEINLINE vec4 rarb() const; // readonly
	TRICIBLE_FORCEINLINE vec4 garb() const; // readonly
	TRICIBLE_FORCEINLINE swizzle4<vec4, float, 1, 3, 0, 2> garb(); // Assignable
	TRICIBLE_FORCEINLINE vec4 barb() const; // readonly
	TRICIBLE_FORCEINLINE vec4 aarb() const; // readonly
	TRICIBLE_FORCEINLINE vec4 rrgb() const; // readonly
	TRICIBLE_FORCEINLINE vec4 grgb() const; // readonly
	TRICIBLE_FORCEINLINE vec4 brgb() const; // readonly
	TRICIBLE_FORCEINLINE vec4 argb() const; // readonly
	TRICIBLE_FORCEINLINE swizzle4<vec4, float, 3, 0, 1, 2> argb(); // Assignable
	TRICIBLE_FORCEINLINE vec4 rggb() const; // readonly
	TRICIBLE_FORCEINLINE vec4 gggb() const; // readonly
	TRICIBLE_FORCEINLINE vec4 bggb() const; // readonly
	TRICIBLE_FORCEINLINE vec4 aggb() const; // readonly
	TRICIBLE_FORCEINLINE vec4 rbgb() const; // readonly
	TRICIBLE_FORCEINLINE vec4 gbgb() const; // readonly
	TRICIBLE_FORCEINLINE vec4 bbgb() const; // readonly
	TRICIBLE_FORCEINLINE vec4 abgb() const; // readonly
	TRICIBLE_FORCEINLINE vec4 ragb() const; // readonly
	TRICIBLE_FORCEINLINE swizzle4<vec4, float, 0, 3, 1, 2> ragb(); // Assignable
	TRICIBLE_FORCEINLINE vec4 gagb() const; // readonly
	TRICIBLE_FORCEINLINE vec4 bagb() const; // readonly
	TRICIBLE_FORCEINLINE vec4 aagb() const; // readonly
	TRICIBLE_FORCEINLINE vec4 rrbb() const; // readonly
	TRICIBLE_FORCEINLINE vec4 grbb() const; // readonly
	TRICIBLE_FORCEINLINE vec4 brbb() const; // readonly
	TRICIBLE_FORCEINLINE vec4 arbb() const; // readonly
	TRICIBLE_FORCEINLINE vec4 rgbb() const; // readonly
	TRICIBLE_FORCEINLINE vec4 ggbb() const; // readonly
	TRICIBLE_FORCEINLINE vec4 bgbb() const; // readonly
	TRICIBLE_FORCEINLINE vec4 agbb() const; // readonly
	TRICIBLE_FORCEINLINE vec4 rbbb() const; // readonly
	TRICIBLE_FORCEINLINE vec4 gbbb() const; // readonly
	TRICIBLE_FORCEINLINE vec4 bbbb() const; // readonly
	TRICIBLE_FORCEINLINE vec4 abbb() const; // readonly
	TRICIBLE_FORCEINLINE vec4 rabb() const; // readonly
	TRICIBLE_FORCEINLINE vec4 gabb() const; // readonly
	TRICIBLE_FORCEINLINE vec4 babb() const; // readonly
	TRICIBLE_FORCEINLINE vec4 aabb() const; // readonly
	TRICIBLE_FORCEINLINE vec4 rrab() const; // readonly
	TRICIBLE_FORCEINLINE vec4 grab() const; // readonly
	TRICIBLE_FORCEINLINE swizzle4<vec4, float, 1, 0, 3, 2> grab(); // Assignable
	TRICIBLE_FORCEINLINE vec4 brab() const; // readonly
	TRICIBLE_FORCEINLINE vec4 arab() const; // readonly
	TRICIBLE_FORCEINLINE vec4 rgab() const; // readonly
	TRICIBLE_FORCEINLINE swizzle4<vec4, float, 0, 1, 3, 2> rgab(); // Assignable
	TRICIBLE_FORCEINLINE vec4 ggab() const; // readonly
	TRICIBLE_FORCEINLINE vec4 bgab() const; // readonly
	TRICIBLE_FORCEINLINE vec4 agab() const; // readonly
	TRICIBLE_FORCEINLINE vec4 rbab() const; // readonly
	TRICIBLE_FORCEINLINE vec4 gbab() const; // readonly
	TRICIBLE_FORCEINLINE vec4 bbab() const; // readonly
	TRICIBLE_FORCEINLINE vec4 abab() const; // readonly
	TRICIBLE_FORCEINLINE vec4 raab() const; // readonly
	TRICIBLE_FORCEINLINE vec4 gaab() const; // readonly
	TRICIBLE_FORCEINLINE vec4 baab() const; // readonly
	TRICIBLE_FORCEINLINE vec4 aaab() const; // readonly
	TRICIBLE_FORCEINLINE vec4 rrra() const; // readonly
	TRICIBLE_FORCEINLINE vec4 grra() const; // readonly
	TRICIBLE_FORCEINLINE vec4 brra() const; // readonly
	TRICIBLE_FORCEINLINE vec4 arra() const; // readonly
	TRICIBLE_FORCEINLINE vec4 rgra() const; // readonly
	TRICIBLE_FORCEINLINE vec4 ggra() const; // readonly
	TRICIBLE_FORCEINLINE vec4 bgra() const; // readonly
	TRICIBLE_FORCEINLINE swizzle4<vec4, float, 2, 1, 0, 3> bgra(); // Assignable
	TRICIBLE_FORCEINLINE vec4 agra() const; // readonly
	TRICIBLE_FORCEINLINE vec4 rbra() const; // readonly
	TRICIBLE_FORCEINLINE vec4 gbra() const; // readonly
	TRICIBLE_FORCEINLINE swizzle4<vec4, float, 1, 2, 0, 3> gbra(); // Assignable
	TRICIBLE_FORCEINLINE vec4 bbra() const; // readonly
	TRICIBLE_FORCEINLINE vec4 abra() const; // readonly
	TRICIBLE_FORCEINLINE vec4 rara() const; // readonly
	TRICIBLE_FORCEINLINE vec4 gara() const; // readonly
	TRICIBLE_FORCEINLINE vec4 bara() const; // readonly
	TRICIBLE_FORCEINLINE vec4 aara() const; // readonly
	TRICIBLE_FORCEINLINE vec4 rrga() const; // readonly
	TRICIBLE_FORCEINLINE vec4 grga() const; // readonly
	TRICIBLE_FORCEINLINE vec4 brga() const; // readonly
	TRICIBLE_FORCEINLINE swizzle4<vec4, float, 2, 0, 1, 3> brga(); // Assignable
	TRICIBLE_FORCEINLINE vec4 arga() const; // readonly
	TRICIBLE_FORCEINLINE vec4 rgga() const; // readonly
	TRICIBLE_FORCEINLINE vec4 ggga() const; // readonly
	TRICIBLE_FORCEINLINE vec4 bgga() const; // readonly
	TRICIBLE_FORCEINLINE vec4 agga() const; // readonly
	TRICIBLE_FORCEINLINE vec4 rbga() const; // readonly
	TRICIBLE_FORCEINLINE swizzle4<vec4, float, 0, 2, 1, 3> rbga(); // Assignable
	TRICIBLE_FORCEINLINE vec4 gbga() const; // readonly
	TRICIBLE_FORCEINLINE vec4 bbga() const; // readonly
	TRICIBLE_FORCEINLINE vec4 abga() const; // readonly
	TRICIBLE_FORCEINLINE vec4 raga() const; // readonly
	TRICIBLE_FORCEINLINE vec4 gaga() const; // readonly
	TRICIBLE_FORCEINLINE vec4 baga() const; // readonly
	TRICIBLE_FORCEINLINE vec4 aaga() const; // readonly
	TRICIBLE_FORCEINLINE vec4 rrba() const; // readonly
	TRICIBLE_FORCEINLINE vec4 grba() const; // readonly
	TRICIBLE_FORCEINLINE swizzle4<vec4, float, 1, 0, 2, 3> grba(); // Assignable
	TRICIBLE_FORCEINLINE vec4 brba() const; // readonly
	TRICIBLE_FORCEINLINE vec4 arba() const; // readonly
	TRICIBLE_FORCEINLINE vec4 rgba() const; // readonly
	TRICIBLE_FORCEINLINE swizzle4<vec4, float, 0, 1, 2, 3> rgba(); // Assignable
	TRICIBLE_FORCEINLINE vec4 ggba() const; // readonly
	TRICIBLE_FORCEINLINE vec4 bgba() const; // readonly
	TRICIBLE_FORCEINLINE vec4 agba() const; // readonly
	TRICIBLE_FORCEINLINE vec4 rbba() const; // readonly
	TRICIBLE_FORCEINLINE vec4 gbba() const; // readonly
	TRICIBLE_FORCEINLINE vec4 bbba() const; // readonly
	TRICIBLE_FORCEINLINE vec4 abba() const; // readonly
	TRICIBLE_FORCEINLINE vec4 raba() const; // readonly
	TRICIBLE_FORCEINLINE vec4 gaba() const; // readonly
	TRICIBLE_FORCEINLINE vec4 baba() const; // readonly
	TRICIBLE_FORCEINLINE vec4 aaba() const; // readonly
	TRICIBLE_FORCEINLINE vec4 rraa() const; // readonly
	TRICIBLE_FORCEINLINE vec4 graa() const; // readonly
	TRICIBLE_FORCEINLINE vec4 braa() const; // readonly
	TRICIBLE_FORCEINLINE vec4 araa() const; // readonly
	TRICIBLE_FORCEINLINE vec4 rgaa() const; // readonly
	TRICIBLE_FORCEINLINE vec4 ggaa() const; // readonly
	TRICIBLE_FORCEINLINE vec4 bgaa() const; // readonly
	TRICIBLE_FORCEINLINE vec4 agaa() const; // readonly
	TRICIBLE_FORCEINLINE vec4 rbaa() const; // readonly
	TRICIBLE_FORCEINLINE vec4 gbaa() const; // readonly
	TRICIBLE_FORCEINLINE vec4 bbaa() const; // readonly
	TRICIBLE_FORCEINLINE vec4 abaa() const; // readonly
	TRICIBLE_FORCEINLINE vec4 raaa() const; // readonly
	TRICIBLE_FORCEINLINE vec4 gaaa() const; // readonly
	TRICIBLE_FORCEINLINE vec4 baaa() const; // readonly
	TRICIBLE_FORCEINLINE vec4 aaaa() const; // readonly

	// vec4 with 1 components.
	TRICIBLE_FORCEINLINE float s() const; // readonly
	TRICIBLE_FORCEINLINE swizzle1<vec4, float, 0> s(); // Assignable
	TRICIBLE_FORCEINLINE float t() const; // readonly
	TRICIBLE_FORCEINLINE swizzle1<vec4, float, 1> t(); // Assignable
	TRICIBLE_FORCEINLINE float p() const; // readonly
	TRICIBLE_FORCEINLINE swizzle1<vec4, float, 2> p(); // Assignable
	TRICIBLE_FORCEINLINE float q() const; // readonly
	TRICIBLE_FORCEINLINE swizzle1<vec4, float, 3> q(); // Assignable

	// vec4 with 2 components.
	TRICIBLE_FORCEINLINE vec2 ss() const; // readonly
	TRICIBLE_FORCEINLINE vec2 ts() const; // readonly
	TRICIBLE_FORCEINLINE swizzle2<vec4, float, 1, 0> ts(); // Assignable
	TRICIBLE_FORCEINLINE vec2 ps() const; // readonly
	TRICIBLE_FORCEINLINE swizzle2<vec4, float, 2, 0> ps(); // Assignable
	TRICIBLE_FORCEINLINE vec2 qs() const; // readonly
	TRICIBLE_FORCEINLINE swizzle2<vec4, float, 3, 0> qs(); // Assignable
	TRICIBLE_FORCEINLINE vec2 st() const; // readonly
	TRICIBLE_FORCEINLINE swizzle2<vec4, float, 0, 1> st(); // Assignable
	TRICIBLE_FORCEINLINE vec2 tt() const; // readonly
	TRICIBLE_FORCEINLINE vec2 pt() const; // readonly
	TRICIBLE_FORCEINLINE swizzle2<vec4, float, 2, 1> pt(); // Assignable
	TRICIBLE_FORCEINLINE vec2 qt() const; // readonly
	TRICIBLE_FORCEINLINE swizzle2<vec4, float, 3, 1> qt(); // Assignable
	TRICIBLE_FORCEINLINE vec2 sp() const; // readonly
	TRICIBLE_FORCEINLINE swizzle2<vec4, float, 0, 2> sp(); // Assignable
	TRICIBLE_FORCEINLINE vec2 tp() const; // readonly
	TRICIBLE_FORCEINLINE swizzle2<vec4, float, 1, 2> tp(); // Assignable
	TRICIBLE_FORCEINLINE vec2 pp() const; // readonly
	TRICIBLE_FORCEINLINE vec2 qp() const; // readonly
	TRICIBLE_FORCEINLINE swizzle2<vec4, float, 3, 2> qp(); // Assignable
	TRICIBLE_FORCEINLINE vec2 sq() const; // readonly
	TRICIBLE_FORCEINLINE swizzle2<vec4, float, 0, 3> sq(); // Assignable
	TRICIBLE_FORCEINLINE vec2 tq() const; // readonly
	TRICIBLE_FORCEINLINE swizzle2<vec4, float, 1, 3> tq(); // Assignable
	TRICIBLE_FORCEINLINE vec2 pq() const; // readonly
	TRICIBLE_FORCEINLINE swizzle2<vec4, float, 2, 3> pq(); // Assignable
	TRICIBLE_FORCEINLINE vec2 qq() const; // readonly

	// vec4 with 3 components.
	TRICIBLE_FORCEINLINE vec3 sss() const; // readonly
	TRICIBLE_FORCEINLINE vec3 tss() const; // readonly
	TRICIBLE_FORCEINLINE vec3 pss() const; // readonly
	TRICIBLE_FORCEINLINE vec3 qss() const; // readonly
	TRICIBLE_FORCEINLINE vec3 sts() const; // readonly
	TRICIBLE_FORCEINLINE vec3 tts() const; // readonly
	TRICIBLE_FORCEINLINE vec3 pts() const; // readonly
	TRICIBLE_FORCEINLINE swizzle3<vec4, float, 2, 1, 0> pts(); // Assignable
	TRICIBLE_FORCEINLINE vec3 qts() const; // readonly
	TRICIBLE_FORCEINLINE swizzle3<vec4, float, 3, 1, 0> qts(); // Assignable
	TRICIBLE_FORCEINLINE vec3 sps() const; // readonly
	TRICIBLE_FORCEINLINE vec3 tps() const; // readonly
	TRICIBLE_FORCEINLINE swizzle3<vec4, float, 1, 2, 0> tps(); // Assignable
	TRICIBLE_FORCEINLINE vec3 pps() const; // readonly
	TRICIBLE_FORCEINLINE vec3 qps() const; // readonly
	TRICIBLE_FORCEINLINE swizzle3<vec4, float, 3, 2, 0> qps(); // Assignable
	TRICIBLE_FORCEINLINE vec3 sqs() const; // readonly
	TRICIBLE_FORCEINLINE vec3 tqs() const; // readonly
	TRICIBLE_FORCEINLINE swizzle3<vec4, float, 1, 3, 0> tqs(); // Assignable
	TRICIBLE_FORCEINLINE vec3 pqs() const; // readonly
	TRICIBLE_FORCEINLINE swizzle3<vec4, float, 2, 3, 0> pqs(); // Assignable
	TRICIBLE_FORCEINLINE vec3 qqs() const; // readonly
	TRICIBLE_FORCEINLINE vec3 sst() const; // readonly
	TRICIBLE_FORCEINLINE vec3 tst() const; // readonly
	TRICIBLE_FORCEINLINE vec3 pst() const; // readonly
	TRICIBLE_FORCEINLINE swizzle3<vec4, float, 2, 0, 1> pst(); // Assignable
	TRICIBLE_FORCEINLINE vec3 qst() const; // readonly
	TRICIBLE_FORCEINLINE swizzle3<vec4, float, 3, 0, 1> qst(); // Assignable
	TRICIBLE_FORCEINLINE vec3 stt() const; // readonly
	TRICIBLE_FORCEINLINE vec3 ttt() const; // readonly
	TRICIBLE_FORCEINLINE vec3 ptt() const; // readonly
	TRICIBLE_FORCEINLINE vec3 qtt() const; // readonly
	TRICIBLE_FORCEINLINE vec3 spt() const; // readonly
	TRICIBLE_FORCEINLINE swizzle3<vec4, float, 0, 2, 1> spt(); // Assignable
	TRICIBLE_FORCEINLINE vec3 tpt() const; // readonly
	TRICIBLE_FORCEINLINE vec3 ppt() const; // readonly
	TRICIBLE_FORCEINLINE vec3 qpt() const; // readonly
	TRICIBLE_FORCEINLINE swizzle3<vec4, float, 3, 2, 1> qpt(); // Assignable
	TRICIBLE_FORCEINLINE vec3 sqt() const; // readonly
	TRICIBLE_FORCEINLINE swizzle3<vec4, float, 0, 3, 1> sqt(); // Assignable
	TRICIBLE_FORCEINLINE vec3 tqt() const; // readonly
	TRICIBLE_FORCEINLINE vec3 pqt() const; // readonly
	TRICIBLE_FORCEINLINE swizzle3<vec4, float, 2, 3, 1> pqt(); // Assignable
	TRICIBLE_FORCEINLINE vec3 qqt() const; // readonly
	TRICIBLE_FORCEINLINE vec3 ssp() const; // readonly
	TRICIBLE_FORCEINLINE vec3 tsp() const; // readonly
	TRICIBLE_FORCEINLINE swizzle3<vec4, float, 1, 0, 2> tsp(); // Assignable
	TRICIBLE_FORCEINLINE vec3 psp() const; // readonly
	TRICIBLE_FORCEINLINE vec3 qsp() const; // readonly
	TRICIBLE_FORCEINLINE swizzle3<vec4, float, 3, 0, 2> qsp(); // Assignable
	TRICIBLE_FORCEINLINE vec3 stp() const; // readonly
	TRICIBLE_FORCEINLINE swizzle3<vec4, float, 0, 1, 2> stp(); // Assignable
	TRICIBLE_FORCEINLINE vec3 ttp() const; // readonly
	TRICIBLE_FORCEINLINE vec3 ptp() const; // readonly
	TRICIBLE_FORCEINLINE vec3 qtp() const; // readonly
	TRICIBLE_FORCEINLINE swizzle3<vec4, float, 3, 1, 2> qtp(); // Assignable
	TRICIBLE_FORCEINLINE vec3 spp() const; // readonly
	TRICIBLE_FORCEINLINE vec3 tpp() const; // readonly
	TRICIBLE_FORCEINLINE vec3 ppp() const; // readonly
	TRICIBLE_FORCEINLINE vec3 qpp() const; // readonly
	TRICIBLE_FORCEINLINE vec3 sqp() const; // readonly
	TRICIBLE_FORCEINLINE swizzle3<vec4, float, 0, 3, 2> sqp(); // Assignable
	TRICIBLE_FORCEINLINE vec3 tqp() const; // readonly
	TRICIBLE_FORCEINLINE swizzle3<vec4, float, 1, 3, 2> tqp(); // Assignable
	TRICIBLE_FORCEINLINE vec3 pqp() const; // readonly
	TRICIBLE_FORCEINLINE vec3 qqp() const; // readonly
	TRICIBLE_FORCEINLINE vec3 ssq() const; // readonly
	TRICIBLE_FORCEINLINE vec3 tsq() const; // readonly
	TRICIBLE_FORCEINLINE swizzle3<vec4, float, 1, 0, 3> tsq(); // Assignable
	TRICIBLE_FORCEINLINE vec3 psq() const; // readonly
	TRICIBLE_FORCEINLINE swizzle3<vec4, float, 2, 0, 3> psq(); // Assignable
	TRICIBLE_FORCEINLINE vec3 qsq() const; // readonly
	TRICIBLE_FORCEINLINE vec3 stq() const; // readonly
	TRICIBLE_FORCEINLINE swizzle3<vec4, float, 0, 1, 3> stq(); // Assignable
	TRICIBLE_FORCEINLINE vec3 ttq() const; // readonly
	TRICIBLE_FORCEINLINE vec3 ptq() const; // readonly
	TRICIBLE_FORCEINLINE swizzle3<vec4, float, 2, 1, 3> ptq(); // Assignable
	TRICIBLE_FORCEINLINE vec3 qtq() const; // readonly
	TRICIBLE_FORCEINLINE vec3 spq() const; // readonly
	TRICIBLE_FORCEINLINE swizzle3<vec4, float, 0, 2, 3> spq(); // Assignable
	TRICIBLE_FORCEINLINE vec3 tpq() const; // readonly
	TRICIBLE_FORCEINLINE swizzle3<vec4, float, 1, 2, 3> tpq(); // Assignable
	TRICIBLE_FORCEINLINE vec3 ppq() const; // readonly
	TRICIBLE_FORCEINLINE vec3 qpq() const; // readonly
	TRICIBLE_FORCEINLINE vec3 sqq() const; // readonly
	TRICIBLE_FORCEINLINE vec3 tqq() const; // readonly
	TRICIBLE_FORCEINLINE vec3 pqq() const; // readonly
	TRICIBLE_FORCEINLINE vec3 qqq() const; // readonly

	// vec4 with 4 components.
	TRICIBLE_FORCEINLINE vec4 ssss() const; // readonly
	TRICIBLE_FORCEINLINE vec4 tsss() const; // readonly
	TRICIBLE_FORCEINLINE vec4 psss() const; // readonly
	TRICIBLE_FORCEINLINE vec4 qsss() const; // readonly
	TRICIBLE_FORCEINLINE vec4 stss() const; // readonly
	TRICIBLE_FORCEINLINE vec4 ttss() const; // readonly
	TRICIBLE_FORCEINLINE vec4 ptss() const; // readonly
	TRICIBLE_FORCEINLINE vec4 qtss() const; // readonly
	TRICIBLE_FORCEINLINE vec4 spss() const; // readonly
	TRICIBLE_FORCEINLINE vec4 tpss() const; // readonly
	TRICIBLE_FORCEINLINE vec4 ppss() const; // readonly
	TRICIBLE_FORCEINLINE vec4 qpss() const; // readonly
	TRICIBLE_FORCEINLINE vec4 sqss() const; // readonly
	TRICIBLE_FORCEINLINE vec4 tqss() const; // readonly
	TRICIBLE_FORCEINLINE vec4 pqss() const; // readonly
	TRICIBLE_FORCEINLINE vec4 qqss() const; // readonly
	TRICIBLE_FORCEINLINE vec4 ssts() const; // readonly
	TRICIBLE_FORCEINLINE vec4 tsts() const; // readonly
	TRICIBLE_FORCEINLINE vec4 psts() const; // readonly
	TRICIBLE_FORCEINLINE vec4 qsts() const; // readonly
	TRICIBLE_FORCEINLINE vec4 stts() const; // readonly
	TRICIBLE_FORCEINLINE vec4 ttts() const; // readonly
	TRICIBLE_FORCEINLINE vec4 ptts() const; // readonly
	TRICIBLE_FORCEINLINE vec4 qtts() const; // readonly
	TRICIBLE_FORCEINLINE vec4 spts() const; // readonly
	TRICIBLE_FORCEINLINE vec4 tpts() const; // readonly
	TRICIBLE_FORCEINLINE vec4 ppts() const; // readonly
	TRICIBLE_FORCEINLINE vec4 qpts() const; // readonly
	TRICIBLE_FORCEINLINE swizzle4<vec4, float, 3, 2, 1, 0> qpts(); // Assignable
	TRICIBLE_FORCEINLINE vec4 sqts() const; // readonly
	TRICIBLE_FORCEINLINE vec4 tqts() const; // readonly
	TRICIBLE_FORCEINLINE vec4 pqts() const; // readonly
	TRICIBLE_FORCEINLINE swizzle4<vec4, float, 2, 3, 1, 0> pqts(); // Assignable
	TRICIBLE_FORCEINLINE vec4 qqts() const; // readonly
	TRICIBLE_FORCEINLINE vec4 ssps() const; // readonly
	TRICIBLE_FORCEINLINE vec4 tsps() const; // readonly
	TRICIBLE_FORCEINLINE vec4 psps() const; // readonly
	TRICIBLE_FORCEINLINE vec4 qsps() const; // readonly
	TRICIBLE_FORCEINLINE vec4 stps() const; // readonly
	TRICIBLE_FORCEINLINE vec4 ttps() const; // readonly
	TRICIBLE_FORCEINLINE vec4 ptps() const; // readonly
	TRICIBLE_FORCEINLINE vec4 qtps() const; // readonly
	TRICIBLE_FORCEINLINE swizzle4<vec4, float, 3, 1, 2, 0> qtps(); // Assignable
	TRICIBLE_FORCEINLINE vec4 spps() const; // readonly
	TRICIBLE_FORCEINLINE vec4 tpps() const; // readonly
	TRICIBLE_FORCEINLINE vec4 ppps() const; // readonly
	TRICIBLE_FORCEINLINE vec4 qpps() const; // readonly
	TRICIBLE_FORCEINLINE vec4 sqps() const; // readonly
	TRICIBLE_FORCEINLINE vec4 tqps() const; // readonly
	TRICIBLE_FORCEINLINE swizzle4<vec4, float, 1, 3, 2, 0> tqps(); // Assignable
	TRICIBLE_FORCEINLINE vec4 pqps() const; // readonly
	TRICIBLE_FORCEINLINE vec4 qqps() const; // readonly
	TRICIBLE_FORCEINLINE vec4 ssqs() const; // readonly
	TRICIBLE_FORCEINLINE vec4 tsqs() const; // readonly
	TRICIBLE_FORCEINLINE vec4 psqs() const; // readonly
	TRICIBLE_FORCEINLINE vec4 qsqs() const; // readonly
	TRICIBLE_FORCEINLINE vec4 stqs() const; // readonly
	TRICIBLE_FORCEINLINE vec4 ttqs() const; // readonly
	TRICIBLE_FORCEINLINE vec4 ptqs() const; // readonly
	TRICIBLE_FORCEINLINE swizzle4<vec4, float, 2, 1, 3, 0> ptqs(); // Assignable
	TRICIBLE_FORCEINLINE vec4 qtqs() const; // readonly
	TRICIBLE_FORCEINLINE vec4 spqs() const; // readonly
	TRICIBLE_FORCEINLINE vec4 tpqs() const; // readonly
	TRICIBLE_FORCEINLINE swizzle4<vec4, float, 1, 2, 3, 0> tpqs(); // Assignable
	TRICIBLE_FORCEINLINE vec4 ppqs() const; // readonly
	TRICIBLE_FORCEINLINE vec4 qpqs() const; // readonly
	TRICIBLE_FORCEINLINE vec4 sqqs() const; // readonly
	TRICIBLE_FORCEINLINE vec4 tqqs() const; // readonly
	TRICIBLE_FORCEINLINE vec4 pqqs() const; // readonly
	TRICIBLE_FORCEINLINE vec4 qqqs() const; // readonly
	TRICIBLE_FORCEINLINE vec4 ssst() const; // readonly
	TRICIBLE_FORCEINLINE vec4 tsst() const; // readonly
	TRICIBLE_FORCEINLINE vec4 psst() const; // readonly
	TRICIBLE_FORCEINLINE vec4 qsst() const; // readonly
	TRICIBLE_FORCEINLINE vec4 stst() const; // readonly
	TRICIBLE_FORCEINLINE vec4 ttst() const; // readonly
	TRICIBLE_FORCEINLINE vec4 ptst() const; // readonly
	TRICIBLE_FORCEINLINE vec4 qtst() const; // readonly
	TRICIBLE_FORCEINLINE vec4 spst() const; // readonly
	TRICIBLE_FORCEINLINE vec4 tpst() const; // readonly
	TRICIBLE_FORCEINLINE vec4 ppst() const; // readonly
	TRICIBLE_FORCEINLINE vec4 qpst() const; // readonly
	TRICIBLE_FORCEINLINE swizzle4<vec4, float, 3, 2, 0, 1> qpst(); // Assignable
	TRICIBLE_FORCEINLINE vec4 sqst() const; // readonly
	TRICIBLE_FORCEINLINE vec4 tqst() const; // readonly
	TRICIBLE_FORCEINLINE vec4 pqst() const; // readonly
	TRICIBLE_FORCEINLINE swizzle4<vec4, float, 2, 3, 0, 1> pqst(); // Assignable
	TRICIBLE_FORCEINLINE vec4 qqst() const; // readonly
	TRICIBLE_FORCEINLINE vec4 sstt() const; // readonly
	TRICIBLE_FORCEINLINE vec4 tstt() const; // readonly
	TRICIBLE_FORCEINLINE vec4 pstt() const; // readonly
	TRICIBLE_FORCEINLINE vec4 qstt() const; // readonly
	TRICIBLE_FORCEINLINE vec4 sttt() const; // readonly
	TRICIBLE_FORCEINLINE vec4 tttt() const; // readonly
	TRICIBLE_FORCEINLINE vec4 pttt() const; // readonly
	TRICIBLE_FORCEINLINE vec4 qttt() const; // readonly
	TRICIBLE_FORCEINLINE vec4 sptt() const; // readonly
	TRICIBLE_FORCEINLINE vec4 tptt() const; // readonly
	TRICIBLE_FORCEINLINE vec4 pptt() const; // readonly
	TRICIBLE_FORCEINLINE vec4 qptt() const; // readonly
	TRICIBLE_FORCEINLINE vec4 sqtt() const; // readonly
	TRICIBLE_FORCEINLINE vec4 tqtt() const; // readonly
	TRICIBLE_FORCEINLINE vec4 pqtt() const; // readonly
	TRICIBLE_FORCEINLINE vec4 qqtt() const; // readonly
	TRICIBLE_FORCEINLINE vec4 sspt() const; // readonly
	TRICIBLE_FORCEINLINE vec4 tspt() const; // readonly
	TRICIBLE_FORCEINLINE vec4 pspt() const; // readonly
	TRICIBLE_FORCEINLINE vec4 qspt() const; // readonly
	TRICIBLE_FORCEINLINE swizzle4<vec4, float, 3, 0, 2, 1> qspt(); // Assignable
	TRICIBLE_FORCEINLINE vec4 stpt() const; // readonly
	TRICIBLE_FORCEINLINE vec4 ttpt() const; // readonly
	TRICIBLE_FORCEINLINE vec4 ptpt() const; // readonly
	TRICIBLE_FORCEINLINE vec4 qtpt() const; // readonly
	TRICIBLE_FORCEINLINE vec4 sppt() const; // readonly
	TRICIBLE_FORCEINLINE vec4 tppt() const; // readonly
	TRICIBLE_FORCEINLINE vec4 pppt() const; // readonly
	TRICIBLE_FORCEINLINE vec4 qppt() const; // readonly
	TRICIBLE_FORCEINLINE vec4 sqpt() const; // readonly
	TRICIBLE_FORCEINLINE swizzle4<vec4, float, 0, 3, 2, 1> sqpt(); // Assignable
	TRICIBLE_FORCEINLINE vec4 tqpt() const; // readonly
	TRICIBLE_FORCEINLINE vec4 pqpt() const; // readonly
	TRICIBLE_FORCEINLINE vec4 qqpt() const; // readonly
	TRICIBLE_FORCEINLINE vec4 ssqt() const; // readonly
	TRICIBLE_FORCEINLINE vec4 tsqt() const; // readonly
	TRICIBLE_FORCEINLINE vec4 psqt() const; // readonly
	TRICIBLE_FORCEINLINE swizzle4<vec4, float, 2, 0, 3, 1> psqt(); // Assignable
	TRICIBLE_FORCEINLINE vec4 qsqt() const; // readonly
	TRICIBLE_FORCEINLINE vec4 stqt() const; // readonly
	TRICIBLE_FORCEINLINE vec4 ttqt() const; // readonly
	TRICIBLE_FORCEINLINE vec4 ptqt() const; // readonly
	TRICIBLE_FORCEINLINE vec4 qtqt() const; // readonly
	TRICIBLE_FORCEINLINE vec4 spqt() const; // readonly
	TRICIBLE_FORCEINLINE swizzle4<vec4, float, 0, 2, 3, 1> spqt(); // Assignable
	TRICIBLE_FORCEINLINE vec4 tpqt() const; // readonly
	TRICIBLE_FORCEINLINE vec4 ppqt() const; // readonly
	TRICIBLE_FORCEINLINE vec4 qpqt() const; // readonly
	TRICIBLE_FORCEINLINE vec4 sqqt() const; // readonly
	TRICIBLE_FORCEINLINE vec4 tqqt() const; // readonly
	TRICIBLE_FORCEINLINE vec4 pqqt() const; // readonly
	TRICIBLE_FORCEINLINE vec4 qqqt() const; // readonly
	TRICIBLE_FORCEINLINE vec4 sssp() const; // readonly
	TRICIBLE_FORCEINLINE vec4 tssp() const; // readonly
	TRICIBLE_FORCEINLINE vec4 pssp() const; // readonly
	TRICIBLE_FORCEINLINE vec4 qssp() const; // readonly
	TRICIBLE_FORCEINLINE vec4 stsp() const; // readonly
	TRICIBLE_FORCEINLINE vec4 ttsp() const; // readonly
	TRICIBLE_FORCEINLINE vec4 ptsp() const; // readonly
	TRICIBLE_FORCEINLINE vec4 qtsp() const; // readonly
	TRICIBLE_FORCEINLINE swizzle4<vec4, float, 3, 1, 0, 2> qtsp(); // Assignable
	TRICIBLE_FORCEINLINE vec4 spsp() const; // readonly
	TRICIBLE_FORCEINLINE vec4 tpsp() const; // readonly
	TRICIBLE_FORCEINLINE vec4 ppsp() const; // readonly
	TRICIBLE_FORCEINLINE vec4 qpsp() const; // readonly
	TRICIBLE_FORCEINLINE vec4 sqsp() const; // readonly
	TRICIBLE_FORCEINLINE vec4 tqsp() const; // readonly
	TRICIBLE_FORCEINLINE swizzle4<vec4, float, 1, 3, 0, 2> tqsp(); // Assignable
	TRICIBLE_FORCEINLINE vec4 pqsp() const; // readonly
	TRICIBLE_FORCEINLINE vec4 qqsp() const; // readonly
	TRICIBLE_FORCEINLINE vec4 sstp() const; // readonly
	TRICIBLE_FORCEINLINE vec4 tstp() const; // readonly
	TRICIBLE_FORCEINLINE vec4 pstp() const; // readonly
	TRICIBLE_FORCEINLINE vec4 qstp() const; // readonly
	TRICIBLE_FORCEINLINE swizzle4<vec4, float, 3, 0, 1, 2> qstp(); // Assignable
	TRICIBLE_FORCEINLINE vec4 sttp() const; // readonly
	TRICIBLE_FORCEINLINE vec4 tttp() const; // readonly
	TRICIBLE_FORCEINLINE vec4 pttp() const; // readonly
	TRICIBLE_FORCEINLINE vec4 qttp() const; // readonly
	TRICIBLE_FORCEINLINE vec4 sptp() const; // readonly
	TRICIBLE_FORCEINLINE vec4 tptp() const; // readonly
	TRICIBLE_FORCEINLINE vec4 pptp() const; // readonly
	TRICIBLE_FORCEINLINE vec4 qptp() const; // readonly
	TRICIBLE_FORCEINLINE vec4 sqtp() const; // readonly
	TRICIBLE_FORCEINLINE swizzle4<vec4, float, 0, 3, 1, 2> sqtp(); // Assignable
	TRICIBLE_FORCEINLINE vec4 tqtp() const; // readonly
	TRICIBLE_FORCEINLINE vec4 pqtp() const; // readonly
	TRICIBLE_FORCEINLINE vec4 qqtp() const; // readonly
	TRICIBLE_FORCEINLINE vec4 sspp() const; // readonly
	TRICIBLE_FORCEINLINE vec4 tspp() const; // readonly
	TRICIBLE_FORCEINLINE vec4 pspp() const; // readonly
	TRICIBLE_FORCEINLINE vec4 qspp() const; // readonly
	TRICIBLE_FORCEINLINE vec4 stpp() const; // readonly
	TRICIBLE_FORCEINLINE vec4 ttpp() const; // readonly
	TRICIBLE_FORCEINLINE vec4 ptpp() const; // readonly
	TRICIBLE_FORCEINLINE vec4 qtpp() const; // readonly
	TRICIBLE_FORCEINLINE vec4 sppp() const; // readonly
	TRICIBLE_FORCEINLINE vec4 tppp() const; // readonly
	TRICIBLE_FORCEINLINE vec4 pppp() const; // readonly
	TRICIBLE_FORCEINLINE vec4 qppp() const; // readonly
	TRICIBLE_FORCEINLINE vec4 sqpp() const; // readonly
	TRICIBLE_FORCEINLINE vec4 tqpp() const; // readonly
	TRICIBLE_FORCEINLINE vec4 pqpp() const; // readonly
	TRICIBLE_FORCEINLINE vec4 qqpp() const; // readonly
	TRICIBLE_FORCEINLINE vec4 ssqp() const; // readonly
	TRICIBLE_FORCEINLINE vec4 tsqp() const; // readonly
	TRICIBLE_FORCEINLINE swizzle4<vec4, float, 1, 0, 3, 2> tsqp(); // Assignable
	TRICIBLE_FORCEINLINE vec4 psqp() const; // readonly
	TRICIBLE_FORCEINLINE vec4 qsqp() const; // readonly
	TRICIBLE_FORCEINLINE vec4 stqp() const; // readonly
	TRICIBLE_FORCEINLINE swizzle4<vec4, float, 0, 1, 3, 2> stqp(); // Assignable
	TRICIBLE_FORCEINLINE vec4 ttqp() const; // readonly
	TRICIBLE_FORCEINLINE vec4 ptqp() const; // readonly
	TRICIBLE_FORCEINLINE vec4 qtqp() const; // readonly
	TRICIBLE_FORCEINLINE vec4 spqp() const; // readonly
	TRICIBLE_FORCEINLINE vec4 tpqp() const; // readonly
	TRICIBLE_FORCEINLINE vec4 ppqp() const; // readonly
	TRICIBLE_FORCEINLINE vec4 qpqp() const; // readonly
	TRICIBLE_FORCEINLINE vec4 sqqp() const; // readonly
	TRICIBLE_FORCEINLINE vec4 tqqp() const; // readonly
	TRICIBLE_FORCEINLINE vec4 pqqp() const; // readonly
	TRICIBLE_FORCEINLINE vec4 qqqp() const; // readonly
	TRICIBLE_FORCEINLINE vec4 sssq() const; // readonly
	TRICIBLE_FORCEINLINE vec4 tssq() const; // readonly
	TRICIBLE_FORCEINLINE vec4 pssq() const; // readonly
	TRICIBLE_FORCEINLINE vec4 qssq() const; // readonly
	TRICIBLE_FORCEINLINE vec4 stsq() const; // readonly
	TRICIBLE_FORCEINLINE vec4 ttsq() const; // readonly
	TRICIBLE_FORCEINLINE vec4 ptsq() const; // readonly
	TRICIBLE_FORCEINLINE swizzle4<vec4, float, 2, 1, 0, 3> ptsq(); // Assignable
	TRICIBLE_FORCEINLINE vec4 qtsq() const; // readonly
	TRICIBLE_FORCEINLINE vec4 spsq() const; // readonly
	TRICIBLE_FORCEINLINE vec4 tpsq() const; // readonly
	TRICIBLE_FORCEINLINE swizzle4<vec4, float, 1, 2, 0, 3> tpsq(); // Assignable
	TRICIBLE_FORCEINLINE vec4 ppsq() const; // readonly
	TRICIBLE_FORCEINLINE vec4 qpsq() const; // readonly
	TRICIBLE_FORCEINLINE vec4 sqsq() const; // readonly
	TRICIBLE_FORCEINLINE vec4 tqsq() const; // readonly
	TRICIBLE_FORCEINLINE vec4 pqsq() const; // readonly
	TRICIBLE_FORCEINLINE vec4 qqsq() const; // readonly
	TRICIBLE_FORCEINLINE vec4 sstq() const; // readonly
	TRICIBLE_FORCEINLINE vec4 tstq() const; // readonly
	TRICIBLE_FORCEINLINE vec4 pstq() const; // readonly
	TRICIBLE_FORCEINLINE swizzle4<vec4, float, 2, 0, 1, 3> pstq(); // Assignable
	TRICIBLE_FORCEINLINE vec4 qstq() const; // readonly
	TRICIBLE_FORCEINLINE vec4 sttq() const; // readonly
	TRICIBLE_FORCEINLINE vec4 tttq() const; // readonly
	TRICIBLE_FORCEINLINE vec4 pttq() const; // readonly
	TRICIBLE_FORCEINLINE vec4 qttq() const; // readonly
	TRICIBLE_FORCEINLINE vec4 sptq() const; // readonly
	TRICIBLE_FORCEINLINE swizzle4<vec4, float, 0, 2, 1, 3> sptq(); // Assignable
	TRICIBLE_FORCEINLINE vec4 tptq() const; // readonly
	TRICIBLE_FORCEINLINE vec4 pptq() const; // readonly
	TRICIBLE_FORCEINLINE vec4 qptq() const; // readonly
	TRICIBLE_FORCEINLINE vec4 sqtq() const; // readonly
	TRICIBLE_FORCEINLINE vec4 tqtq() const; // readonly
	TRICIBLE_FORCEINLINE vec4 pqtq() const; // readonly
	TRICIBLE_FORCEINLINE vec4 qqtq() const; // readonly
	TRICIBLE_FORCEINLINE vec4 sspq() const; // readonly
	TRICIBLE_FORCEINLINE vec4 tspq() const; // readonly
	TRICIBLE_FORCEINLINE swizzle4<vec4, float, 1, 0, 2, 3> tspq(); // Assignable
	TRICIBLE_FORCEINLINE vec4 pspq() const; // readonly
	TRICIBLE_FORCEINLINE vec4 qspq() const; // readonly
	TRICIBLE_FORCEINLINE vec4 stpq() const; // readonly
	TRICIBLE_FORCEINLINE swizzle4<vec4, float, 0, 1, 2, 3> stpq(); // Assignable
	TRICIBLE_FORCEINLINE vec4 ttpq() const; // readonly
	TRICIBLE_FORCEINLINE vec4 ptpq() const; // readonly
	TRICIBLE_FORCEINLINE vec4 qtpq() const; // readonly
	TRICIBLE_FORCEINLINE vec4 sppq() const; // readonly
	TRICIBLE_FORCEINLINE vec4 tppq() const; // readonly
	TRICIBLE_FORCEINLINE vec4 pppq() const; // readonly
	TRICIBLE_FORCEINLINE vec4 qppq() const; // readonly
	TRICIBLE_FORCEINLINE vec4 sqpq() const; // readonly
	TRICIBLE_FORCEINLINE vec4 tqpq() const; // readonly
	TRICIBLE_FORCEINLINE vec4 pqpq() const; // readonly
	TRICIBLE_FORCEINLINE vec4 qqpq() const; // readonly
	TRICIBLE_FORCEINLINE vec4 ssqq() const; // readonly
	TRICIBLE_FORCEINLINE vec4 tsqq() const; // readonly
	TRICIBLE_FORCEINLINE vec4 psqq() const; // readonly
	TRICIBLE_FORCEINLINE vec4 qsqq() const; // readonly
	TRICIBLE_FORCEINLINE vec4 stqq() const; // readonly
	TRICIBLE_FORCEINLINE vec4 ttqq() const; // readonly
	TRICIBLE_FORCEINLINE vec4 ptqq() const; // readonly
	TRICIBLE_FORCEINLINE vec4 qtqq() const; // readonly
	TRICIBLE_FORCEINLINE vec4 spqq() const; // readonly
	TRICIBLE_FORCEINLINE vec4 tpqq() const; // readonly
	TRICIBLE_FORCEINLINE vec4 ppqq() const; // readonly
	TRICIBLE_FORCEINLINE vec4 qpqq() const; // readonly
	TRICIBLE_FORCEINLINE vec4 sqqq() const; // readonly
	TRICIBLE_FORCEINLINE vec4 tqqq() const; // readonly
	TRICIBLE_FORCEINLINE vec4 pqqq() const; // readonly
	TRICIBLE_FORCEINLINE vec4 qqqq() const; // readonly
};


