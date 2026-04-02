#include <sstream>
#include "GLSLFunctions.hpp"
#include "vec3.hpp"

vec3::vec3() :
	vec3(0.0f)
{
}
vec3::vec3(const vec3& rhs)
{
	*this = rhs;
}
vec3::vec3(float x_, float y_, float z_)
{
	_x = x_;
	_y = y_;
	_z = z_;
}
vec3::vec3(float x_) :
	vec3(x_, x_, x_)
{
}


TRICIBLE_FORCEINLINE vec3 vec3::operator-() const
{
	return vec3(-this->_x, -this->_y, -this->_z);
}

TRICIBLE_FORCEINLINE vec3 vec3::operator+(const vec3& rhs) const
{
	return vec3(_x + rhs._x, _y + rhs._y, _z + rhs._z);
}

TRICIBLE_FORCEINLINE vec3 vec3::operator-(const vec3& rhs) const
{
	return vec3(_x - rhs._x, _y - rhs._y, _z - rhs._z);
}

TRICIBLE_FORCEINLINE vec3 vec3::operator*(const vec3& rhs) const
{
	return vec3(_x * rhs._x, _y * rhs._y, _z * rhs._z);
}

TRICIBLE_FORCEINLINE vec3 vec3::operator*(const float rhs) const
{
	return vec3(_x * rhs, _y * rhs, _z * rhs);
}

TRICIBLE_FORCEINLINE vec3 vec3::operator/(const vec3& rhs) const
{
	return vec3(_x / rhs._x, _y / rhs._y, _z / rhs._z);
}
TRICIBLE_FORCEINLINE vec3 vec3::operator/(const float rhs) const
{
	return vec3(_x / rhs, _y / rhs, _z / rhs);
}

TRICIBLE_FORCEINLINE vec3 vec3::operator=(const vec3& rhs)
{
	this->_x = rhs._x;
	this->_y = rhs._y;
	this->_z = rhs._z;
	return *this;
}

TRICIBLE_FORCEINLINE vec3 vec3::operator+=(const vec3& rhs)
{
	this->_x += rhs._x;
	this->_y += rhs._y;
	this->_z += rhs._z;
	return *this;
}

TRICIBLE_FORCEINLINE vec3 vec3::operator-=(const vec3& rhs)
{
	this->_x -= rhs._x;
	this->_y -= rhs._y;
	this->_z -= rhs._z;
	return *this;
}

TRICIBLE_FORCEINLINE vec3 vec3::operator*=(const vec3& rhs)
{
	this->_x *= rhs._x;
	this->_y *= rhs._y;
	this->_z *= rhs._z;
	return *this;
}
TRICIBLE_FORCEINLINE vec3 vec3::operator/=(const vec3& rhs)
{
	this->_x /= rhs._x;
	this->_y /= rhs._y;
	this->_z /= rhs._z;
	return *this;
}
TRICIBLE_FORCEINLINE vec3 vec3::operator*=(const float rhs)
{
	this->_x *= rhs;
	this->_y *= rhs;
	this->_z *= rhs;
	return *this;
}
TRICIBLE_FORCEINLINE vec3 vec3::operator/=(const float rhs)
{
	this->_x /= rhs;
	this->_y /= rhs;
	this->_z /= rhs;
	return *this;
}


TRICIBLE_FORCEINLINE std::string vec3::ToString() const
{
	std::stringstream ss;
	ss << "(" << _x << ", " << _y << ", " << _z << ")";
	return ss.str();
}

unsigned int vec3::ToInt()
{
	//return (_red << 24) + (_green << 16) + (_blue << 8) + 0xFF;
	return 0xFF000000 +
		clamp((uint)(_x * 255.0f), (uint)0, (uint)0xFF) +
		(clamp((uint)(_y * 255.0f), (uint)0, (uint)0xFF) << 8) +
		(clamp((uint)(_z * 255.0f), (uint)0, (uint)0xFF) << 16);
}

