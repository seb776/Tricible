#pragma once

#include <string>
#include "../Tools/Macros.hpp"

template<typename VecType, typename ScalarType, int A>
struct swizzle1;
template<typename VecType, typename ScalarType, int A, int B>
struct swizzle2;
template<typename VecType, typename ScalarType, int A, int B, int C>
struct swizzle3;
template<typename VecType, typename ScalarType, int A, int B, int C, int D>
struct swizzle4;

class vec2;

class vec3
{
	friend class vec4;
private:
	float _x;
	float _y;
	float _z;
public:
	vec3();
	vec3(const vec3& rhs);
	// TODO vec2 ctor
	explicit vec3(float x_, float y_, float z_);
	explicit vec3(float x_);

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

	TRICIBLE_FORCEINLINE vec3 operator-() const;
	TRICIBLE_FORCEINLINE vec3 operator+(const vec3& rhs) const;
	TRICIBLE_FORCEINLINE vec3 operator-(const vec3& rhs) const;
	TRICIBLE_FORCEINLINE vec3 operator*(const vec3& rhs) const;
	TRICIBLE_FORCEINLINE vec3 operator*(const float rhs) const;
	TRICIBLE_FORCEINLINE vec3 operator/(const vec3& rhs) const;
	TRICIBLE_FORCEINLINE vec3 operator/(const float rhs) const;

	TRICIBLE_FORCEINLINE vec3 operator=(const vec3& rhs);

	TRICIBLE_FORCEINLINE vec3 operator+=(const vec3& rhs);
	TRICIBLE_FORCEINLINE vec3 operator-=(const vec3& rhs);
	TRICIBLE_FORCEINLINE vec3 operator*=(const vec3& rhs);
	TRICIBLE_FORCEINLINE vec3 operator/=(const vec3& rhs);
	TRICIBLE_FORCEINLINE vec3 operator*=(const float rhs);
	TRICIBLE_FORCEINLINE vec3 operator/=(const float rhs);

	TRICIBLE_FORCEINLINE std::string ToString() const;
	unsigned int ToInt();

	// vec3 with 1 components.
	TRICIBLE_FORCEINLINE float x() const; // readonly
	TRICIBLE_FORCEINLINE swizzle1<vec3, float, 0> x(); // Assignable
	TRICIBLE_FORCEINLINE float y() const; // readonly
	TRICIBLE_FORCEINLINE swizzle1<vec3, float, 1> y(); // Assignable
	TRICIBLE_FORCEINLINE float z() const; // readonly
	TRICIBLE_FORCEINLINE swizzle1<vec3, float, 2> z(); // Assignable

	// vec3 with 2 components.
	TRICIBLE_FORCEINLINE vec2 xx() const; // readonly
	TRICIBLE_FORCEINLINE vec2 yx() const; // readonly
	TRICIBLE_FORCEINLINE swizzle2<vec3, float, 1, 0> yx(); // Assignable
	TRICIBLE_FORCEINLINE vec2 zx() const; // readonly
	TRICIBLE_FORCEINLINE swizzle2<vec3, float, 2, 0> zx(); // Assignable
	TRICIBLE_FORCEINLINE vec2 xy() const; // readonly
	TRICIBLE_FORCEINLINE swizzle2<vec3, float, 0, 1> xy(); // Assignable
	TRICIBLE_FORCEINLINE vec2 yy() const; // readonly
	TRICIBLE_FORCEINLINE vec2 zy() const; // readonly
	TRICIBLE_FORCEINLINE swizzle2<vec3, float, 2, 1> zy(); // Assignable
	TRICIBLE_FORCEINLINE vec2 xz() const; // readonly
	TRICIBLE_FORCEINLINE swizzle2<vec3, float, 0, 2> xz(); // Assignable
	TRICIBLE_FORCEINLINE vec2 yz() const; // readonly
	TRICIBLE_FORCEINLINE swizzle2<vec3, float, 1, 2> yz(); // Assignable
	TRICIBLE_FORCEINLINE vec2 zz() const; // readonly

