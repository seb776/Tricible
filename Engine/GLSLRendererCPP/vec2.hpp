#pragma once

#include <string>
#include "../Tools/Macros.hpp"
#include "SwizzleProxies.hpp"

class vec2
{
	friend class vec4;
private:
	float _x;
	float _y;
public:
	vec2();
	vec2(const vec2& rhs);
	explicit vec2(float x_, float y_);
	explicit vec2(float x_);

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

	TRICIBLE_FORCEINLINE vec2 operator-() const;
	TRICIBLE_FORCEINLINE vec2 operator+(const vec2& rhs) const;
	TRICIBLE_FORCEINLINE vec2 operator-(const vec2& rhs) const;
	TRICIBLE_FORCEINLINE vec2 operator*(const vec2& rhs) const;
	TRICIBLE_FORCEINLINE vec2 operator*(const float rhs) const;
	TRICIBLE_FORCEINLINE vec2 operator/(const vec2& rhs) const;
	TRICIBLE_FORCEINLINE vec2 operator/(const float rhs) const;

	TRICIBLE_FORCEINLINE vec2 operator=(const vec2& rhs);

	TRICIBLE_FORCEINLINE vec2 operator+=(const vec2& rhs);
	TRICIBLE_FORCEINLINE vec2 operator-=(const vec2& rhs);
	TRICIBLE_FORCEINLINE vec2 operator*=(const vec2& rhs);
	TRICIBLE_FORCEINLINE vec2 operator/=(const vec2& rhs);
	TRICIBLE_FORCEINLINE vec2 operator*=(const float rhs);
	TRICIBLE_FORCEINLINE vec2 operator/=(const float rhs);

	TRICIBLE_FORCEINLINE std::string ToString() const;

	// vec2 with 1 components.
	TRICIBLE_FORCEINLINE float x() const; // readonly
	TRICIBLE_FORCEINLINE swizzle1<vec2, float, 0> x(); // Assignable
	TRICIBLE_FORCEINLINE float y() const; // readonly
	TRICIBLE_FORCEINLINE swizzle1<vec2, float, 1> y(); // Assignable

	// vec2 with 2 components.
	TRICIBLE_FORCEINLINE vec2 xx() const; // readonly
	TRICIBLE_FORCEINLINE vec2 yx() const; // readonly
	TRICIBLE_FORCEINLINE swizzle2<vec2, float, 1, 0> yx(); // Assignable
	TRICIBLE_FORCEINLINE vec2 xy() const; // readonly
	TRICIBLE_FORCEINLINE swizzle2<vec2, float, 0, 1> xy(); // Assignable
	TRICIBLE_FORCEINLINE vec2 yy() const; // readonly

	// vec2 with 3 components.
	TRICIBLE_FORCEINLINE vec3 xxx() const; // readonly
	TRICIBLE_FORCEINLINE vec3 yxx() const; // readonly
	TRICIBLE_FORCEINLINE vec3 xyx() const; // readonly
	TRICIBLE_FORCEINLINE vec3 yyx() const; // readonly
	TRICIBLE_FORCEINLINE vec3 xxy() const; // readonly
	TRICIBLE_FORCEINLINE vec3 yxy() const; // readonly
	TRICIBLE_FORCEINLINE vec3 xyy() const; // readonly
	TRICIBLE_FORCEINLINE vec3 yyy() const; // readonly

	// vec2 with 4 components.
	TRICIBLE_FORCEINLINE vec4 xxxx() const; // readonly
	TRICIBLE_FORCEINLINE vec4 yxxx() const; // readonly
	TRICIBLE_FORCEINLINE vec4 xyxx() const; // readonly
	TRICIBLE_FORCEINLINE vec4 yyxx() const; // readonly
	TRICIBLE_FORCEINLINE vec4 xxyx() const; // readonly
	TRICIBLE_FORCEINLINE vec4 yxyx() const; // readonly
	TRICIBLE_FORCEINLINE vec4 xyyx() const; // readonly
	TRICIBLE_FORCEINLINE vec4 yyyx() const; // readonly
	TRICIBLE_FORCEINLINE vec4 xxxy() const; // readonly
	TRICIBLE_FORCEINLINE vec4 yxxy() const; // readonly
	TRICIBLE_FORCEINLINE vec4 xyxy() const; // readonly
	TRICIBLE_FORCEINLINE vec4 yyxy() const; // readonly
	TRICIBLE_FORCEINLINE vec4 xxyy() const; // readonly
	TRICIBLE_FORCEINLINE vec4 yxyy() const; // readonly
	TRICIBLE_FORCEINLINE vec4 xyyy() const; // readonly
	TRICIBLE_FORCEINLINE vec4 yyyy() const; // readonly

	// vec2 with 1 components.
	TRICIBLE_FORCEINLINE float r() const; // readonly
	TRICIBLE_FORCEINLINE swizzle1<vec2, float, 0> r(); // Assignable
	TRICIBLE_FORCEINLINE float g() const; // readonly
	TRICIBLE_FORCEINLINE swizzle1<vec2, float, 1> g(); // Assignable