TRICIBLE_FORCEINLINE float vec3::x() const { return this->_x; } // readonly
TRICIBLE_FORCEINLINE swizzle1<vec3, float, 0> vec3::x() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE float vec3::y() const { return this->_y; } // readonly
TRICIBLE_FORCEINLINE swizzle1<vec3, float, 1> vec3::y() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE float vec3::z() const { return this->_z; } // readonly
TRICIBLE_FORCEINLINE swizzle1<vec3, float, 2> vec3::z() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec2 vec3::xx() const { return vec2(this->_x, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec2 vec3::yx() const { return vec2(this->_y, this->_x); } // readonly
TRICIBLE_FORCEINLINE swizzle2<vec3, float, 1, 0> vec3::yx() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec2 vec3::zx() const { return vec2(this->_z, this->_x); } // readonly
TRICIBLE_FORCEINLINE swizzle2<vec3, float, 2, 0> vec3::zx() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec2 vec3::xy() const { return vec2(this->_x, this->_y); } // readonly
TRICIBLE_FORCEINLINE swizzle2<vec3, float, 0, 1> vec3::xy() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec2 vec3::yy() const { return vec2(this->_y, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec2 vec3::zy() const { return vec2(this->_z, this->_y); } // readonly
TRICIBLE_FORCEINLINE swizzle2<vec3, float, 2, 1> vec3::zy() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec2 vec3::xz() const { return vec2(this->_x, this->_z); } // readonly
TRICIBLE_FORCEINLINE swizzle2<vec3, float, 0, 2> vec3::xz() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec2 vec3::yz() const { return vec2(this->_y, this->_z); } // readonly
TRICIBLE_FORCEINLINE swizzle2<vec3, float, 1, 2> vec3::yz() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec2 vec3::zz() const { return vec2(this->_z, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec3 vec3::xxx() const { return vec3(this->_x, this->_x, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec3 vec3::yxx() const { return vec3(this->_y, this->_x, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec3 vec3::zxx() const { return vec3(this->_z, this->_x, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec3 vec3::xyx() const { return vec3(this->_x, this->_y, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec3 vec3::yyx() const { return vec3(this->_y, this->_y, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec3 vec3::zyx() const { return vec3(this->_z, this->_y, this->_x); } // readonly
TRICIBLE_FORCEINLINE swizzle3<vec3, float, 2, 1, 0> vec3::zyx() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec3 vec3::xzx() const { return vec3(this->_x, this->_z, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec3 vec3::yzx() const { return vec3(this->_y, this->_z, this->_x); } // readonly
TRICIBLE_FORCEINLINE swizzle3<vec3, float, 1, 2, 0> vec3::yzx() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec3 vec3::zzx() const { return vec3(this->_z, this->_z, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec3 vec3::xxy() const { return vec3(this->_x, this->_x, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec3 vec3::yxy() const { return vec3(this->_y, this->_x, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec3 vec3::zxy() const { return vec3(this->_z, this->_x, this->_y); } // readonly
TRICIBLE_FORCEINLINE swizzle3<vec3, float, 2, 0, 1> vec3::zxy() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec3 vec3::xyy() const { return vec3(this->_x, this->_y, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec3 vec3::yyy() const { return vec3(this->_y, this->_y, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec3 vec3::zyy() const { return vec3(this->_z, this->_y, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec3 vec3::xzy() const { return vec3(this->_x, this->_z, this->_y); } // readonly
TRICIBLE_FORCEINLINE swizzle3<vec3, float, 0, 2, 1> vec3::xzy() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec3 vec3::yzy() const { return vec3(this->_y, this->_z, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec3 vec3::zzy() const { return vec3(this->_z, this->_z, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec3 vec3::xxz() const { return vec3(this->_x, this->_x, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec3 vec3::yxz() const { return vec3(this->_y, this->_x, this->_z); } // readonly
TRICIBLE_FORCEINLINE swizzle3<vec3, float, 1, 0, 2> vec3::yxz() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec3 vec3::zxz() const { return vec3(this->_z, this->_x, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec3 vec3::xyz() const { return vec3(this->_x, this->_y, this->_z); } // readonly
TRICIBLE_FORCEINLINE swizzle3<vec3, float, 0, 1, 2> vec3::xyz() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec3 vec3::yyz() const { return vec3(this->_y, this->_y, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec3 vec3::zyz() const { return vec3(this->_z, this->_y, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec3 vec3::xzz() const { return vec3(this->_x, this->_z, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec3 vec3::yzz() const { return vec3(this->_y, this->_z, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec3 vec3::zzz() const { return vec3(this->_z, this->_z, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::xxxx() const { return vec4(this->_x, this->_x, this->_x, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::yxxx() const { return vec4(this->_y, this->_x, this->_x, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::zxxx() const { return vec4(this->_z, this->_x, this->_x, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::xyxx() const { return vec4(this->_x, this->_y, this->_x, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::yyxx() const { return vec4(this->_y, this->_y, this->_x, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::zyxx() const { return vec4(this->_z, this->_y, this->_x, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::xzxx() const { return vec4(this->_x, this->_z, this->_x, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::yzxx() const { return vec4(this->_y, this->_z, this->_x, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::zzxx() const { return vec4(this->_z, this->_z, this->_x, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::xxyx() const { return vec4(this->_x, this->_x, this->_y, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::yxyx() const { return vec4(this->_y, this->_x, this->_y, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::zxyx() const { return vec4(this->_z, this->_x, this->_y, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::xyyx() const { return vec4(this->_x, this->_y, this->_y, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::yyyx() const { return vec4(this->_y, this->_y, this->_y, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::zyyx() const { return vec4(this->_z, this->_y, this->_y, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::xzyx() const { return vec4(this->_x, this->_z, this->_y, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::yzyx() const { return vec4(this->_y, this->_z, this->_y, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::zzyx() const { return vec4(this->_z, this->_z, this->_y, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::xxzx() const { return vec4(this->_x, this->_x, this->_z, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::yxzx() const { return vec4(this->_y, this->_x, this->_z, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::zxzx() const { return vec4(this->_z, this->_x, this->_z, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::xyzx() const { return vec4(this->_x, this->_y, this->_z, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::yyzx() const { return vec4(this->_y, this->_y, this->_z, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::zyzx() const { return vec4(this->_z, this->_y, this->_z, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::xzzx() const { return vec4(this->_x, this->_z, this->_z, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::yzzx() const { return vec4(this->_y, this->_z, this->_z, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::zzzx() const { return vec4(this->_z, this->_z, this->_z, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::xxxy() const { return vec4(this->_x, this->_x, this->_x, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::yxxy() const { return vec4(this->_y, this->_x, this->_x, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::zxxy() const { return vec4(this->_z, this->_x, this->_x, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::xyxy() const { return vec4(this->_x, this->_y, this->_x, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::yyxy() const { return vec4(this->_y, this->_y, this->_x, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::zyxy() const { return vec4(this->_z, this->_y, this->_x, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::xzxy() const { return vec4(this->_x, this->_z, this->_x, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::yzxy() const { return vec4(this->_y, this->_z, this->_x, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::zzxy() const { return vec4(this->_z, this->_z, this->_x, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::xxyy() const { return vec4(this->_x, this->_x, this->_y, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::yxyy() const { return vec4(this->_y, this->_x, this->_y, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::zxyy() const { return vec4(this->_z, this->_x, this->_y, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::xyyy() const { return vec4(this->_x, this->_y, this->_y, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::yyyy() const { return vec4(this->_y, this->_y, this->_y, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::zyyy() const { return vec4(this->_z, this->_y, this->_y, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::xzyy() const { return vec4(this->_x, this->_z, this->_y, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::yzyy() const { return vec4(this->_y, this->_z, this->_y, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::zzyy() const { return vec4(this->_z, this->_z, this->_y, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::xxzy() const { return vec4(this->_x, this->_x, this->_z, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::yxzy() const { return vec4(this->_y, this->_x, this->_z, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::zxzy() const { return vec4(this->_z, this->_x, this->_z, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::xyzy() const { return vec4(this->_x, this->_y, this->_z, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::yyzy() const { return vec4(this->_y, this->_y, this->_z, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::zyzy() const { return vec4(this->_z, this->_y, this->_z, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::xzzy() const { return vec4(this->_x, this->_z, this->_z, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::yzzy() const { return vec4(this->_y, this->_z, this->_z, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::zzzy() const { return vec4(this->_z, this->_z, this->_z, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::xxxz() const { return vec4(this->_x, this->_x, this->_x, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::yxxz() const { return vec4(this->_y, this->_x, this->_x, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::zxxz() const { return vec4(this->_z, this->_x, this->_x, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::xyxz() const { return vec4(this->_x, this->_y, this->_x, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::yyxz() const { return vec4(this->_y, this->_y, this->_x, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::zyxz() const { return vec4(this->_z, this->_y, this->_x, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::xzxz() const { return vec4(this->_x, this->_z, this->_x, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::yzxz() const { return vec4(this->_y, this->_z, this->_x, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::zzxz() const { return vec4(this->_z, this->_z, this->_x, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::xxyz() const { return vec4(this->_x, this->_x, this->_y, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::yxyz() const { return vec4(this->_y, this->_x, this->_y, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::zxyz() const { return vec4(this->_z, this->_x, this->_y, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::xyyz() const { return vec4(this->_x, this->_y, this->_y, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::yyyz() const { return vec4(this->_y, this->_y, this->_y, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::zyyz() const { return vec4(this->_z, this->_y, this->_y, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::xzyz() const { return vec4(this->_x, this->_z, this->_y, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::yzyz() const { return vec4(this->_y, this->_z, this->_y, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::zzyz() const { return vec4(this->_z, this->_z, this->_y, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::xxzz() const { return vec4(this->_x, this->_x, this->_z, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::yxzz() const { return vec4(this->_y, this->_x, this->_z, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::zxzz() const { return vec4(this->_z, this->_x, this->_z, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::xyzz() const { return vec4(this->_x, this->_y, this->_z, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::yyzz() const { return vec4(this->_y, this->_y, this->_z, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::zyzz() const { return vec4(this->_z, this->_y, this->_z, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::xzzz() const { return vec4(this->_x, this->_z, this->_z, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::yzzz() const { return vec4(this->_y, this->_z, this->_z, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::zzzz() const { return vec4(this->_z, this->_z, this->_z, this->_z); } // readonly

TRICIBLE_FORCEINLINE float vec3::r() const { return this->_x; } // readonly
TRICIBLE_FORCEINLINE swizzle1<vec3, float, 0> vec3::r() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE float vec3::g() const { return this->_y; } // readonly
TRICIBLE_FORCEINLINE swizzle1<vec3, float, 1> vec3::g() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE float vec3::b() const { return this->_z; } // readonly
TRICIBLE_FORCEINLINE swizzle1<vec3, float, 2> vec3::b() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec2 vec3::rr() const { return vec2(this->_x, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec2 vec3::gr() const { return vec2(this->_y, this->_x); } // readonly
TRICIBLE_FORCEINLINE swizzle2<vec3, float, 1, 0> vec3::gr() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec2 vec3::br() const { return vec2(this->_z, this->_x); } // readonly
TRICIBLE_FORCEINLINE swizzle2<vec3, float, 2, 0> vec3::br() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec2 vec3::rg() const { return vec2(this->_x, this->_y); } // readonly
TRICIBLE_FORCEINLINE swizzle2<vec3, float, 0, 1> vec3::rg() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec2 vec3::gg() const { return vec2(this->_y, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec2 vec3::bg() const { return vec2(this->_z, this->_y); } // readonly
TRICIBLE_FORCEINLINE swizzle2<vec3, float, 2, 1> vec3::bg() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec2 vec3::rb() const { return vec2(this->_x, this->_z); } // readonly
TRICIBLE_FORCEINLINE swizzle2<vec3, float, 0, 2> vec3::rb() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec2 vec3::gb() const { return vec2(this->_y, this->_z); } // readonly
TRICIBLE_FORCEINLINE swizzle2<vec3, float, 1, 2> vec3::gb() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec2 vec3::bb() const { return vec2(this->_z, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec3 vec3::rrr() const { return vec3(this->_x, this->_x, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec3 vec3::grr() const { return vec3(this->_y, this->_x, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec3 vec3::brr() const { return vec3(this->_z, this->_x, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec3 vec3::rgr() const { return vec3(this->_x, this->_y, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec3 vec3::ggr() const { return vec3(this->_y, this->_y, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec3 vec3::bgr() const { return vec3(this->_z, this->_y, this->_x); } // readonly
TRICIBLE_FORCEINLINE swizzle3<vec3, float, 2, 1, 0> vec3::bgr() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec3 vec3::rbr() const { return vec3(this->_x, this->_z, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec3 vec3::gbr() const { return vec3(this->_y, this->_z, this->_x); } // readonly
TRICIBLE_FORCEINLINE swizzle3<vec3, float, 1, 2, 0> vec3::gbr() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec3 vec3::bbr() const { return vec3(this->_z, this->_z, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec3 vec3::rrg() const { return vec3(this->_x, this->_x, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec3 vec3::grg() const { return vec3(this->_y, this->_x, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec3 vec3::brg() const { return vec3(this->_z, this->_x, this->_y); } // readonly
TRICIBLE_FORCEINLINE swizzle3<vec3, float, 2, 0, 1> vec3::brg() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec3 vec3::rgg() const { return vec3(this->_x, this->_y, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec3 vec3::ggg() const { return vec3(this->_y, this->_y, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec3 vec3::bgg() const { return vec3(this->_z, this->_y, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec3 vec3::rbg() const { return vec3(this->_x, this->_z, this->_y); } // readonly
TRICIBLE_FORCEINLINE swizzle3<vec3, float, 0, 2, 1> vec3::rbg() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec3 vec3::gbg() const { return vec3(this->_y, this->_z, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec3 vec3::bbg() const { return vec3(this->_z, this->_z, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec3 vec3::rrb() const { return vec3(this->_x, this->_x, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec3 vec3::grb() const { return vec3(this->_y, this->_x, this->_z); } // readonly
TRICIBLE_FORCEINLINE swizzle3<vec3, float, 1, 0, 2> vec3::grb() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec3 vec3::brb() const { return vec3(this->_z, this->_x, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec3 vec3::rgb() const { return vec3(this->_x, this->_y, this->_z); } // readonly
TRICIBLE_FORCEINLINE swizzle3<vec3, float, 0, 1, 2> vec3::rgb() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec3 vec3::ggb() const { return vec3(this->_y, this->_y, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec3 vec3::bgb() const { return vec3(this->_z, this->_y, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec3 vec3::rbb() const { return vec3(this->_x, this->_z, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec3 vec3::gbb() const { return vec3(this->_y, this->_z, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec3 vec3::bbb() const { return vec3(this->_z, this->_z, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::rrrr() const { return vec4(this->_x, this->_x, this->_x, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::grrr() const { return vec4(this->_y, this->_x, this->_x, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::brrr() const { return vec4(this->_z, this->_x, this->_x, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::rgrr() const { return vec4(this->_x, this->_y, this->_x, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::ggrr() const { return vec4(this->_y, this->_y, this->_x, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::bgrr() const { return vec4(this->_z, this->_y, this->_x, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::rbrr() const { return vec4(this->_x, this->_z, this->_x, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::gbrr() const { return vec4(this->_y, this->_z, this->_x, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::bbrr() const { return vec4(this->_z, this->_z, this->_x, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::rrgr() const { return vec4(this->_x, this->_x, this->_y, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::grgr() const { return vec4(this->_y, this->_x, this->_y, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::brgr() const { return vec4(this->_z, this->_x, this->_y, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::rggr() const { return vec4(this->_x, this->_y, this->_y, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::gggr() const { return vec4(this->_y, this->_y, this->_y, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::bggr() const { return vec4(this->_z, this->_y, this->_y, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::rbgr() const { return vec4(this->_x, this->_z, this->_y, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::gbgr() const { return vec4(this->_y, this->_z, this->_y, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::bbgr() const { return vec4(this->_z, this->_z, this->_y, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::rrbr() const { return vec4(this->_x, this->_x, this->_z, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::grbr() const { return vec4(this->_y, this->_x, this->_z, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::brbr() const { return vec4(this->_z, this->_x, this->_z, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::rgbr() const { return vec4(this->_x, this->_y, this->_z, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::ggbr() const { return vec4(this->_y, this->_y, this->_z, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::bgbr() const { return vec4(this->_z, this->_y, this->_z, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::rbbr() const { return vec4(this->_x, this->_z, this->_z, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::gbbr() const { return vec4(this->_y, this->_z, this->_z, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::bbbr() const { return vec4(this->_z, this->_z, this->_z, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::rrrg() const { return vec4(this->_x, this->_x, this->_x, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::grrg() const { return vec4(this->_y, this->_x, this->_x, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::brrg() const { return vec4(this->_z, this->_x, this->_x, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::rgrg() const { return vec4(this->_x, this->_y, this->_x, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::ggrg() const { return vec4(this->_y, this->_y, this->_x, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::bgrg() const { return vec4(this->_z, this->_y, this->_x, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::rbrg() const { return vec4(this->_x, this->_z, this->_x, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::gbrg() const { return vec4(this->_y, this->_z, this->_x, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::bbrg() const { return vec4(this->_z, this->_z, this->_x, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::rrgg() const { return vec4(this->_x, this->_x, this->_y, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::grgg() const { return vec4(this->_y, this->_x, this->_y, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::brgg() const { return vec4(this->_z, this->_x, this->_y, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::rggg() const { return vec4(this->_x, this->_y, this->_y, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::gggg() const { return vec4(this->_y, this->_y, this->_y, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::bggg() const { return vec4(this->_z, this->_y, this->_y, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::rbgg() const { return vec4(this->_x, this->_z, this->_y, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::gbgg() const { return vec4(this->_y, this->_z, this->_y, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::bbgg() const { return vec4(this->_z, this->_z, this->_y, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::rrbg() const { return vec4(this->_x, this->_x, this->_z, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::grbg() const { return vec4(this->_y, this->_x, this->_z, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::brbg() const { return vec4(this->_z, this->_x, this->_z, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::rgbg() const { return vec4(this->_x, this->_y, this->_z, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::ggbg() const { return vec4(this->_y, this->_y, this->_z, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::bgbg() const { return vec4(this->_z, this->_y, this->_z, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::rbbg() const { return vec4(this->_x, this->_z, this->_z, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::gbbg() const { return vec4(this->_y, this->_z, this->_z, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::bbbg() const { return vec4(this->_z, this->_z, this->_z, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::rrrb() const { return vec4(this->_x, this->_x, this->_x, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::grrb() const { return vec4(this->_y, this->_x, this->_x, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::brrb() const { return vec4(this->_z, this->_x, this->_x, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::rgrb() const { return vec4(this->_x, this->_y, this->_x, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::ggrb() const { return vec4(this->_y, this->_y, this->_x, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::bgrb() const { return vec4(this->_z, this->_y, this->_x, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::rbrb() const { return vec4(this->_x, this->_z, this->_x, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::gbrb() const { return vec4(this->_y, this->_z, this->_x, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::bbrb() const { return vec4(this->_z, this->_z, this->_x, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::rrgb() const { return vec4(this->_x, this->_x, this->_y, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::grgb() const { return vec4(this->_y, this->_x, this->_y, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::brgb() const { return vec4(this->_z, this->_x, this->_y, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::rggb() const { return vec4(this->_x, this->_y, this->_y, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::gggb() const { return vec4(this->_y, this->_y, this->_y, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::bggb() const { return vec4(this->_z, this->_y, this->_y, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::rbgb() const { return vec4(this->_x, this->_z, this->_y, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::gbgb() const { return vec4(this->_y, this->_z, this->_y, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::bbgb() const { return vec4(this->_z, this->_z, this->_y, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::rrbb() const { return vec4(this->_x, this->_x, this->_z, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::grbb() const { return vec4(this->_y, this->_x, this->_z, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::brbb() const { return vec4(this->_z, this->_x, this->_z, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::rgbb() const { return vec4(this->_x, this->_y, this->_z, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::ggbb() const { return vec4(this->_y, this->_y, this->_z, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::bgbb() const { return vec4(this->_z, this->_y, this->_z, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::rbbb() const { return vec4(this->_x, this->_z, this->_z, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::gbbb() const { return vec4(this->_y, this->_z, this->_z, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::bbbb() const { return vec4(this->_z, this->_z, this->_z, this->_z); } // readonly

TRICIBLE_FORCEINLINE float vec3::s() const { return this->_x; } // readonly
TRICIBLE_FORCEINLINE swizzle1<vec3, float, 0> vec3::s() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE float vec3::t() const { return this->_y; } // readonly
TRICIBLE_FORCEINLINE swizzle1<vec3, float, 1> vec3::t() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE float vec3::p() const { return this->_z; } // readonly
TRICIBLE_FORCEINLINE swizzle1<vec3, float, 2> vec3::p() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec2 vec3::ss() const { return vec2(this->_x, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec2 vec3::ts() const { return vec2(this->_y, this->_x); } // readonly
TRICIBLE_FORCEINLINE swizzle2<vec3, float, 1, 0> vec3::ts() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec2 vec3::ps() const { return vec2(this->_z, this->_x); } // readonly
TRICIBLE_FORCEINLINE swizzle2<vec3, float, 2, 0> vec3::ps() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec2 vec3::st() const { return vec2(this->_x, this->_y); } // readonly
TRICIBLE_FORCEINLINE swizzle2<vec3, float, 0, 1> vec3::st() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec2 vec3::tt() const { return vec2(this->_y, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec2 vec3::pt() const { return vec2(this->_z, this->_y); } // readonly
TRICIBLE_FORCEINLINE swizzle2<vec3, float, 2, 1> vec3::pt() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec2 vec3::sp() const { return vec2(this->_x, this->_z); } // readonly
TRICIBLE_FORCEINLINE swizzle2<vec3, float, 0, 2> vec3::sp() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec2 vec3::tp() const { return vec2(this->_y, this->_z); } // readonly
TRICIBLE_FORCEINLINE swizzle2<vec3, float, 1, 2> vec3::tp() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec2 vec3::pp() const { return vec2(this->_z, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec3 vec3::sss() const { return vec3(this->_x, this->_x, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec3 vec3::tss() const { return vec3(this->_y, this->_x, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec3 vec3::pss() const { return vec3(this->_z, this->_x, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec3 vec3::sts() const { return vec3(this->_x, this->_y, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec3 vec3::tts() const { return vec3(this->_y, this->_y, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec3 vec3::pts() const { return vec3(this->_z, this->_y, this->_x); } // readonly
TRICIBLE_FORCEINLINE swizzle3<vec3, float, 2, 1, 0> vec3::pts() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec3 vec3::sps() const { return vec3(this->_x, this->_z, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec3 vec3::tps() const { return vec3(this->_y, this->_z, this->_x); } // readonly
TRICIBLE_FORCEINLINE swizzle3<vec3, float, 1, 2, 0> vec3::tps() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec3 vec3::pps() const { return vec3(this->_z, this->_z, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec3 vec3::sst() const { return vec3(this->_x, this->_x, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec3 vec3::tst() const { return vec3(this->_y, this->_x, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec3 vec3::pst() const { return vec3(this->_z, this->_x, this->_y); } // readonly
TRICIBLE_FORCEINLINE swizzle3<vec3, float, 2, 0, 1> vec3::pst() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec3 vec3::stt() const { return vec3(this->_x, this->_y, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec3 vec3::ttt() const { return vec3(this->_y, this->_y, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec3 vec3::ptt() const { return vec3(this->_z, this->_y, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec3 vec3::spt() const { return vec3(this->_x, this->_z, this->_y); } // readonly
TRICIBLE_FORCEINLINE swizzle3<vec3, float, 0, 2, 1> vec3::spt() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec3 vec3::tpt() const { return vec3(this->_y, this->_z, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec3 vec3::ppt() const { return vec3(this->_z, this->_z, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec3 vec3::ssp() const { return vec3(this->_x, this->_x, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec3 vec3::tsp() const { return vec3(this->_y, this->_x, this->_z); } // readonly
TRICIBLE_FORCEINLINE swizzle3<vec3, float, 1, 0, 2> vec3::tsp() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec3 vec3::psp() const { return vec3(this->_z, this->_x, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec3 vec3::stp() const { return vec3(this->_x, this->_y, this->_z); } // readonly
TRICIBLE_FORCEINLINE swizzle3<vec3, float, 0, 1, 2> vec3::stp() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec3 vec3::ttp() const { return vec3(this->_y, this->_y, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec3 vec3::ptp() const { return vec3(this->_z, this->_y, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec3 vec3::spp() const { return vec3(this->_x, this->_z, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec3 vec3::tpp() const { return vec3(this->_y, this->_z, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec3 vec3::ppp() const { return vec3(this->_z, this->_z, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::ssss() const { return vec4(this->_x, this->_x, this->_x, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::tsss() const { return vec4(this->_y, this->_x, this->_x, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::psss() const { return vec4(this->_z, this->_x, this->_x, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::stss() const { return vec4(this->_x, this->_y, this->_x, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::ttss() const { return vec4(this->_y, this->_y, this->_x, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::ptss() const { return vec4(this->_z, this->_y, this->_x, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::spss() const { return vec4(this->_x, this->_z, this->_x, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::tpss() const { return vec4(this->_y, this->_z, this->_x, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::ppss() const { return vec4(this->_z, this->_z, this->_x, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::ssts() const { return vec4(this->_x, this->_x, this->_y, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::tsts() const { return vec4(this->_y, this->_x, this->_y, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::psts() const { return vec4(this->_z, this->_x, this->_y, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::stts() const { return vec4(this->_x, this->_y, this->_y, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::ttts() const { return vec4(this->_y, this->_y, this->_y, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::ptts() const { return vec4(this->_z, this->_y, this->_y, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::spts() const { return vec4(this->_x, this->_z, this->_y, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::tpts() const { return vec4(this->_y, this->_z, this->_y, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::ppts() const { return vec4(this->_z, this->_z, this->_y, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::ssps() const { return vec4(this->_x, this->_x, this->_z, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::tsps() const { return vec4(this->_y, this->_x, this->_z, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::psps() const { return vec4(this->_z, this->_x, this->_z, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::stps() const { return vec4(this->_x, this->_y, this->_z, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::ttps() const { return vec4(this->_y, this->_y, this->_z, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::ptps() const { return vec4(this->_z, this->_y, this->_z, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::spps() const { return vec4(this->_x, this->_z, this->_z, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::tpps() const { return vec4(this->_y, this->_z, this->_z, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::ppps() const { return vec4(this->_z, this->_z, this->_z, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::ssst() const { return vec4(this->_x, this->_x, this->_x, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::tsst() const { return vec4(this->_y, this->_x, this->_x, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::psst() const { return vec4(this->_z, this->_x, this->_x, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::stst() const { return vec4(this->_x, this->_y, this->_x, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::ttst() const { return vec4(this->_y, this->_y, this->_x, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::ptst() const { return vec4(this->_z, this->_y, this->_x, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::spst() const { return vec4(this->_x, this->_z, this->_x, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::tpst() const { return vec4(this->_y, this->_z, this->_x, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::ppst() const { return vec4(this->_z, this->_z, this->_x, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::sstt() const { return vec4(this->_x, this->_x, this->_y, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::tstt() const { return vec4(this->_y, this->_x, this->_y, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::pstt() const { return vec4(this->_z, this->_x, this->_y, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::sttt() const { return vec4(this->_x, this->_y, this->_y, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::tttt() const { return vec4(this->_y, this->_y, this->_y, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::pttt() const { return vec4(this->_z, this->_y, this->_y, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::sptt() const { return vec4(this->_x, this->_z, this->_y, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::tptt() const { return vec4(this->_y, this->_z, this->_y, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::pptt() const { return vec4(this->_z, this->_z, this->_y, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::sspt() const { return vec4(this->_x, this->_x, this->_z, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::tspt() const { return vec4(this->_y, this->_x, this->_z, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::pspt() const { return vec4(this->_z, this->_x, this->_z, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::stpt() const { return vec4(this->_x, this->_y, this->_z, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::ttpt() const { return vec4(this->_y, this->_y, this->_z, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::ptpt() const { return vec4(this->_z, this->_y, this->_z, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::sppt() const { return vec4(this->_x, this->_z, this->_z, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::tppt() const { return vec4(this->_y, this->_z, this->_z, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::pppt() const { return vec4(this->_z, this->_z, this->_z, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::sssp() const { return vec4(this->_x, this->_x, this->_x, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::tssp() const { return vec4(this->_y, this->_x, this->_x, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::pssp() const { return vec4(this->_z, this->_x, this->_x, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::stsp() const { return vec4(this->_x, this->_y, this->_x, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::ttsp() const { return vec4(this->_y, this->_y, this->_x, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::ptsp() const { return vec4(this->_z, this->_y, this->_x, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::spsp() const { return vec4(this->_x, this->_z, this->_x, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::tpsp() const { return vec4(this->_y, this->_z, this->_x, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::ppsp() const { return vec4(this->_z, this->_z, this->_x, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::sstp() const { return vec4(this->_x, this->_x, this->_y, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::tstp() const { return vec4(this->_y, this->_x, this->_y, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::pstp() const { return vec4(this->_z, this->_x, this->_y, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::sttp() const { return vec4(this->_x, this->_y, this->_y, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::tttp() const { return vec4(this->_y, this->_y, this->_y, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::pttp() const { return vec4(this->_z, this->_y, this->_y, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::sptp() const { return vec4(this->_x, this->_z, this->_y, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::tptp() const { return vec4(this->_y, this->_z, this->_y, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::pptp() const { return vec4(this->_z, this->_z, this->_y, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::sspp() const { return vec4(this->_x, this->_x, this->_z, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::tspp() const { return vec4(this->_y, this->_x, this->_z, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::pspp() const { return vec4(this->_z, this->_x, this->_z, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::stpp() const { return vec4(this->_x, this->_y, this->_z, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::ttpp() const { return vec4(this->_y, this->_y, this->_z, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::ptpp() const { return vec4(this->_z, this->_y, this->_z, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::sppp() const { return vec4(this->_x, this->_z, this->_z, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::tppp() const { return vec4(this->_y, this->_z, this->_z, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec3::pppp() const { return vec4(this->_z, this->_z, this->_z, this->_z); } // readonly