	// vec3 with 3 components.
	TRICIBLE_FORCEINLINE vec3 xxx() const; // readonly
	TRICIBLE_FORCEINLINE vec3 yxx() const; // readonly
	TRICIBLE_FORCEINLINE vec3 zxx() const; // readonly
	TRICIBLE_FORCEINLINE vec3 xyx() const; // readonly
	TRICIBLE_FORCEINLINE vec3 yyx() const; // readonly
	TRICIBLE_FORCEINLINE vec3 zyx() const; // readonly
	TRICIBLE_FORCEINLINE swizzle3<vec3, float, 2, 1, 0> zyx(); // Assignable
	TRICIBLE_FORCEINLINE vec3 xzx() const; // readonly
	TRICIBLE_FORCEINLINE vec3 yzx() const; // readonly
	TRICIBLE_FORCEINLINE swizzle3<vec3, float, 1, 2, 0> yzx(); // Assignable
	TRICIBLE_FORCEINLINE vec3 zzx() const; // readonly
	TRICIBLE_FORCEINLINE vec3 xxy() const; // readonly
	TRICIBLE_FORCEINLINE vec3 yxy() const; // readonly
	TRICIBLE_FORCEINLINE vec3 zxy() const; // readonly
	TRICIBLE_FORCEINLINE swizzle3<vec3, float, 2, 0, 1> zxy(); // Assignable
	TRICIBLE_FORCEINLINE vec3 xyy() const; // readonly
	TRICIBLE_FORCEINLINE vec3 yyy() const; // readonly
	TRICIBLE_FORCEINLINE vec3 zyy() const; // readonly
	TRICIBLE_FORCEINLINE vec3 xzy() const; // readonly
	TRICIBLE_FORCEINLINE swizzle3<vec3, float, 0, 2, 1> xzy(); // Assignable
	TRICIBLE_FORCEINLINE vec3 yzy() const; // readonly
	TRICIBLE_FORCEINLINE vec3 zzy() const; // readonly
	TRICIBLE_FORCEINLINE vec3 xxz() const; // readonly
	TRICIBLE_FORCEINLINE vec3 yxz() const; // readonly
	TRICIBLE_FORCEINLINE swizzle3<vec3, float, 1, 0, 2> yxz(); // Assignable
	TRICIBLE_FORCEINLINE vec3 zxz() const; // readonly
	TRICIBLE_FORCEINLINE vec3 xyz() const; // readonly
	TRICIBLE_FORCEINLINE swizzle3<vec3, float, 0, 1, 2> xyz(); // Assignable
	TRICIBLE_FORCEINLINE vec3 yyz() const; // readonly
	TRICIBLE_FORCEINLINE vec3 zyz() const; // readonly
	TRICIBLE_FORCEINLINE vec3 xzz() const; // readonly
	TRICIBLE_FORCEINLINE vec3 yzz() const; // readonly
	TRICIBLE_FORCEINLINE vec3 zzz() const; // readonly