	// vec2 with 2 components.
	TRICIBLE_FORCEINLINE vec2 rr() const; // readonly
	TRICIBLE_FORCEINLINE vec2 gr() const; // readonly
	TRICIBLE_FORCEINLINE swizzle2<vec2, float, 1, 0> gr(); // Assignable
	TRICIBLE_FORCEINLINE vec2 rg() const; // readonly
	TRICIBLE_FORCEINLINE swizzle2<vec2, float, 0, 1> rg(); // Assignable
	TRICIBLE_FORCEINLINE vec2 gg() const; // readonly

	// vec2 with 3 components.
	TRICIBLE_FORCEINLINE vec3 rrr() const; // readonly
	TRICIBLE_FORCEINLINE vec3 grr() const; // readonly
	TRICIBLE_FORCEINLINE vec3 rgr() const; // readonly
	TRICIBLE_FORCEINLINE vec3 ggr() const; // readonly
	TRICIBLE_FORCEINLINE vec3 rrg() const; // readonly
	TRICIBLE_FORCEINLINE vec3 grg() const; // readonly
	TRICIBLE_FORCEINLINE vec3 rgg() const; // readonly
	TRICIBLE_FORCEINLINE vec3 ggg() const; // readonly

	// vec2 with 4 components.
	TRICIBLE_FORCEINLINE vec4 rrrr() const; // readonly
	TRICIBLE_FORCEINLINE vec4 grrr() const; // readonly
	TRICIBLE_FORCEINLINE vec4 rgrr() const; // readonly
	TRICIBLE_FORCEINLINE vec4 ggrr() const; // readonly
	TRICIBLE_FORCEINLINE vec4 rrgr() const; // readonly
	TRICIBLE_FORCEINLINE vec4 grgr() const; // readonly
	TRICIBLE_FORCEINLINE vec4 rggr() const; // readonly
	TRICIBLE_FORCEINLINE vec4 gggr() const; // readonly
	TRICIBLE_FORCEINLINE vec4 rrrg() const; // readonly
	TRICIBLE_FORCEINLINE vec4 grrg() const; // readonly
	TRICIBLE_FORCEINLINE vec4 rgrg() const; // readonly
	TRICIBLE_FORCEINLINE vec4 ggrg() const; // readonly
	TRICIBLE_FORCEINLINE vec4 rrgg() const; // readonly
	TRICIBLE_FORCEINLINE vec4 grgg() const; // readonly
	TRICIBLE_FORCEINLINE vec4 rggg() const; // readonly
	TRICIBLE_FORCEINLINE vec4 gggg() const; // readonly

	// vec2 with 1 components.
	TRICIBLE_FORCEINLINE float s() const; // readonly
	TRICIBLE_FORCEINLINE swizzle1<vec2, float, 0> s(); // Assignable
	TRICIBLE_FORCEINLINE float t() const; // readonly
	TRICIBLE_FORCEINLINE swizzle1<vec2, float, 1> t(); // Assignable

	// vec2 with 2 components.
	TRICIBLE_FORCEINLINE vec2 ss() const; // readonly
	TRICIBLE_FORCEINLINE vec2 ts() const; // readonly
	TRICIBLE_FORCEINLINE swizzle2<vec2, float, 1, 0> ts(); // Assignable
	TRICIBLE_FORCEINLINE vec2 st() const; // readonly
	TRICIBLE_FORCEINLINE swizzle2<vec2, float, 0, 1> st(); // Assignable
	TRICIBLE_FORCEINLINE vec2 tt() const; // readonly

	// vec2 with 3 components.
	TRICIBLE_FORCEINLINE vec3 sss() const; // readonly
	TRICIBLE_FORCEINLINE vec3 tss() const; // readonly
	TRICIBLE_FORCEINLINE vec3 sts() const; // readonly
	TRICIBLE_FORCEINLINE vec3 tts() const; // readonly
	TRICIBLE_FORCEINLINE vec3 sst() const; // readonly
	TRICIBLE_FORCEINLINE vec3 tst() const; // readonly
	TRICIBLE_FORCEINLINE vec3 stt() const; // readonly
	TRICIBLE_FORCEINLINE vec3 ttt() const; // readonly

	// vec2 with 4 components.
	TRICIBLE_FORCEINLINE vec4 ssss() const; // readonly
	TRICIBLE_FORCEINLINE vec4 tsss() const; // readonly
	TRICIBLE_FORCEINLINE vec4 stss() const; // readonly
	TRICIBLE_FORCEINLINE vec4 ttss() const; // readonly
	TRICIBLE_FORCEINLINE vec4 ssts() const; // readonly
	TRICIBLE_FORCEINLINE vec4 tsts() const; // readonly
	TRICIBLE_FORCEINLINE vec4 stts() const; // readonly
	TRICIBLE_FORCEINLINE vec4 ttts() const; // readonly
	TRICIBLE_FORCEINLINE vec4 ssst() const; // readonly
	TRICIBLE_FORCEINLINE vec4 tsst() const; // readonly
	TRICIBLE_FORCEINLINE vec4 stst() const; // readonly
	TRICIBLE_FORCEINLINE vec4 ttst() const; // readonly
	TRICIBLE_FORCEINLINE vec4 sstt() const; // readonly
	TRICIBLE_FORCEINLINE vec4 tstt() const; // readonly
	TRICIBLE_FORCEINLINE vec4 sttt() const; // readonly
	TRICIBLE_FORCEINLINE vec4 tttt() const; // readonly
};