	// vec3 with 4 components.
	TRICIBLE_FORCEINLINE vec4 xxxx() const; // readonly
	TRICIBLE_FORCEINLINE vec4 yxxx() const; // readonly
	TRICIBLE_FORCEINLINE vec4 zxxx() const; // readonly
	TRICIBLE_FORCEINLINE vec4 xyxx() const; // readonly
	TRICIBLE_FORCEINLINE vec4 yyxx() const; // readonly
	TRICIBLE_FORCEINLINE vec4 zyxx() const; // readonly
	TRICIBLE_FORCEINLINE vec4 xzxx() const; // readonly
	TRICIBLE_FORCEINLINE vec4 yzxx() const; // readonly
	TRICIBLE_FORCEINLINE vec4 zzxx() const; // readonly
	TRICIBLE_FORCEINLINE vec4 xxyx() const; // readonly
	TRICIBLE_FORCEINLINE vec4 yxyx() const; // readonly
	TRICIBLE_FORCEINLINE vec4 zxyx() const; // readonly
	TRICIBLE_FORCEINLINE vec4 xyyx() const; // readonly
	TRICIBLE_FORCEINLINE vec4 yyyx() const; // readonly
	TRICIBLE_FORCEINLINE vec4 zyyx() const; // readonly
	TRICIBLE_FORCEINLINE vec4 xzyx() const; // readonly
	TRICIBLE_FORCEINLINE vec4 yzyx() const; // readonly
	TRICIBLE_FORCEINLINE vec4 zzyx() const; // readonly
	TRICIBLE_FORCEINLINE vec4 xxzx() const; // readonly
	TRICIBLE_FORCEINLINE vec4 yxzx() const; // readonly
	TRICIBLE_FORCEINLINE vec4 zxzx() const; // readonly
	TRICIBLE_FORCEINLINE vec4 xyzx() const; // readonly
	TRICIBLE_FORCEINLINE vec4 yyzx() const; // readonly
	TRICIBLE_FORCEINLINE vec4 zyzx() const; // readonly
	TRICIBLE_FORCEINLINE vec4 xzzx() const; // readonly
	TRICIBLE_FORCEINLINE vec4 yzzx() const; // readonly
	TRICIBLE_FORCEINLINE vec4 zzzx() const; // readonly
	TRICIBLE_FORCEINLINE vec4 xxxy() const; // readonly
	TRICIBLE_FORCEINLINE vec4 yxxy() const; // readonly
	TRICIBLE_FORCEINLINE vec4 zxxy() const; // readonly
	TRICIBLE_FORCEINLINE vec4 xyxy() const; // readonly
	TRICIBLE_FORCEINLINE vec4 yyxy() const; // readonly
	TRICIBLE_FORCEINLINE vec4 zyxy() const; // readonly
	TRICIBLE_FORCEINLINE vec4 xzxy() const; // readonly
	TRICIBLE_FORCEINLINE vec4 yzxy() const; // readonly
	TRICIBLE_FORCEINLINE vec4 zzxy() const; // readonly
	TRICIBLE_FORCEINLINE vec4 xxyy() const; // readonly
	TRICIBLE_FORCEINLINE vec4 yxyy() const; // readonly
	TRICIBLE_FORCEINLINE vec4 zxyy() const; // readonly
	TRICIBLE_FORCEINLINE vec4 xyyy() const; // readonly
	TRICIBLE_FORCEINLINE vec4 yyyy() const; // readonly
	TRICIBLE_FORCEINLINE vec4 zyyy() const; // readonly
	TRICIBLE_FORCEINLINE vec4 xzyy() const; // readonly
	TRICIBLE_FORCEINLINE vec4 yzyy() const; // readonly
	TRICIBLE_FORCEINLINE vec4 zzyy() const; // readonly
	TRICIBLE_FORCEINLINE vec4 xxzy() const; // readonly
	TRICIBLE_FORCEINLINE vec4 yxzy() const; // readonly
	TRICIBLE_FORCEINLINE vec4 zxzy() const; // readonly
	TRICIBLE_FORCEINLINE vec4 xyzy() const; // readonly
	TRICIBLE_FORCEINLINE vec4 yyzy() const; // readonly
	TRICIBLE_FORCEINLINE vec4 zyzy() const; // readonly
	TRICIBLE_FORCEINLINE vec4 xzzy() const; // readonly
	TRICIBLE_FORCEINLINE vec4 yzzy() const; // readonly
	TRICIBLE_FORCEINLINE vec4 zzzy() const; // readonly
	TRICIBLE_FORCEINLINE vec4 xxxz() const; // readonly
	TRICIBLE_FORCEINLINE vec4 yxxz() const; // readonly
	TRICIBLE_FORCEINLINE vec4 zxxz() const; // readonly
	TRICIBLE_FORCEINLINE vec4 xyxz() const; // readonly
	TRICIBLE_FORCEINLINE vec4 yyxz() const; // readonly
	TRICIBLE_FORCEINLINE vec4 zyxz() const; // readonly
	TRICIBLE_FORCEINLINE vec4 xzxz() const; // readonly
	TRICIBLE_FORCEINLINE vec4 yzxz() const; // readonly
	TRICIBLE_FORCEINLINE vec4 zzxz() const; // readonly
	TRICIBLE_FORCEINLINE vec4 xxyz() const; // readonly
	TRICIBLE_FORCEINLINE vec4 yxyz() const; // readonly
	TRICIBLE_FORCEINLINE vec4 zxyz() const; // readonly
	TRICIBLE_FORCEINLINE vec4 xyyz() const; // readonly
	TRICIBLE_FORCEINLINE vec4 yyyz() const; // readonly
	TRICIBLE_FORCEINLINE vec4 zyyz() const; // readonly
	TRICIBLE_FORCEINLINE vec4 xzyz() const; // readonly
	TRICIBLE_FORCEINLINE vec4 yzyz() const; // readonly
	TRICIBLE_FORCEINLINE vec4 zzyz() const; // readonly
	TRICIBLE_FORCEINLINE vec4 xxzz() const; // readonly
	TRICIBLE_FORCEINLINE vec4 yxzz() const; // readonly
	TRICIBLE_FORCEINLINE vec4 zxzz() const; // readonly
	TRICIBLE_FORCEINLINE vec4 xyzz() const; // readonly
	TRICIBLE_FORCEINLINE vec4 yyzz() const; // readonly
	TRICIBLE_FORCEINLINE vec4 zyzz() const; // readonly
	TRICIBLE_FORCEINLINE vec4 xzzz() const; // readonly
	TRICIBLE_FORCEINLINE vec4 yzzz() const; // readonly
	TRICIBLE_FORCEINLINE vec4 zzzz() const; // readonly

	// vec3 with 1 components.
	TRICIBLE_FORCEINLINE float r() const; // readonly
	TRICIBLE_FORCEINLINE swizzle1<vec3, float, 0> r(); // Assignable
	TRICIBLE_FORCEINLINE float g() const; // readonly
	TRICIBLE_FORCEINLINE swizzle1<vec3, float, 1> g(); // Assignable
	TRICIBLE_FORCEINLINE float b() const; // readonly
	TRICIBLE_FORCEINLINE swizzle1<vec3, float, 2> b(); // Assignable

	// vec3 with 2 components.
	TRICIBLE_FORCEINLINE vec2 rr() const; // readonly
	TRICIBLE_FORCEINLINE vec2 gr() const; // readonly
	TRICIBLE_FORCEINLINE swizzle2<vec3, float, 1, 0> gr(); // Assignable
	TRICIBLE_FORCEINLINE vec2 br() const; // readonly
	TRICIBLE_FORCEINLINE swizzle2<vec3, float, 2, 0> br(); // Assignable
	TRICIBLE_FORCEINLINE vec2 rg() const; // readonly
	TRICIBLE_FORCEINLINE swizzle2<vec3, float, 0, 1> rg(); // Assignable
	TRICIBLE_FORCEINLINE vec2 gg() const; // readonly
	TRICIBLE_FORCEINLINE vec2 bg() const; // readonly
	TRICIBLE_FORCEINLINE swizzle2<vec3, float, 2, 1> bg(); // Assignable
	TRICIBLE_FORCEINLINE vec2 rb() const; // readonly
	TRICIBLE_FORCEINLINE swizzle2<vec3, float, 0, 2> rb(); // Assignable
	TRICIBLE_FORCEINLINE vec2 gb() const; // readonly
	TRICIBLE_FORCEINLINE swizzle2<vec3, float, 1, 2> gb(); // Assignable
	TRICIBLE_FORCEINLINE vec2 bb() const; // readonly

	// vec3 with 3 components.
	TRICIBLE_FORCEINLINE vec3 rrr() const; // readonly
	TRICIBLE_FORCEINLINE vec3 grr() const; // readonly
	TRICIBLE_FORCEINLINE vec3 brr() const; // readonly
	TRICIBLE_FORCEINLINE vec3 rgr() const; // readonly
	TRICIBLE_FORCEINLINE vec3 ggr() const; // readonly
	TRICIBLE_FORCEINLINE vec3 bgr() const; // readonly
	TRICIBLE_FORCEINLINE swizzle3<vec3, float, 2, 1, 0> bgr(); // Assignable
	TRICIBLE_FORCEINLINE vec3 rbr() const; // readonly
	TRICIBLE_FORCEINLINE vec3 gbr() const; // readonly
	TRICIBLE_FORCEINLINE swizzle3<vec3, float, 1, 2, 0> gbr(); // Assignable
	TRICIBLE_FORCEINLINE vec3 bbr() const; // readonly
	TRICIBLE_FORCEINLINE vec3 rrg() const; // readonly
	TRICIBLE_FORCEINLINE vec3 grg() const; // readonly
	TRICIBLE_FORCEINLINE vec3 brg() const; // readonly
	TRICIBLE_FORCEINLINE swizzle3<vec3, float, 2, 0, 1> brg(); // Assignable
	TRICIBLE_FORCEINLINE vec3 rgg() const; // readonly
	TRICIBLE_FORCEINLINE vec3 ggg() const; // readonly
	TRICIBLE_FORCEINLINE vec3 bgg() const; // readonly
	TRICIBLE_FORCEINLINE vec3 rbg() const; // readonly
	TRICIBLE_FORCEINLINE swizzle3<vec3, float, 0, 2, 1> rbg(); // Assignable
	TRICIBLE_FORCEINLINE vec3 gbg() const; // readonly
	TRICIBLE_FORCEINLINE vec3 bbg() const; // readonly
	TRICIBLE_FORCEINLINE vec3 rrb() const; // readonly
	TRICIBLE_FORCEINLINE vec3 grb() const; // readonly
	TRICIBLE_FORCEINLINE swizzle3<vec3, float, 1, 0, 2> grb(); // Assignable
	TRICIBLE_FORCEINLINE vec3 brb() const; // readonly
	TRICIBLE_FORCEINLINE vec3 rgb() const; // readonly
	TRICIBLE_FORCEINLINE swizzle3<vec3, float, 0, 1, 2> rgb(); // Assignable
	TRICIBLE_FORCEINLINE vec3 ggb() const; // readonly
	TRICIBLE_FORCEINLINE vec3 bgb() const; // readonly
	TRICIBLE_FORCEINLINE vec3 rbb() const; // readonly
	TRICIBLE_FORCEINLINE vec3 gbb() const; // readonly
	TRICIBLE_FORCEINLINE vec3 bbb() const; // readonly

	// vec3 with 4 components.
	TRICIBLE_FORCEINLINE vec4 rrrr() const; // readonly
	TRICIBLE_FORCEINLINE vec4 grrr() const; // readonly
	TRICIBLE_FORCEINLINE vec4 brrr() const; // readonly
	TRICIBLE_FORCEINLINE vec4 rgrr() const; // readonly
	TRICIBLE_FORCEINLINE vec4 ggrr() const; // readonly
	TRICIBLE_FORCEINLINE vec4 bgrr() const; // readonly
	TRICIBLE_FORCEINLINE vec4 rbrr() const; // readonly
	TRICIBLE_FORCEINLINE vec4 gbrr() const; // readonly
	TRICIBLE_FORCEINLINE vec4 bbrr() const; // readonly
	TRICIBLE_FORCEINLINE vec4 rrgr() const; // readonly
	TRICIBLE_FORCEINLINE vec4 grgr() const; // readonly
	TRICIBLE_FORCEINLINE vec4 brgr() const; // readonly
	TRICIBLE_FORCEINLINE vec4 rggr() const; // readonly
	TRICIBLE_FORCEINLINE vec4 gggr() const; // readonly
	TRICIBLE_FORCEINLINE vec4 bggr() const; // readonly
	TRICIBLE_FORCEINLINE vec4 rbgr() const; // readonly
	TRICIBLE_FORCEINLINE vec4 gbgr() const; // readonly
	TRICIBLE_FORCEINLINE vec4 bbgr() const; // readonly
	TRICIBLE_FORCEINLINE vec4 rrbr() const; // readonly
	TRICIBLE_FORCEINLINE vec4 grbr() const; // readonly
	TRICIBLE_FORCEINLINE vec4 brbr() const; // readonly
	TRICIBLE_FORCEINLINE vec4 rgbr() const; // readonly
	TRICIBLE_FORCEINLINE vec4 ggbr() const; // readonly
	TRICIBLE_FORCEINLINE vec4 bgbr() const; // readonly
	TRICIBLE_FORCEINLINE vec4 rbbr() const; // readonly
	TRICIBLE_FORCEINLINE vec4 gbbr() const; // readonly
	TRICIBLE_FORCEINLINE vec4 bbbr() const; // readonly
	TRICIBLE_FORCEINLINE vec4 rrrg() const; // readonly
	TRICIBLE_FORCEINLINE vec4 grrg() const; // readonly
	TRICIBLE_FORCEINLINE vec4 brrg() const; // readonly
	TRICIBLE_FORCEINLINE vec4 rgrg() const; // readonly
	TRICIBLE_FORCEINLINE vec4 ggrg() const; // readonly
	TRICIBLE_FORCEINLINE vec4 bgrg() const; // readonly
	TRICIBLE_FORCEINLINE vec4 rbrg() const; // readonly
	TRICIBLE_FORCEINLINE vec4 gbrg() const; // readonly
	TRICIBLE_FORCEINLINE vec4 bbrg() const; // readonly
	TRICIBLE_FORCEINLINE vec4 rrgg() const; // readonly
	TRICIBLE_FORCEINLINE vec4 grgg() const; // readonly
	TRICIBLE_FORCEINLINE vec4 brgg() const; // readonly
	TRICIBLE_FORCEINLINE vec4 rggg() const; // readonly
	TRICIBLE_FORCEINLINE vec4 gggg() const; // readonly
	TRICIBLE_FORCEINLINE vec4 bggg() const; // readonly
	TRICIBLE_FORCEINLINE vec4 rbgg() const; // readonly
	TRICIBLE_FORCEINLINE vec4 gbgg() const; // readonly
	TRICIBLE_FORCEINLINE vec4 bbgg() const; // readonly
	TRICIBLE_FORCEINLINE vec4 rrbg() const; // readonly
	TRICIBLE_FORCEINLINE vec4 grbg() const; // readonly
	TRICIBLE_FORCEINLINE vec4 brbg() const; // readonly
	TRICIBLE_FORCEINLINE vec4 rgbg() const; // readonly
	TRICIBLE_FORCEINLINE vec4 ggbg() const; // readonly
	TRICIBLE_FORCEINLINE vec4 bgbg() const; // readonly
	TRICIBLE_FORCEINLINE vec4 rbbg() const; // readonly
	TRICIBLE_FORCEINLINE vec4 gbbg() const; // readonly
	TRICIBLE_FORCEINLINE vec4 bbbg() const; // readonly
	TRICIBLE_FORCEINLINE vec4 rrrb() const; // readonly
	TRICIBLE_FORCEINLINE vec4 grrb() const; // readonly
	TRICIBLE_FORCEINLINE vec4 brrb() const; // readonly
	TRICIBLE_FORCEINLINE vec4 rgrb() const; // readonly
	TRICIBLE_FORCEINLINE vec4 ggrb() const; // readonly
	TRICIBLE_FORCEINLINE vec4 bgrb() const; // readonly
	TRICIBLE_FORCEINLINE vec4 rbrb() const; // readonly
	TRICIBLE_FORCEINLINE vec4 gbrb() const; // readonly
	TRICIBLE_FORCEINLINE vec4 bbrb() const; // readonly
	TRICIBLE_FORCEINLINE vec4 rrgb() const; // readonly
	TRICIBLE_FORCEINLINE vec4 grgb() const; // readonly
	TRICIBLE_FORCEINLINE vec4 brgb() const; // readonly
	TRICIBLE_FORCEINLINE vec4 rggb() const; // readonly
	TRICIBLE_FORCEINLINE vec4 gggb() const; // readonly
	TRICIBLE_FORCEINLINE vec4 bggb() const; // readonly
	TRICIBLE_FORCEINLINE vec4 rbgb() const; // readonly
	TRICIBLE_FORCEINLINE vec4 gbgb() const; // readonly
	TRICIBLE_FORCEINLINE vec4 bbgb() const; // readonly
	TRICIBLE_FORCEINLINE vec4 rrbb() const; // readonly
	TRICIBLE_FORCEINLINE vec4 grbb() const; // readonly
	TRICIBLE_FORCEINLINE vec4 brbb() const; // readonly
	TRICIBLE_FORCEINLINE vec4 rgbb() const; // readonly
	TRICIBLE_FORCEINLINE vec4 ggbb() const; // readonly
	TRICIBLE_FORCEINLINE vec4 bgbb() const; // readonly
	TRICIBLE_FORCEINLINE vec4 rbbb() const; // readonly
	TRICIBLE_FORCEINLINE vec4 gbbb() const; // readonly
	TRICIBLE_FORCEINLINE vec4 bbbb() const; // readonly

	// vec3 with 1 components.
	TRICIBLE_FORCEINLINE float s() const; // readonly
	TRICIBLE_FORCEINLINE swizzle1<vec3, float, 0> s(); // Assignable
	TRICIBLE_FORCEINLINE float t() const; // readonly
	TRICIBLE_FORCEINLINE swizzle1<vec3, float, 1> t(); // Assignable
	TRICIBLE_FORCEINLINE float p() const; // readonly
	TRICIBLE_FORCEINLINE swizzle1<vec3, float, 2> p(); // Assignable

	// vec3 with 2 components.
	TRICIBLE_FORCEINLINE vec2 ss() const; // readonly
	TRICIBLE_FORCEINLINE vec2 ts() const; // readonly
	TRICIBLE_FORCEINLINE swizzle2<vec3, float, 1, 0> ts(); // Assignable
	TRICIBLE_FORCEINLINE vec2 ps() const; // readonly
	TRICIBLE_FORCEINLINE swizzle2<vec3, float, 2, 0> ps(); // Assignable
	TRICIBLE_FORCEINLINE vec2 st() const; // readonly
	TRICIBLE_FORCEINLINE swizzle2<vec3, float, 0, 1> st(); // Assignable
	TRICIBLE_FORCEINLINE vec2 tt() const; // readonly
	TRICIBLE_FORCEINLINE vec2 pt() const; // readonly
	TRICIBLE_FORCEINLINE swizzle2<vec3, float, 2, 1> pt(); // Assignable
	TRICIBLE_FORCEINLINE vec2 sp() const; // readonly
	TRICIBLE_FORCEINLINE swizzle2<vec3, float, 0, 2> sp(); // Assignable
	TRICIBLE_FORCEINLINE vec2 tp() const; // readonly
	TRICIBLE_FORCEINLINE swizzle2<vec3, float, 1, 2> tp(); // Assignable
	TRICIBLE_FORCEINLINE vec2 pp() const; // readonly

	// vec3 with 3 components.
	TRICIBLE_FORCEINLINE vec3 sss() const; // readonly
	TRICIBLE_FORCEINLINE vec3 tss() const; // readonly
	TRICIBLE_FORCEINLINE vec3 pss() const; // readonly
	TRICIBLE_FORCEINLINE vec3 sts() const; // readonly
	TRICIBLE_FORCEINLINE vec3 tts() const; // readonly
	TRICIBLE_FORCEINLINE vec3 pts() const; // readonly
	TRICIBLE_FORCEINLINE swizzle3<vec3, float, 2, 1, 0> pts(); // Assignable
	TRICIBLE_FORCEINLINE vec3 sps() const; // readonly
	TRICIBLE_FORCEINLINE vec3 tps() const; // readonly
	TRICIBLE_FORCEINLINE swizzle3<vec3, float, 1, 2, 0> tps(); // Assignable
	TRICIBLE_FORCEINLINE vec3 pps() const; // readonly
	TRICIBLE_FORCEINLINE vec3 sst() const; // readonly
	TRICIBLE_FORCEINLINE vec3 tst() const; // readonly
	TRICIBLE_FORCEINLINE vec3 pst() const; // readonly
	TRICIBLE_FORCEINLINE swizzle3<vec3, float, 2, 0, 1> pst(); // Assignable
	TRICIBLE_FORCEINLINE vec3 stt() const; // readonly
	TRICIBLE_FORCEINLINE vec3 ttt() const; // readonly
	TRICIBLE_FORCEINLINE vec3 ptt() const; // readonly
	TRICIBLE_FORCEINLINE vec3 spt() const; // readonly
	TRICIBLE_FORCEINLINE swizzle3<vec3, float, 0, 2, 1> spt(); // Assignable
	TRICIBLE_FORCEINLINE vec3 tpt() const; // readonly
	TRICIBLE_FORCEINLINE vec3 ppt() const; // readonly
	TRICIBLE_FORCEINLINE vec3 ssp() const; // readonly
	TRICIBLE_FORCEINLINE vec3 tsp() const; // readonly
	TRICIBLE_FORCEINLINE swizzle3<vec3, float, 1, 0, 2> tsp(); // Assignable
	TRICIBLE_FORCEINLINE vec3 psp() const; // readonly
	TRICIBLE_FORCEINLINE vec3 stp() const; // readonly
	TRICIBLE_FORCEINLINE swizzle3<vec3, float, 0, 1, 2> stp(); // Assignable
	TRICIBLE_FORCEINLINE vec3 ttp() const; // readonly
	TRICIBLE_FORCEINLINE vec3 ptp() const; // readonly
	TRICIBLE_FORCEINLINE vec3 spp() const; // readonly
	TRICIBLE_FORCEINLINE vec3 tpp() const; // readonly
	TRICIBLE_FORCEINLINE vec3 ppp() const; // readonly

	// vec3 with 4 components.
	TRICIBLE_FORCEINLINE vec4 ssss() const; // readonly
	TRICIBLE_FORCEINLINE vec4 tsss() const; // readonly
	TRICIBLE_FORCEINLINE vec4 psss() const; // readonly
	TRICIBLE_FORCEINLINE vec4 stss() const; // readonly
	TRICIBLE_FORCEINLINE vec4 ttss() const; // readonly
	TRICIBLE_FORCEINLINE vec4 ptss() const; // readonly
	TRICIBLE_FORCEINLINE vec4 spss() const; // readonly
	TRICIBLE_FORCEINLINE vec4 tpss() const; // readonly
	TRICIBLE_FORCEINLINE vec4 ppss() const; // readonly
	TRICIBLE_FORCEINLINE vec4 ssts() const; // readonly
	TRICIBLE_FORCEINLINE vec4 tsts() const; // readonly
	TRICIBLE_FORCEINLINE vec4 psts() const; // readonly
	TRICIBLE_FORCEINLINE vec4 stts() const; // readonly
	TRICIBLE_FORCEINLINE vec4 ttts() const; // readonly
	TRICIBLE_FORCEINLINE vec4 ptts() const; // readonly
	TRICIBLE_FORCEINLINE vec4 spts() const; // readonly
	TRICIBLE_FORCEINLINE vec4 tpts() const; // readonly
	TRICIBLE_FORCEINLINE vec4 ppts() const; // readonly
	TRICIBLE_FORCEINLINE vec4 ssps() const; // readonly
	TRICIBLE_FORCEINLINE vec4 tsps() const; // readonly
	TRICIBLE_FORCEINLINE vec4 psps() const; // readonly
	TRICIBLE_FORCEINLINE vec4 stps() const; // readonly
	TRICIBLE_FORCEINLINE vec4 ttps() const; // readonly
	TRICIBLE_FORCEINLINE vec4 ptps() const; // readonly
	TRICIBLE_FORCEINLINE vec4 spps() const; // readonly
	TRICIBLE_FORCEINLINE vec4 tpps() const; // readonly
	TRICIBLE_FORCEINLINE vec4 ppps() const; // readonly
	TRICIBLE_FORCEINLINE vec4 ssst() const; // readonly
	TRICIBLE_FORCEINLINE vec4 tsst() const; // readonly
	TRICIBLE_FORCEINLINE vec4 psst() const; // readonly
	TRICIBLE_FORCEINLINE vec4 stst() const; // readonly
	TRICIBLE_FORCEINLINE vec4 ttst() const; // readonly
	TRICIBLE_FORCEINLINE vec4 ptst() const; // readonly
	TRICIBLE_FORCEINLINE vec4 spst() const; // readonly
	TRICIBLE_FORCEINLINE vec4 tpst() const; // readonly
	TRICIBLE_FORCEINLINE vec4 ppst() const; // readonly
	TRICIBLE_FORCEINLINE vec4 sstt() const; // readonly
	TRICIBLE_FORCEINLINE vec4 tstt() const; // readonly
	TRICIBLE_FORCEINLINE vec4 pstt() const; // readonly
	TRICIBLE_FORCEINLINE vec4 sttt() const; // readonly
	TRICIBLE_FORCEINLINE vec4 tttt() const; // readonly
	TRICIBLE_FORCEINLINE vec4 pttt() const; // readonly
	TRICIBLE_FORCEINLINE vec4 sptt() const; // readonly
	TRICIBLE_FORCEINLINE vec4 tptt() const; // readonly
	TRICIBLE_FORCEINLINE vec4 pptt() const; // readonly
	TRICIBLE_FORCEINLINE vec4 sspt() const; // readonly
	TRICIBLE_FORCEINLINE vec4 tspt() const; // readonly
	TRICIBLE_FORCEINLINE vec4 pspt() const; // readonly
	TRICIBLE_FORCEINLINE vec4 stpt() const; // readonly
	TRICIBLE_FORCEINLINE vec4 ttpt() const; // readonly
	TRICIBLE_FORCEINLINE vec4 ptpt() const; // readonly
	TRICIBLE_FORCEINLINE vec4 sppt() const; // readonly
	TRICIBLE_FORCEINLINE vec4 tppt() const; // readonly
	TRICIBLE_FORCEINLINE vec4 pppt() const; // readonly
	TRICIBLE_FORCEINLINE vec4 sssp() const; // readonly
	TRICIBLE_FORCEINLINE vec4 tssp() const; // readonly
	TRICIBLE_FORCEINLINE vec4 pssp() const; // readonly
	TRICIBLE_FORCEINLINE vec4 stsp() const; // readonly
	TRICIBLE_FORCEINLINE vec4 ttsp() const; // readonly
	TRICIBLE_FORCEINLINE vec4 ptsp() const; // readonly
	TRICIBLE_FORCEINLINE vec4 spsp() const; // readonly
	TRICIBLE_FORCEINLINE vec4 tpsp() const; // readonly
	TRICIBLE_FORCEINLINE vec4 ppsp() const; // readonly
	TRICIBLE_FORCEINLINE vec4 sstp() const; // readonly
	TRICIBLE_FORCEINLINE vec4 tstp() const; // readonly
	TRICIBLE_FORCEINLINE vec4 pstp() const; // readonly
	TRICIBLE_FORCEINLINE vec4 sttp() const; // readonly
	TRICIBLE_FORCEINLINE vec4 tttp() const; // readonly
	TRICIBLE_FORCEINLINE vec4 pttp() const; // readonly
	TRICIBLE_FORCEINLINE vec4 sptp() const; // readonly
	TRICIBLE_FORCEINLINE vec4 tptp() const; // readonly
	TRICIBLE_FORCEINLINE vec4 pptp() const; // readonly
	TRICIBLE_FORCEINLINE vec4 sspp() const; // readonly
	TRICIBLE_FORCEINLINE vec4 tspp() const; // readonly
	TRICIBLE_FORCEINLINE vec4 pspp() const; // readonly
	TRICIBLE_FORCEINLINE vec4 stpp() const; // readonly
	TRICIBLE_FORCEINLINE vec4 ttpp() const; // readonly
	TRICIBLE_FORCEINLINE vec4 ptpp() const; // readonly
	TRICIBLE_FORCEINLINE vec4 sppp() const; // readonly
	TRICIBLE_FORCEINLINE vec4 tppp() const; // readonly
	TRICIBLE_FORCEINLINE vec4 pppp() const; // readonly
};


