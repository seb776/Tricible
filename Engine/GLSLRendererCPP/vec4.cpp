#include <sstream>
#include "GLSLFunctions.hpp"
#include "SwizzleProxies.hpp"
#include "vec4.hpp"
#include "vec3.hpp"
#include "vec2.hpp"

vec4::vec4() :
	vec4(0.0f)
{
}
vec4::vec4(const vec4& rhs)
{
	*this = rhs;
}
vec4::vec4(const vec2& a, const vec2& b) :
	vec4(a._x, a._y, b._x, a._y)
{}
vec4::vec4(const vec2& a, float z_, float w_) :
	vec4(a, vec2(z_, w_))
{}
vec4::vec4(float x_, const vec2& a, float w_) :
	vec4(x_, a._x, a._y, w_)
{}
vec4::vec4(float x_, float y_, const vec2& a) :
	vec4(vec2(x_, y_), a)
{}
vec4::vec4(float x_, const vec3& a) :
	vec4(x_, a._x, a._y, a._z)
{}
vec4::vec4(const vec3& a, float w_) :
	vec4(a._x, a._y, a._z, w_)
{}
vec4::vec4(float x_, float y_, float z_, float w_)
{
	_x = x_;
	_y = y_;
	_z = z_;
	_w = w_;
}
vec4::vec4(float x_) :
	vec4(x_, x_, x_, x_)
{
}


TRICIBLE_FORCEINLINE vec4 vec4::operator-() const
{
	return vec4(-this->_x, -this->_y, -this->_z, -this->_w);
}

TRICIBLE_FORCEINLINE vec4 vec4::operator+(const vec4& rhs) const
{
	return vec4(_x + rhs._x, _y + rhs._y, _z + rhs._z, _w + rhs._w);
}

TRICIBLE_FORCEINLINE vec4 vec4::operator-(const vec4& rhs) const
{
	return vec4(_x - rhs._x, _y - rhs._y, _z - rhs._z, _w - rhs._w);
}

TRICIBLE_FORCEINLINE vec4 vec4::operator*(const vec4& rhs) const
{
	return vec4(_x * rhs._x, _y * rhs._y, _z * rhs._z, _w * rhs._w);
}

TRICIBLE_FORCEINLINE vec4 vec4::operator*(const float rhs) const
{
	return vec4(_x * rhs, _y * rhs, _z * rhs, _w * rhs);
}

TRICIBLE_FORCEINLINE vec4 vec4::operator/(const vec4& rhs) const
{
	return vec4(_x / rhs._x, _y / rhs._y, _z / rhs._z, _w / rhs._w);
}
TRICIBLE_FORCEINLINE vec4 vec4::operator/(const float rhs) const
{
	return vec4(_x / rhs, _y / rhs, _z / rhs, _w / rhs);
}

TRICIBLE_FORCEINLINE vec4 vec4::operator=(const vec4& rhs)
{
	this->_x = rhs._x;
	this->_y = rhs._y;
	this->_z = rhs._z;
	return *this;
}

TRICIBLE_FORCEINLINE vec4 vec4::operator+=(const vec4& rhs)
{
	this->_x += rhs._x;
	this->_y += rhs._y;
	this->_z += rhs._z;
	return *this;
}

TRICIBLE_FORCEINLINE vec4 vec4::operator-=(const vec4& rhs)
{
	this->_x -= rhs._x;
	this->_y -= rhs._y;
	this->_z -= rhs._z;
	return *this;
}

TRICIBLE_FORCEINLINE vec4 vec4::operator*=(const vec4& rhs)
{
	this->_x *= rhs._x;
	this->_y *= rhs._y;
	this->_z *= rhs._z;
	return *this;
}
TRICIBLE_FORCEINLINE vec4 vec4::operator/=(const vec4& rhs)
{
	this->_x /= rhs._x;
	this->_y /= rhs._y;
	this->_z /= rhs._z;
	return *this;
}
TRICIBLE_FORCEINLINE vec4 vec4::operator*=(const float rhs)
{
	this->_x *= rhs;
	this->_y *= rhs;
	this->_z *= rhs;
	return *this;
}
TRICIBLE_FORCEINLINE vec4 vec4::operator/=(const float rhs)
{
	this->_x /= rhs;
	this->_y /= rhs;
	this->_z /= rhs;
	return *this;
}


TRICIBLE_FORCEINLINE std::string vec4::ToString() const
{
	std::stringstream ss;
	ss << "(" << _x << ", " << _y << ", " << _z << ", " << _w << ")";
	return ss.str();
}

uint vec4::ToInt()
{
	//return (_red << 24) + (_green << 16) + (_blue << 8) + 0xFF;
	// TODO missing Alpha
	return 0xFF000000 +
		clamp((uint)(_x * 255.0f), (uint)0, (uint)0xFF) +
		(clamp((uint)(_y * 255.0f), (uint)0, (uint)0xFF) << 8) +
		(clamp((uint)(_z * 255.0f), (uint)0, (uint)0xFF) << 16);
}

TRICIBLE_FORCEINLINE float vec4::x() const { return this->_x; } // readonly
TRICIBLE_FORCEINLINE swizzle1<vec4, float, 0> vec4::x() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE float vec4::y() const { return this->_y; } // readonly
TRICIBLE_FORCEINLINE swizzle1<vec4, float, 1> vec4::y() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE float vec4::z() const { return this->_z; } // readonly
TRICIBLE_FORCEINLINE swizzle1<vec4, float, 2> vec4::z() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE float vec4::w() const { return this->_w; } // readonly
TRICIBLE_FORCEINLINE swizzle1<vec4, float, 3> vec4::w() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec2 vec4::xx() const { return vec2(this->_x, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec2 vec4::yx() const { return vec2(this->_y, this->_x); } // readonly
TRICIBLE_FORCEINLINE swizzle2<vec4, float, 1, 0> vec4::yx() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec2 vec4::zx() const { return vec2(this->_z, this->_x); } // readonly
TRICIBLE_FORCEINLINE swizzle2<vec4, float, 2, 0> vec4::zx() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec2 vec4::wx() const { return vec2(this->_w, this->_x); } // readonly
TRICIBLE_FORCEINLINE swizzle2<vec4, float, 3, 0> vec4::wx() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec2 vec4::xy() const { return vec2(this->_x, this->_y); } // readonly
TRICIBLE_FORCEINLINE swizzle2<vec4, float, 0, 1> vec4::xy() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec2 vec4::yy() const { return vec2(this->_y, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec2 vec4::zy() const { return vec2(this->_z, this->_y); } // readonly
TRICIBLE_FORCEINLINE swizzle2<vec4, float, 2, 1> vec4::zy() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec2 vec4::wy() const { return vec2(this->_w, this->_y); } // readonly
TRICIBLE_FORCEINLINE swizzle2<vec4, float, 3, 1> vec4::wy() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec2 vec4::xz() const { return vec2(this->_x, this->_z); } // readonly
TRICIBLE_FORCEINLINE swizzle2<vec4, float, 0, 2> vec4::xz() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec2 vec4::yz() const { return vec2(this->_y, this->_z); } // readonly
TRICIBLE_FORCEINLINE swizzle2<vec4, float, 1, 2> vec4::yz() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec2 vec4::zz() const { return vec2(this->_z, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec2 vec4::wz() const { return vec2(this->_w, this->_z); } // readonly
TRICIBLE_FORCEINLINE swizzle2<vec4, float, 3, 2> vec4::wz() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec2 vec4::xw() const { return vec2(this->_x, this->_w); } // readonly
TRICIBLE_FORCEINLINE swizzle2<vec4, float, 0, 3> vec4::xw() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec2 vec4::yw() const { return vec2(this->_y, this->_w); } // readonly
TRICIBLE_FORCEINLINE swizzle2<vec4, float, 1, 3> vec4::yw() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec2 vec4::zw() const { return vec2(this->_z, this->_w); } // readonly
TRICIBLE_FORCEINLINE swizzle2<vec4, float, 2, 3> vec4::zw() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec2 vec4::ww() const { return vec2(this->_w, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec3 vec4::xxx() const { return vec3(this->_x, this->_x, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec3 vec4::yxx() const { return vec3(this->_y, this->_x, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec3 vec4::zxx() const { return vec3(this->_z, this->_x, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec3 vec4::wxx() const { return vec3(this->_w, this->_x, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec3 vec4::xyx() const { return vec3(this->_x, this->_y, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec3 vec4::yyx() const { return vec3(this->_y, this->_y, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec3 vec4::zyx() const { return vec3(this->_z, this->_y, this->_x); } // readonly
TRICIBLE_FORCEINLINE swizzle3<vec4, float, 2, 1, 0> vec4::zyx() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec3 vec4::wyx() const { return vec3(this->_w, this->_y, this->_x); } // readonly
TRICIBLE_FORCEINLINE swizzle3<vec4, float, 3, 1, 0> vec4::wyx() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec3 vec4::xzx() const { return vec3(this->_x, this->_z, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec3 vec4::yzx() const { return vec3(this->_y, this->_z, this->_x); } // readonly
TRICIBLE_FORCEINLINE swizzle3<vec4, float, 1, 2, 0> vec4::yzx() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec3 vec4::zzx() const { return vec3(this->_z, this->_z, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec3 vec4::wzx() const { return vec3(this->_w, this->_z, this->_x); } // readonly
TRICIBLE_FORCEINLINE swizzle3<vec4, float, 3, 2, 0> vec4::wzx() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec3 vec4::xwx() const { return vec3(this->_x, this->_w, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec3 vec4::ywx() const { return vec3(this->_y, this->_w, this->_x); } // readonly
TRICIBLE_FORCEINLINE swizzle3<vec4, float, 1, 3, 0> vec4::ywx() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec3 vec4::zwx() const { return vec3(this->_z, this->_w, this->_x); } // readonly
TRICIBLE_FORCEINLINE swizzle3<vec4, float, 2, 3, 0> vec4::zwx() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec3 vec4::wwx() const { return vec3(this->_w, this->_w, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec3 vec4::xxy() const { return vec3(this->_x, this->_x, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec3 vec4::yxy() const { return vec3(this->_y, this->_x, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec3 vec4::zxy() const { return vec3(this->_z, this->_x, this->_y); } // readonly
TRICIBLE_FORCEINLINE swizzle3<vec4, float, 2, 0, 1> vec4::zxy() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec3 vec4::wxy() const { return vec3(this->_w, this->_x, this->_y); } // readonly
TRICIBLE_FORCEINLINE swizzle3<vec4, float, 3, 0, 1> vec4::wxy() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec3 vec4::xyy() const { return vec3(this->_x, this->_y, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec3 vec4::yyy() const { return vec3(this->_y, this->_y, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec3 vec4::zyy() const { return vec3(this->_z, this->_y, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec3 vec4::wyy() const { return vec3(this->_w, this->_y, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec3 vec4::xzy() const { return vec3(this->_x, this->_z, this->_y); } // readonly
TRICIBLE_FORCEINLINE swizzle3<vec4, float, 0, 2, 1> vec4::xzy() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec3 vec4::yzy() const { return vec3(this->_y, this->_z, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec3 vec4::zzy() const { return vec3(this->_z, this->_z, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec3 vec4::wzy() const { return vec3(this->_w, this->_z, this->_y); } // readonly
TRICIBLE_FORCEINLINE swizzle3<vec4, float, 3, 2, 1> vec4::wzy() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec3 vec4::xwy() const { return vec3(this->_x, this->_w, this->_y); } // readonly
TRICIBLE_FORCEINLINE swizzle3<vec4, float, 0, 3, 1> vec4::xwy() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec3 vec4::ywy() const { return vec3(this->_y, this->_w, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec3 vec4::zwy() const { return vec3(this->_z, this->_w, this->_y); } // readonly
TRICIBLE_FORCEINLINE swizzle3<vec4, float, 2, 3, 1> vec4::zwy() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec3 vec4::wwy() const { return vec3(this->_w, this->_w, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec3 vec4::xxz() const { return vec3(this->_x, this->_x, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec3 vec4::yxz() const { return vec3(this->_y, this->_x, this->_z); } // readonly
TRICIBLE_FORCEINLINE swizzle3<vec4, float, 1, 0, 2> vec4::yxz() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec3 vec4::zxz() const { return vec3(this->_z, this->_x, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec3 vec4::wxz() const { return vec3(this->_w, this->_x, this->_z); } // readonly
TRICIBLE_FORCEINLINE swizzle3<vec4, float, 3, 0, 2> vec4::wxz() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec3 vec4::xyz() const { return vec3(this->_x, this->_y, this->_z); } // readonly
TRICIBLE_FORCEINLINE swizzle3<vec4, float, 0, 1, 2> vec4::xyz() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec3 vec4::yyz() const { return vec3(this->_y, this->_y, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec3 vec4::zyz() const { return vec3(this->_z, this->_y, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec3 vec4::wyz() const { return vec3(this->_w, this->_y, this->_z); } // readonly
TRICIBLE_FORCEINLINE swizzle3<vec4, float, 3, 1, 2> vec4::wyz() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec3 vec4::xzz() const { return vec3(this->_x, this->_z, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec3 vec4::yzz() const { return vec3(this->_y, this->_z, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec3 vec4::zzz() const { return vec3(this->_z, this->_z, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec3 vec4::wzz() const { return vec3(this->_w, this->_z, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec3 vec4::xwz() const { return vec3(this->_x, this->_w, this->_z); } // readonly
TRICIBLE_FORCEINLINE swizzle3<vec4, float, 0, 3, 2> vec4::xwz() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec3 vec4::ywz() const { return vec3(this->_y, this->_w, this->_z); } // readonly
TRICIBLE_FORCEINLINE swizzle3<vec4, float, 1, 3, 2> vec4::ywz() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec3 vec4::zwz() const { return vec3(this->_z, this->_w, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec3 vec4::wwz() const { return vec3(this->_w, this->_w, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec3 vec4::xxw() const { return vec3(this->_x, this->_x, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec3 vec4::yxw() const { return vec3(this->_y, this->_x, this->_w); } // readonly
TRICIBLE_FORCEINLINE swizzle3<vec4, float, 1, 0, 3> vec4::yxw() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec3 vec4::zxw() const { return vec3(this->_z, this->_x, this->_w); } // readonly
TRICIBLE_FORCEINLINE swizzle3<vec4, float, 2, 0, 3> vec4::zxw() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec3 vec4::wxw() const { return vec3(this->_w, this->_x, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec3 vec4::xyw() const { return vec3(this->_x, this->_y, this->_w); } // readonly
TRICIBLE_FORCEINLINE swizzle3<vec4, float, 0, 1, 3> vec4::xyw() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec3 vec4::yyw() const { return vec3(this->_y, this->_y, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec3 vec4::zyw() const { return vec3(this->_z, this->_y, this->_w); } // readonly
TRICIBLE_FORCEINLINE swizzle3<vec4, float, 2, 1, 3> vec4::zyw() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec3 vec4::wyw() const { return vec3(this->_w, this->_y, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec3 vec4::xzw() const { return vec3(this->_x, this->_z, this->_w); } // readonly
TRICIBLE_FORCEINLINE swizzle3<vec4, float, 0, 2, 3> vec4::xzw() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec3 vec4::yzw() const { return vec3(this->_y, this->_z, this->_w); } // readonly
TRICIBLE_FORCEINLINE swizzle3<vec4, float, 1, 2, 3> vec4::yzw() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec3 vec4::zzw() const { return vec3(this->_z, this->_z, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec3 vec4::wzw() const { return vec3(this->_w, this->_z, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec3 vec4::xww() const { return vec3(this->_x, this->_w, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec3 vec4::yww() const { return vec3(this->_y, this->_w, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec3 vec4::zww() const { return vec3(this->_z, this->_w, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec3 vec4::www() const { return vec3(this->_w, this->_w, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::xxxx() const { return vec4(this->_x, this->_x, this->_x, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::yxxx() const { return vec4(this->_y, this->_x, this->_x, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::zxxx() const { return vec4(this->_z, this->_x, this->_x, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::wxxx() const { return vec4(this->_w, this->_x, this->_x, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::xyxx() const { return vec4(this->_x, this->_y, this->_x, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::yyxx() const { return vec4(this->_y, this->_y, this->_x, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::zyxx() const { return vec4(this->_z, this->_y, this->_x, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::wyxx() const { return vec4(this->_w, this->_y, this->_x, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::xzxx() const { return vec4(this->_x, this->_z, this->_x, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::yzxx() const { return vec4(this->_y, this->_z, this->_x, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::zzxx() const { return vec4(this->_z, this->_z, this->_x, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::wzxx() const { return vec4(this->_w, this->_z, this->_x, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::xwxx() const { return vec4(this->_x, this->_w, this->_x, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::ywxx() const { return vec4(this->_y, this->_w, this->_x, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::zwxx() const { return vec4(this->_z, this->_w, this->_x, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::wwxx() const { return vec4(this->_w, this->_w, this->_x, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::xxyx() const { return vec4(this->_x, this->_x, this->_y, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::yxyx() const { return vec4(this->_y, this->_x, this->_y, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::zxyx() const { return vec4(this->_z, this->_x, this->_y, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::wxyx() const { return vec4(this->_w, this->_x, this->_y, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::xyyx() const { return vec4(this->_x, this->_y, this->_y, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::yyyx() const { return vec4(this->_y, this->_y, this->_y, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::zyyx() const { return vec4(this->_z, this->_y, this->_y, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::wyyx() const { return vec4(this->_w, this->_y, this->_y, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::xzyx() const { return vec4(this->_x, this->_z, this->_y, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::yzyx() const { return vec4(this->_y, this->_z, this->_y, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::zzyx() const { return vec4(this->_z, this->_z, this->_y, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::wzyx() const { return vec4(this->_w, this->_z, this->_y, this->_x); } // readonly
TRICIBLE_FORCEINLINE swizzle4<vec4, float, 3, 2, 1, 0> vec4::wzyx() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec4 vec4::xwyx() const { return vec4(this->_x, this->_w, this->_y, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::ywyx() const { return vec4(this->_y, this->_w, this->_y, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::zwyx() const { return vec4(this->_z, this->_w, this->_y, this->_x); } // readonly
TRICIBLE_FORCEINLINE swizzle4<vec4, float, 2, 3, 1, 0> vec4::zwyx() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec4 vec4::wwyx() const { return vec4(this->_w, this->_w, this->_y, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::xxzx() const { return vec4(this->_x, this->_x, this->_z, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::yxzx() const { return vec4(this->_y, this->_x, this->_z, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::zxzx() const { return vec4(this->_z, this->_x, this->_z, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::wxzx() const { return vec4(this->_w, this->_x, this->_z, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::xyzx() const { return vec4(this->_x, this->_y, this->_z, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::yyzx() const { return vec4(this->_y, this->_y, this->_z, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::zyzx() const { return vec4(this->_z, this->_y, this->_z, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::wyzx() const { return vec4(this->_w, this->_y, this->_z, this->_x); } // readonly
TRICIBLE_FORCEINLINE swizzle4<vec4, float, 3, 1, 2, 0> vec4::wyzx() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec4 vec4::xzzx() const { return vec4(this->_x, this->_z, this->_z, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::yzzx() const { return vec4(this->_y, this->_z, this->_z, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::zzzx() const { return vec4(this->_z, this->_z, this->_z, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::wzzx() const { return vec4(this->_w, this->_z, this->_z, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::xwzx() const { return vec4(this->_x, this->_w, this->_z, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::ywzx() const { return vec4(this->_y, this->_w, this->_z, this->_x); } // readonly
TRICIBLE_FORCEINLINE swizzle4<vec4, float, 1, 3, 2, 0> vec4::ywzx() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec4 vec4::zwzx() const { return vec4(this->_z, this->_w, this->_z, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::wwzx() const { return vec4(this->_w, this->_w, this->_z, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::xxwx() const { return vec4(this->_x, this->_x, this->_w, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::yxwx() const { return vec4(this->_y, this->_x, this->_w, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::zxwx() const { return vec4(this->_z, this->_x, this->_w, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::wxwx() const { return vec4(this->_w, this->_x, this->_w, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::xywx() const { return vec4(this->_x, this->_y, this->_w, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::yywx() const { return vec4(this->_y, this->_y, this->_w, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::zywx() const { return vec4(this->_z, this->_y, this->_w, this->_x); } // readonly
TRICIBLE_FORCEINLINE swizzle4<vec4, float, 2, 1, 3, 0> vec4::zywx() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec4 vec4::wywx() const { return vec4(this->_w, this->_y, this->_w, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::xzwx() const { return vec4(this->_x, this->_z, this->_w, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::yzwx() const { return vec4(this->_y, this->_z, this->_w, this->_x); } // readonly
TRICIBLE_FORCEINLINE swizzle4<vec4, float, 1, 2, 3, 0> vec4::yzwx() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec4 vec4::zzwx() const { return vec4(this->_z, this->_z, this->_w, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::wzwx() const { return vec4(this->_w, this->_z, this->_w, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::xwwx() const { return vec4(this->_x, this->_w, this->_w, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::ywwx() const { return vec4(this->_y, this->_w, this->_w, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::zwwx() const { return vec4(this->_z, this->_w, this->_w, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::wwwx() const { return vec4(this->_w, this->_w, this->_w, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::xxxy() const { return vec4(this->_x, this->_x, this->_x, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::yxxy() const { return vec4(this->_y, this->_x, this->_x, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::zxxy() const { return vec4(this->_z, this->_x, this->_x, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::wxxy() const { return vec4(this->_w, this->_x, this->_x, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::xyxy() const { return vec4(this->_x, this->_y, this->_x, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::yyxy() const { return vec4(this->_y, this->_y, this->_x, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::zyxy() const { return vec4(this->_z, this->_y, this->_x, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::wyxy() const { return vec4(this->_w, this->_y, this->_x, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::xzxy() const { return vec4(this->_x, this->_z, this->_x, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::yzxy() const { return vec4(this->_y, this->_z, this->_x, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::zzxy() const { return vec4(this->_z, this->_z, this->_x, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::wzxy() const { return vec4(this->_w, this->_z, this->_x, this->_y); } // readonly
TRICIBLE_FORCEINLINE swizzle4<vec4, float, 3, 2, 0, 1> vec4::wzxy() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec4 vec4::xwxy() const { return vec4(this->_x, this->_w, this->_x, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::ywxy() const { return vec4(this->_y, this->_w, this->_x, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::zwxy() const { return vec4(this->_z, this->_w, this->_x, this->_y); } // readonly
TRICIBLE_FORCEINLINE swizzle4<vec4, float, 2, 3, 0, 1> vec4::zwxy() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec4 vec4::wwxy() const { return vec4(this->_w, this->_w, this->_x, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::xxyy() const { return vec4(this->_x, this->_x, this->_y, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::yxyy() const { return vec4(this->_y, this->_x, this->_y, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::zxyy() const { return vec4(this->_z, this->_x, this->_y, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::wxyy() const { return vec4(this->_w, this->_x, this->_y, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::xyyy() const { return vec4(this->_x, this->_y, this->_y, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::yyyy() const { return vec4(this->_y, this->_y, this->_y, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::zyyy() const { return vec4(this->_z, this->_y, this->_y, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::wyyy() const { return vec4(this->_w, this->_y, this->_y, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::xzyy() const { return vec4(this->_x, this->_z, this->_y, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::yzyy() const { return vec4(this->_y, this->_z, this->_y, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::zzyy() const { return vec4(this->_z, this->_z, this->_y, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::wzyy() const { return vec4(this->_w, this->_z, this->_y, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::xwyy() const { return vec4(this->_x, this->_w, this->_y, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::ywyy() const { return vec4(this->_y, this->_w, this->_y, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::zwyy() const { return vec4(this->_z, this->_w, this->_y, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::wwyy() const { return vec4(this->_w, this->_w, this->_y, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::xxzy() const { return vec4(this->_x, this->_x, this->_z, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::yxzy() const { return vec4(this->_y, this->_x, this->_z, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::zxzy() const { return vec4(this->_z, this->_x, this->_z, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::wxzy() const { return vec4(this->_w, this->_x, this->_z, this->_y); } // readonly
TRICIBLE_FORCEINLINE swizzle4<vec4, float, 3, 0, 2, 1> vec4::wxzy() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec4 vec4::xyzy() const { return vec4(this->_x, this->_y, this->_z, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::yyzy() const { return vec4(this->_y, this->_y, this->_z, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::zyzy() const { return vec4(this->_z, this->_y, this->_z, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::wyzy() const { return vec4(this->_w, this->_y, this->_z, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::xzzy() const { return vec4(this->_x, this->_z, this->_z, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::yzzy() const { return vec4(this->_y, this->_z, this->_z, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::zzzy() const { return vec4(this->_z, this->_z, this->_z, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::wzzy() const { return vec4(this->_w, this->_z, this->_z, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::xwzy() const { return vec4(this->_x, this->_w, this->_z, this->_y); } // readonly
TRICIBLE_FORCEINLINE swizzle4<vec4, float, 0, 3, 2, 1> vec4::xwzy() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec4 vec4::ywzy() const { return vec4(this->_y, this->_w, this->_z, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::zwzy() const { return vec4(this->_z, this->_w, this->_z, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::wwzy() const { return vec4(this->_w, this->_w, this->_z, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::xxwy() const { return vec4(this->_x, this->_x, this->_w, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::yxwy() const { return vec4(this->_y, this->_x, this->_w, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::zxwy() const { return vec4(this->_z, this->_x, this->_w, this->_y); } // readonly
TRICIBLE_FORCEINLINE swizzle4<vec4, float, 2, 0, 3, 1> vec4::zxwy() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec4 vec4::wxwy() const { return vec4(this->_w, this->_x, this->_w, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::xywy() const { return vec4(this->_x, this->_y, this->_w, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::yywy() const { return vec4(this->_y, this->_y, this->_w, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::zywy() const { return vec4(this->_z, this->_y, this->_w, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::wywy() const { return vec4(this->_w, this->_y, this->_w, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::xzwy() const { return vec4(this->_x, this->_z, this->_w, this->_y); } // readonly
TRICIBLE_FORCEINLINE swizzle4<vec4, float, 0, 2, 3, 1> vec4::xzwy() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec4 vec4::yzwy() const { return vec4(this->_y, this->_z, this->_w, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::zzwy() const { return vec4(this->_z, this->_z, this->_w, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::wzwy() const { return vec4(this->_w, this->_z, this->_w, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::xwwy() const { return vec4(this->_x, this->_w, this->_w, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::ywwy() const { return vec4(this->_y, this->_w, this->_w, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::zwwy() const { return vec4(this->_z, this->_w, this->_w, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::wwwy() const { return vec4(this->_w, this->_w, this->_w, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::xxxz() const { return vec4(this->_x, this->_x, this->_x, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::yxxz() const { return vec4(this->_y, this->_x, this->_x, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::zxxz() const { return vec4(this->_z, this->_x, this->_x, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::wxxz() const { return vec4(this->_w, this->_x, this->_x, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::xyxz() const { return vec4(this->_x, this->_y, this->_x, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::yyxz() const { return vec4(this->_y, this->_y, this->_x, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::zyxz() const { return vec4(this->_z, this->_y, this->_x, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::wyxz() const { return vec4(this->_w, this->_y, this->_x, this->_z); } // readonly
TRICIBLE_FORCEINLINE swizzle4<vec4, float, 3, 1, 0, 2> vec4::wyxz() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec4 vec4::xzxz() const { return vec4(this->_x, this->_z, this->_x, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::yzxz() const { return vec4(this->_y, this->_z, this->_x, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::zzxz() const { return vec4(this->_z, this->_z, this->_x, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::wzxz() const { return vec4(this->_w, this->_z, this->_x, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::xwxz() const { return vec4(this->_x, this->_w, this->_x, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::ywxz() const { return vec4(this->_y, this->_w, this->_x, this->_z); } // readonly
TRICIBLE_FORCEINLINE swizzle4<vec4, float, 1, 3, 0, 2> vec4::ywxz() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec4 vec4::zwxz() const { return vec4(this->_z, this->_w, this->_x, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::wwxz() const { return vec4(this->_w, this->_w, this->_x, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::xxyz() const { return vec4(this->_x, this->_x, this->_y, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::yxyz() const { return vec4(this->_y, this->_x, this->_y, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::zxyz() const { return vec4(this->_z, this->_x, this->_y, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::wxyz() const { return vec4(this->_w, this->_x, this->_y, this->_z); } // readonly
TRICIBLE_FORCEINLINE swizzle4<vec4, float, 3, 0, 1, 2> vec4::wxyz() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec4 vec4::xyyz() const { return vec4(this->_x, this->_y, this->_y, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::yyyz() const { return vec4(this->_y, this->_y, this->_y, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::zyyz() const { return vec4(this->_z, this->_y, this->_y, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::wyyz() const { return vec4(this->_w, this->_y, this->_y, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::xzyz() const { return vec4(this->_x, this->_z, this->_y, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::yzyz() const { return vec4(this->_y, this->_z, this->_y, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::zzyz() const { return vec4(this->_z, this->_z, this->_y, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::wzyz() const { return vec4(this->_w, this->_z, this->_y, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::xwyz() const { return vec4(this->_x, this->_w, this->_y, this->_z); } // readonly
TRICIBLE_FORCEINLINE swizzle4<vec4, float, 0, 3, 1, 2> vec4::xwyz() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec4 vec4::ywyz() const { return vec4(this->_y, this->_w, this->_y, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::zwyz() const { return vec4(this->_z, this->_w, this->_y, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::wwyz() const { return vec4(this->_w, this->_w, this->_y, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::xxzz() const { return vec4(this->_x, this->_x, this->_z, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::yxzz() const { return vec4(this->_y, this->_x, this->_z, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::zxzz() const { return vec4(this->_z, this->_x, this->_z, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::wxzz() const { return vec4(this->_w, this->_x, this->_z, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::xyzz() const { return vec4(this->_x, this->_y, this->_z, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::yyzz() const { return vec4(this->_y, this->_y, this->_z, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::zyzz() const { return vec4(this->_z, this->_y, this->_z, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::wyzz() const { return vec4(this->_w, this->_y, this->_z, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::xzzz() const { return vec4(this->_x, this->_z, this->_z, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::yzzz() const { return vec4(this->_y, this->_z, this->_z, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::zzzz() const { return vec4(this->_z, this->_z, this->_z, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::wzzz() const { return vec4(this->_w, this->_z, this->_z, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::xwzz() const { return vec4(this->_x, this->_w, this->_z, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::ywzz() const { return vec4(this->_y, this->_w, this->_z, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::zwzz() const { return vec4(this->_z, this->_w, this->_z, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::wwzz() const { return vec4(this->_w, this->_w, this->_z, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::xxwz() const { return vec4(this->_x, this->_x, this->_w, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::yxwz() const { return vec4(this->_y, this->_x, this->_w, this->_z); } // readonly
TRICIBLE_FORCEINLINE swizzle4<vec4, float, 1, 0, 3, 2> vec4::yxwz() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec4 vec4::zxwz() const { return vec4(this->_z, this->_x, this->_w, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::wxwz() const { return vec4(this->_w, this->_x, this->_w, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::xywz() const { return vec4(this->_x, this->_y, this->_w, this->_z); } // readonly
TRICIBLE_FORCEINLINE swizzle4<vec4, float, 0, 1, 3, 2> vec4::xywz() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec4 vec4::yywz() const { return vec4(this->_y, this->_y, this->_w, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::zywz() const { return vec4(this->_z, this->_y, this->_w, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::wywz() const { return vec4(this->_w, this->_y, this->_w, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::xzwz() const { return vec4(this->_x, this->_z, this->_w, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::yzwz() const { return vec4(this->_y, this->_z, this->_w, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::zzwz() const { return vec4(this->_z, this->_z, this->_w, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::wzwz() const { return vec4(this->_w, this->_z, this->_w, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::xwwz() const { return vec4(this->_x, this->_w, this->_w, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::ywwz() const { return vec4(this->_y, this->_w, this->_w, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::zwwz() const { return vec4(this->_z, this->_w, this->_w, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::wwwz() const { return vec4(this->_w, this->_w, this->_w, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::xxxw() const { return vec4(this->_x, this->_x, this->_x, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::yxxw() const { return vec4(this->_y, this->_x, this->_x, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::zxxw() const { return vec4(this->_z, this->_x, this->_x, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::wxxw() const { return vec4(this->_w, this->_x, this->_x, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::xyxw() const { return vec4(this->_x, this->_y, this->_x, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::yyxw() const { return vec4(this->_y, this->_y, this->_x, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::zyxw() const { return vec4(this->_z, this->_y, this->_x, this->_w); } // readonly
TRICIBLE_FORCEINLINE swizzle4<vec4, float, 2, 1, 0, 3> vec4::zyxw() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec4 vec4::wyxw() const { return vec4(this->_w, this->_y, this->_x, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::xzxw() const { return vec4(this->_x, this->_z, this->_x, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::yzxw() const { return vec4(this->_y, this->_z, this->_x, this->_w); } // readonly
TRICIBLE_FORCEINLINE swizzle4<vec4, float, 1, 2, 0, 3> vec4::yzxw() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec4 vec4::zzxw() const { return vec4(this->_z, this->_z, this->_x, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::wzxw() const { return vec4(this->_w, this->_z, this->_x, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::xwxw() const { return vec4(this->_x, this->_w, this->_x, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::ywxw() const { return vec4(this->_y, this->_w, this->_x, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::zwxw() const { return vec4(this->_z, this->_w, this->_x, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::wwxw() const { return vec4(this->_w, this->_w, this->_x, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::xxyw() const { return vec4(this->_x, this->_x, this->_y, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::yxyw() const { return vec4(this->_y, this->_x, this->_y, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::zxyw() const { return vec4(this->_z, this->_x, this->_y, this->_w); } // readonly
TRICIBLE_FORCEINLINE swizzle4<vec4, float, 2, 0, 1, 3> vec4::zxyw() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec4 vec4::wxyw() const { return vec4(this->_w, this->_x, this->_y, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::xyyw() const { return vec4(this->_x, this->_y, this->_y, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::yyyw() const { return vec4(this->_y, this->_y, this->_y, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::zyyw() const { return vec4(this->_z, this->_y, this->_y, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::wyyw() const { return vec4(this->_w, this->_y, this->_y, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::xzyw() const { return vec4(this->_x, this->_z, this->_y, this->_w); } // readonly
TRICIBLE_FORCEINLINE swizzle4<vec4, float, 0, 2, 1, 3> vec4::xzyw() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec4 vec4::yzyw() const { return vec4(this->_y, this->_z, this->_y, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::zzyw() const { return vec4(this->_z, this->_z, this->_y, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::wzyw() const { return vec4(this->_w, this->_z, this->_y, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::xwyw() const { return vec4(this->_x, this->_w, this->_y, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::ywyw() const { return vec4(this->_y, this->_w, this->_y, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::zwyw() const { return vec4(this->_z, this->_w, this->_y, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::wwyw() const { return vec4(this->_w, this->_w, this->_y, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::xxzw() const { return vec4(this->_x, this->_x, this->_z, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::yxzw() const { return vec4(this->_y, this->_x, this->_z, this->_w); } // readonly
TRICIBLE_FORCEINLINE swizzle4<vec4, float, 1, 0, 2, 3> vec4::yxzw() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec4 vec4::zxzw() const { return vec4(this->_z, this->_x, this->_z, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::wxzw() const { return vec4(this->_w, this->_x, this->_z, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::xyzw() const { return vec4(this->_x, this->_y, this->_z, this->_w); } // readonly
TRICIBLE_FORCEINLINE swizzle4<vec4, float, 0, 1, 2, 3> vec4::xyzw() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec4 vec4::yyzw() const { return vec4(this->_y, this->_y, this->_z, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::zyzw() const { return vec4(this->_z, this->_y, this->_z, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::wyzw() const { return vec4(this->_w, this->_y, this->_z, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::xzzw() const { return vec4(this->_x, this->_z, this->_z, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::yzzw() const { return vec4(this->_y, this->_z, this->_z, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::zzzw() const { return vec4(this->_z, this->_z, this->_z, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::wzzw() const { return vec4(this->_w, this->_z, this->_z, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::xwzw() const { return vec4(this->_x, this->_w, this->_z, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::ywzw() const { return vec4(this->_y, this->_w, this->_z, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::zwzw() const { return vec4(this->_z, this->_w, this->_z, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::wwzw() const { return vec4(this->_w, this->_w, this->_z, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::xxww() const { return vec4(this->_x, this->_x, this->_w, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::yxww() const { return vec4(this->_y, this->_x, this->_w, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::zxww() const { return vec4(this->_z, this->_x, this->_w, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::wxww() const { return vec4(this->_w, this->_x, this->_w, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::xyww() const { return vec4(this->_x, this->_y, this->_w, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::yyww() const { return vec4(this->_y, this->_y, this->_w, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::zyww() const { return vec4(this->_z, this->_y, this->_w, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::wyww() const { return vec4(this->_w, this->_y, this->_w, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::xzww() const { return vec4(this->_x, this->_z, this->_w, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::yzww() const { return vec4(this->_y, this->_z, this->_w, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::zzww() const { return vec4(this->_z, this->_z, this->_w, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::wzww() const { return vec4(this->_w, this->_z, this->_w, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::xwww() const { return vec4(this->_x, this->_w, this->_w, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::ywww() const { return vec4(this->_y, this->_w, this->_w, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::zwww() const { return vec4(this->_z, this->_w, this->_w, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::wwww() const { return vec4(this->_w, this->_w, this->_w, this->_w); } // readonly

TRICIBLE_FORCEINLINE float vec4::r() const { return this->_x; } // readonly
TRICIBLE_FORCEINLINE swizzle1<vec4, float, 0> vec4::r() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE float vec4::g() const { return this->_y; } // readonly
TRICIBLE_FORCEINLINE swizzle1<vec4, float, 1> vec4::g() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE float vec4::b() const { return this->_z; } // readonly
TRICIBLE_FORCEINLINE swizzle1<vec4, float, 2> vec4::b() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE float vec4::a() const { return this->_w; } // readonly
TRICIBLE_FORCEINLINE swizzle1<vec4, float, 3> vec4::a() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec2 vec4::rr() const { return vec2(this->_x, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec2 vec4::gr() const { return vec2(this->_y, this->_x); } // readonly
TRICIBLE_FORCEINLINE swizzle2<vec4, float, 1, 0> vec4::gr() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec2 vec4::br() const { return vec2(this->_z, this->_x); } // readonly
TRICIBLE_FORCEINLINE swizzle2<vec4, float, 2, 0> vec4::br() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec2 vec4::ar() const { return vec2(this->_w, this->_x); } // readonly
TRICIBLE_FORCEINLINE swizzle2<vec4, float, 3, 0> vec4::ar() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec2 vec4::rg() const { return vec2(this->_x, this->_y); } // readonly
TRICIBLE_FORCEINLINE swizzle2<vec4, float, 0, 1> vec4::rg() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec2 vec4::gg() const { return vec2(this->_y, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec2 vec4::bg() const { return vec2(this->_z, this->_y); } // readonly
TRICIBLE_FORCEINLINE swizzle2<vec4, float, 2, 1> vec4::bg() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec2 vec4::ag() const { return vec2(this->_w, this->_y); } // readonly
TRICIBLE_FORCEINLINE swizzle2<vec4, float, 3, 1> vec4::ag() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec2 vec4::rb() const { return vec2(this->_x, this->_z); } // readonly
TRICIBLE_FORCEINLINE swizzle2<vec4, float, 0, 2> vec4::rb() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec2 vec4::gb() const { return vec2(this->_y, this->_z); } // readonly
TRICIBLE_FORCEINLINE swizzle2<vec4, float, 1, 2> vec4::gb() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec2 vec4::bb() const { return vec2(this->_z, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec2 vec4::ab() const { return vec2(this->_w, this->_z); } // readonly
TRICIBLE_FORCEINLINE swizzle2<vec4, float, 3, 2> vec4::ab() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec2 vec4::ra() const { return vec2(this->_x, this->_w); } // readonly
TRICIBLE_FORCEINLINE swizzle2<vec4, float, 0, 3> vec4::ra() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec2 vec4::ga() const { return vec2(this->_y, this->_w); } // readonly
TRICIBLE_FORCEINLINE swizzle2<vec4, float, 1, 3> vec4::ga() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec2 vec4::ba() const { return vec2(this->_z, this->_w); } // readonly
TRICIBLE_FORCEINLINE swizzle2<vec4, float, 2, 3> vec4::ba() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec2 vec4::aa() const { return vec2(this->_w, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec3 vec4::rrr() const { return vec3(this->_x, this->_x, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec3 vec4::grr() const { return vec3(this->_y, this->_x, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec3 vec4::brr() const { return vec3(this->_z, this->_x, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec3 vec4::arr() const { return vec3(this->_w, this->_x, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec3 vec4::rgr() const { return vec3(this->_x, this->_y, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec3 vec4::ggr() const { return vec3(this->_y, this->_y, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec3 vec4::bgr() const { return vec3(this->_z, this->_y, this->_x); } // readonly
TRICIBLE_FORCEINLINE swizzle3<vec4, float, 2, 1, 0> vec4::bgr() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec3 vec4::agr() const { return vec3(this->_w, this->_y, this->_x); } // readonly
TRICIBLE_FORCEINLINE swizzle3<vec4, float, 3, 1, 0> vec4::agr() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec3 vec4::rbr() const { return vec3(this->_x, this->_z, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec3 vec4::gbr() const { return vec3(this->_y, this->_z, this->_x); } // readonly
TRICIBLE_FORCEINLINE swizzle3<vec4, float, 1, 2, 0> vec4::gbr() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec3 vec4::bbr() const { return vec3(this->_z, this->_z, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec3 vec4::abr() const { return vec3(this->_w, this->_z, this->_x); } // readonly
TRICIBLE_FORCEINLINE swizzle3<vec4, float, 3, 2, 0> vec4::abr() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec3 vec4::rar() const { return vec3(this->_x, this->_w, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec3 vec4::gar() const { return vec3(this->_y, this->_w, this->_x); } // readonly
TRICIBLE_FORCEINLINE swizzle3<vec4, float, 1, 3, 0> vec4::gar() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec3 vec4::bar() const { return vec3(this->_z, this->_w, this->_x); } // readonly
TRICIBLE_FORCEINLINE swizzle3<vec4, float, 2, 3, 0> vec4::bar() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec3 vec4::aar() const { return vec3(this->_w, this->_w, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec3 vec4::rrg() const { return vec3(this->_x, this->_x, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec3 vec4::grg() const { return vec3(this->_y, this->_x, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec3 vec4::brg() const { return vec3(this->_z, this->_x, this->_y); } // readonly
TRICIBLE_FORCEINLINE swizzle3<vec4, float, 2, 0, 1> vec4::brg() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec3 vec4::arg() const { return vec3(this->_w, this->_x, this->_y); } // readonly
TRICIBLE_FORCEINLINE swizzle3<vec4, float, 3, 0, 1> vec4::arg() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec3 vec4::rgg() const { return vec3(this->_x, this->_y, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec3 vec4::ggg() const { return vec3(this->_y, this->_y, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec3 vec4::bgg() const { return vec3(this->_z, this->_y, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec3 vec4::agg() const { return vec3(this->_w, this->_y, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec3 vec4::rbg() const { return vec3(this->_x, this->_z, this->_y); } // readonly
TRICIBLE_FORCEINLINE swizzle3<vec4, float, 0, 2, 1> vec4::rbg() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec3 vec4::gbg() const { return vec3(this->_y, this->_z, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec3 vec4::bbg() const { return vec3(this->_z, this->_z, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec3 vec4::abg() const { return vec3(this->_w, this->_z, this->_y); } // readonly
TRICIBLE_FORCEINLINE swizzle3<vec4, float, 3, 2, 1> vec4::abg() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec3 vec4::rag() const { return vec3(this->_x, this->_w, this->_y); } // readonly
TRICIBLE_FORCEINLINE swizzle3<vec4, float, 0, 3, 1> vec4::rag() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec3 vec4::gag() const { return vec3(this->_y, this->_w, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec3 vec4::bag() const { return vec3(this->_z, this->_w, this->_y); } // readonly
TRICIBLE_FORCEINLINE swizzle3<vec4, float, 2, 3, 1> vec4::bag() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec3 vec4::aag() const { return vec3(this->_w, this->_w, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec3 vec4::rrb() const { return vec3(this->_x, this->_x, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec3 vec4::grb() const { return vec3(this->_y, this->_x, this->_z); } // readonly
TRICIBLE_FORCEINLINE swizzle3<vec4, float, 1, 0, 2> vec4::grb() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec3 vec4::brb() const { return vec3(this->_z, this->_x, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec3 vec4::arb() const { return vec3(this->_w, this->_x, this->_z); } // readonly
TRICIBLE_FORCEINLINE swizzle3<vec4, float, 3, 0, 2> vec4::arb() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec3 vec4::rgb() const { return vec3(this->_x, this->_y, this->_z); } // readonly
TRICIBLE_FORCEINLINE swizzle3<vec4, float, 0, 1, 2> vec4::rgb() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec3 vec4::ggb() const { return vec3(this->_y, this->_y, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec3 vec4::bgb() const { return vec3(this->_z, this->_y, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec3 vec4::agb() const { return vec3(this->_w, this->_y, this->_z); } // readonly
TRICIBLE_FORCEINLINE swizzle3<vec4, float, 3, 1, 2> vec4::agb() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec3 vec4::rbb() const { return vec3(this->_x, this->_z, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec3 vec4::gbb() const { return vec3(this->_y, this->_z, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec3 vec4::bbb() const { return vec3(this->_z, this->_z, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec3 vec4::abb() const { return vec3(this->_w, this->_z, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec3 vec4::rab() const { return vec3(this->_x, this->_w, this->_z); } // readonly
TRICIBLE_FORCEINLINE swizzle3<vec4, float, 0, 3, 2> vec4::rab() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec3 vec4::gab() const { return vec3(this->_y, this->_w, this->_z); } // readonly
TRICIBLE_FORCEINLINE swizzle3<vec4, float, 1, 3, 2> vec4::gab() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec3 vec4::bab() const { return vec3(this->_z, this->_w, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec3 vec4::aab() const { return vec3(this->_w, this->_w, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec3 vec4::rra() const { return vec3(this->_x, this->_x, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec3 vec4::gra() const { return vec3(this->_y, this->_x, this->_w); } // readonly
TRICIBLE_FORCEINLINE swizzle3<vec4, float, 1, 0, 3> vec4::gra() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec3 vec4::bra() const { return vec3(this->_z, this->_x, this->_w); } // readonly
TRICIBLE_FORCEINLINE swizzle3<vec4, float, 2, 0, 3> vec4::bra() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec3 vec4::ara() const { return vec3(this->_w, this->_x, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec3 vec4::rga() const { return vec3(this->_x, this->_y, this->_w); } // readonly
TRICIBLE_FORCEINLINE swizzle3<vec4, float, 0, 1, 3> vec4::rga() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec3 vec4::gga() const { return vec3(this->_y, this->_y, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec3 vec4::bga() const { return vec3(this->_z, this->_y, this->_w); } // readonly
TRICIBLE_FORCEINLINE swizzle3<vec4, float, 2, 1, 3> vec4::bga() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec3 vec4::aga() const { return vec3(this->_w, this->_y, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec3 vec4::rba() const { return vec3(this->_x, this->_z, this->_w); } // readonly
TRICIBLE_FORCEINLINE swizzle3<vec4, float, 0, 2, 3> vec4::rba() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec3 vec4::gba() const { return vec3(this->_y, this->_z, this->_w); } // readonly
TRICIBLE_FORCEINLINE swizzle3<vec4, float, 1, 2, 3> vec4::gba() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec3 vec4::bba() const { return vec3(this->_z, this->_z, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec3 vec4::aba() const { return vec3(this->_w, this->_z, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec3 vec4::raa() const { return vec3(this->_x, this->_w, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec3 vec4::gaa() const { return vec3(this->_y, this->_w, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec3 vec4::baa() const { return vec3(this->_z, this->_w, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec3 vec4::aaa() const { return vec3(this->_w, this->_w, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::rrrr() const { return vec4(this->_x, this->_x, this->_x, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::grrr() const { return vec4(this->_y, this->_x, this->_x, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::brrr() const { return vec4(this->_z, this->_x, this->_x, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::arrr() const { return vec4(this->_w, this->_x, this->_x, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::rgrr() const { return vec4(this->_x, this->_y, this->_x, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::ggrr() const { return vec4(this->_y, this->_y, this->_x, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::bgrr() const { return vec4(this->_z, this->_y, this->_x, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::agrr() const { return vec4(this->_w, this->_y, this->_x, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::rbrr() const { return vec4(this->_x, this->_z, this->_x, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::gbrr() const { return vec4(this->_y, this->_z, this->_x, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::bbrr() const { return vec4(this->_z, this->_z, this->_x, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::abrr() const { return vec4(this->_w, this->_z, this->_x, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::rarr() const { return vec4(this->_x, this->_w, this->_x, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::garr() const { return vec4(this->_y, this->_w, this->_x, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::barr() const { return vec4(this->_z, this->_w, this->_x, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::aarr() const { return vec4(this->_w, this->_w, this->_x, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::rrgr() const { return vec4(this->_x, this->_x, this->_y, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::grgr() const { return vec4(this->_y, this->_x, this->_y, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::brgr() const { return vec4(this->_z, this->_x, this->_y, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::argr() const { return vec4(this->_w, this->_x, this->_y, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::rggr() const { return vec4(this->_x, this->_y, this->_y, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::gggr() const { return vec4(this->_y, this->_y, this->_y, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::bggr() const { return vec4(this->_z, this->_y, this->_y, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::aggr() const { return vec4(this->_w, this->_y, this->_y, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::rbgr() const { return vec4(this->_x, this->_z, this->_y, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::gbgr() const { return vec4(this->_y, this->_z, this->_y, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::bbgr() const { return vec4(this->_z, this->_z, this->_y, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::abgr() const { return vec4(this->_w, this->_z, this->_y, this->_x); } // readonly
TRICIBLE_FORCEINLINE swizzle4<vec4, float, 3, 2, 1, 0> vec4::abgr() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec4 vec4::ragr() const { return vec4(this->_x, this->_w, this->_y, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::gagr() const { return vec4(this->_y, this->_w, this->_y, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::bagr() const { return vec4(this->_z, this->_w, this->_y, this->_x); } // readonly
TRICIBLE_FORCEINLINE swizzle4<vec4, float, 2, 3, 1, 0> vec4::bagr() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec4 vec4::aagr() const { return vec4(this->_w, this->_w, this->_y, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::rrbr() const { return vec4(this->_x, this->_x, this->_z, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::grbr() const { return vec4(this->_y, this->_x, this->_z, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::brbr() const { return vec4(this->_z, this->_x, this->_z, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::arbr() const { return vec4(this->_w, this->_x, this->_z, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::rgbr() const { return vec4(this->_x, this->_y, this->_z, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::ggbr() const { return vec4(this->_y, this->_y, this->_z, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::bgbr() const { return vec4(this->_z, this->_y, this->_z, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::agbr() const { return vec4(this->_w, this->_y, this->_z, this->_x); } // readonly
TRICIBLE_FORCEINLINE swizzle4<vec4, float, 3, 1, 2, 0> vec4::agbr() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec4 vec4::rbbr() const { return vec4(this->_x, this->_z, this->_z, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::gbbr() const { return vec4(this->_y, this->_z, this->_z, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::bbbr() const { return vec4(this->_z, this->_z, this->_z, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::abbr() const { return vec4(this->_w, this->_z, this->_z, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::rabr() const { return vec4(this->_x, this->_w, this->_z, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::gabr() const { return vec4(this->_y, this->_w, this->_z, this->_x); } // readonly
TRICIBLE_FORCEINLINE swizzle4<vec4, float, 1, 3, 2, 0> vec4::gabr() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec4 vec4::babr() const { return vec4(this->_z, this->_w, this->_z, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::aabr() const { return vec4(this->_w, this->_w, this->_z, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::rrar() const { return vec4(this->_x, this->_x, this->_w, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::grar() const { return vec4(this->_y, this->_x, this->_w, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::brar() const { return vec4(this->_z, this->_x, this->_w, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::arar() const { return vec4(this->_w, this->_x, this->_w, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::rgar() const { return vec4(this->_x, this->_y, this->_w, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::ggar() const { return vec4(this->_y, this->_y, this->_w, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::bgar() const { return vec4(this->_z, this->_y, this->_w, this->_x); } // readonly
TRICIBLE_FORCEINLINE swizzle4<vec4, float, 2, 1, 3, 0> vec4::bgar() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec4 vec4::agar() const { return vec4(this->_w, this->_y, this->_w, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::rbar() const { return vec4(this->_x, this->_z, this->_w, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::gbar() const { return vec4(this->_y, this->_z, this->_w, this->_x); } // readonly
TRICIBLE_FORCEINLINE swizzle4<vec4, float, 1, 2, 3, 0> vec4::gbar() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec4 vec4::bbar() const { return vec4(this->_z, this->_z, this->_w, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::abar() const { return vec4(this->_w, this->_z, this->_w, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::raar() const { return vec4(this->_x, this->_w, this->_w, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::gaar() const { return vec4(this->_y, this->_w, this->_w, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::baar() const { return vec4(this->_z, this->_w, this->_w, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::aaar() const { return vec4(this->_w, this->_w, this->_w, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::rrrg() const { return vec4(this->_x, this->_x, this->_x, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::grrg() const { return vec4(this->_y, this->_x, this->_x, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::brrg() const { return vec4(this->_z, this->_x, this->_x, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::arrg() const { return vec4(this->_w, this->_x, this->_x, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::rgrg() const { return vec4(this->_x, this->_y, this->_x, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::ggrg() const { return vec4(this->_y, this->_y, this->_x, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::bgrg() const { return vec4(this->_z, this->_y, this->_x, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::agrg() const { return vec4(this->_w, this->_y, this->_x, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::rbrg() const { return vec4(this->_x, this->_z, this->_x, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::gbrg() const { return vec4(this->_y, this->_z, this->_x, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::bbrg() const { return vec4(this->_z, this->_z, this->_x, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::abrg() const { return vec4(this->_w, this->_z, this->_x, this->_y); } // readonly
TRICIBLE_FORCEINLINE swizzle4<vec4, float, 3, 2, 0, 1> vec4::abrg() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec4 vec4::rarg() const { return vec4(this->_x, this->_w, this->_x, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::garg() const { return vec4(this->_y, this->_w, this->_x, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::barg() const { return vec4(this->_z, this->_w, this->_x, this->_y); } // readonly
TRICIBLE_FORCEINLINE swizzle4<vec4, float, 2, 3, 0, 1> vec4::barg() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec4 vec4::aarg() const { return vec4(this->_w, this->_w, this->_x, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::rrgg() const { return vec4(this->_x, this->_x, this->_y, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::grgg() const { return vec4(this->_y, this->_x, this->_y, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::brgg() const { return vec4(this->_z, this->_x, this->_y, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::argg() const { return vec4(this->_w, this->_x, this->_y, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::rggg() const { return vec4(this->_x, this->_y, this->_y, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::gggg() const { return vec4(this->_y, this->_y, this->_y, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::bggg() const { return vec4(this->_z, this->_y, this->_y, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::aggg() const { return vec4(this->_w, this->_y, this->_y, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::rbgg() const { return vec4(this->_x, this->_z, this->_y, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::gbgg() const { return vec4(this->_y, this->_z, this->_y, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::bbgg() const { return vec4(this->_z, this->_z, this->_y, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::abgg() const { return vec4(this->_w, this->_z, this->_y, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::ragg() const { return vec4(this->_x, this->_w, this->_y, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::gagg() const { return vec4(this->_y, this->_w, this->_y, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::bagg() const { return vec4(this->_z, this->_w, this->_y, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::aagg() const { return vec4(this->_w, this->_w, this->_y, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::rrbg() const { return vec4(this->_x, this->_x, this->_z, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::grbg() const { return vec4(this->_y, this->_x, this->_z, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::brbg() const { return vec4(this->_z, this->_x, this->_z, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::arbg() const { return vec4(this->_w, this->_x, this->_z, this->_y); } // readonly
TRICIBLE_FORCEINLINE swizzle4<vec4, float, 3, 0, 2, 1> vec4::arbg() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec4 vec4::rgbg() const { return vec4(this->_x, this->_y, this->_z, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::ggbg() const { return vec4(this->_y, this->_y, this->_z, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::bgbg() const { return vec4(this->_z, this->_y, this->_z, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::agbg() const { return vec4(this->_w, this->_y, this->_z, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::rbbg() const { return vec4(this->_x, this->_z, this->_z, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::gbbg() const { return vec4(this->_y, this->_z, this->_z, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::bbbg() const { return vec4(this->_z, this->_z, this->_z, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::abbg() const { return vec4(this->_w, this->_z, this->_z, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::rabg() const { return vec4(this->_x, this->_w, this->_z, this->_y); } // readonly
TRICIBLE_FORCEINLINE swizzle4<vec4, float, 0, 3, 2, 1> vec4::rabg() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec4 vec4::gabg() const { return vec4(this->_y, this->_w, this->_z, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::babg() const { return vec4(this->_z, this->_w, this->_z, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::aabg() const { return vec4(this->_w, this->_w, this->_z, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::rrag() const { return vec4(this->_x, this->_x, this->_w, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::grag() const { return vec4(this->_y, this->_x, this->_w, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::brag() const { return vec4(this->_z, this->_x, this->_w, this->_y); } // readonly
TRICIBLE_FORCEINLINE swizzle4<vec4, float, 2, 0, 3, 1> vec4::brag() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec4 vec4::arag() const { return vec4(this->_w, this->_x, this->_w, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::rgag() const { return vec4(this->_x, this->_y, this->_w, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::ggag() const { return vec4(this->_y, this->_y, this->_w, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::bgag() const { return vec4(this->_z, this->_y, this->_w, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::agag() const { return vec4(this->_w, this->_y, this->_w, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::rbag() const { return vec4(this->_x, this->_z, this->_w, this->_y); } // readonly
TRICIBLE_FORCEINLINE swizzle4<vec4, float, 0, 2, 3, 1> vec4::rbag() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec4 vec4::gbag() const { return vec4(this->_y, this->_z, this->_w, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::bbag() const { return vec4(this->_z, this->_z, this->_w, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::abag() const { return vec4(this->_w, this->_z, this->_w, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::raag() const { return vec4(this->_x, this->_w, this->_w, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::gaag() const { return vec4(this->_y, this->_w, this->_w, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::baag() const { return vec4(this->_z, this->_w, this->_w, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::aaag() const { return vec4(this->_w, this->_w, this->_w, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::rrrb() const { return vec4(this->_x, this->_x, this->_x, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::grrb() const { return vec4(this->_y, this->_x, this->_x, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::brrb() const { return vec4(this->_z, this->_x, this->_x, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::arrb() const { return vec4(this->_w, this->_x, this->_x, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::rgrb() const { return vec4(this->_x, this->_y, this->_x, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::ggrb() const { return vec4(this->_y, this->_y, this->_x, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::bgrb() const { return vec4(this->_z, this->_y, this->_x, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::agrb() const { return vec4(this->_w, this->_y, this->_x, this->_z); } // readonly
TRICIBLE_FORCEINLINE swizzle4<vec4, float, 3, 1, 0, 2> vec4::agrb() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec4 vec4::rbrb() const { return vec4(this->_x, this->_z, this->_x, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::gbrb() const { return vec4(this->_y, this->_z, this->_x, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::bbrb() const { return vec4(this->_z, this->_z, this->_x, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::abrb() const { return vec4(this->_w, this->_z, this->_x, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::rarb() const { return vec4(this->_x, this->_w, this->_x, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::garb() const { return vec4(this->_y, this->_w, this->_x, this->_z); } // readonly
TRICIBLE_FORCEINLINE swizzle4<vec4, float, 1, 3, 0, 2> vec4::garb() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec4 vec4::barb() const { return vec4(this->_z, this->_w, this->_x, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::aarb() const { return vec4(this->_w, this->_w, this->_x, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::rrgb() const { return vec4(this->_x, this->_x, this->_y, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::grgb() const { return vec4(this->_y, this->_x, this->_y, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::brgb() const { return vec4(this->_z, this->_x, this->_y, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::argb() const { return vec4(this->_w, this->_x, this->_y, this->_z); } // readonly
TRICIBLE_FORCEINLINE swizzle4<vec4, float, 3, 0, 1, 2> vec4::argb() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec4 vec4::rggb() const { return vec4(this->_x, this->_y, this->_y, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::gggb() const { return vec4(this->_y, this->_y, this->_y, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::bggb() const { return vec4(this->_z, this->_y, this->_y, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::aggb() const { return vec4(this->_w, this->_y, this->_y, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::rbgb() const { return vec4(this->_x, this->_z, this->_y, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::gbgb() const { return vec4(this->_y, this->_z, this->_y, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::bbgb() const { return vec4(this->_z, this->_z, this->_y, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::abgb() const { return vec4(this->_w, this->_z, this->_y, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::ragb() const { return vec4(this->_x, this->_w, this->_y, this->_z); } // readonly
TRICIBLE_FORCEINLINE swizzle4<vec4, float, 0, 3, 1, 2> vec4::ragb() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec4 vec4::gagb() const { return vec4(this->_y, this->_w, this->_y, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::bagb() const { return vec4(this->_z, this->_w, this->_y, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::aagb() const { return vec4(this->_w, this->_w, this->_y, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::rrbb() const { return vec4(this->_x, this->_x, this->_z, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::grbb() const { return vec4(this->_y, this->_x, this->_z, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::brbb() const { return vec4(this->_z, this->_x, this->_z, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::arbb() const { return vec4(this->_w, this->_x, this->_z, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::rgbb() const { return vec4(this->_x, this->_y, this->_z, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::ggbb() const { return vec4(this->_y, this->_y, this->_z, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::bgbb() const { return vec4(this->_z, this->_y, this->_z, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::agbb() const { return vec4(this->_w, this->_y, this->_z, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::rbbb() const { return vec4(this->_x, this->_z, this->_z, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::gbbb() const { return vec4(this->_y, this->_z, this->_z, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::bbbb() const { return vec4(this->_z, this->_z, this->_z, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::abbb() const { return vec4(this->_w, this->_z, this->_z, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::rabb() const { return vec4(this->_x, this->_w, this->_z, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::gabb() const { return vec4(this->_y, this->_w, this->_z, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::babb() const { return vec4(this->_z, this->_w, this->_z, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::aabb() const { return vec4(this->_w, this->_w, this->_z, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::rrab() const { return vec4(this->_x, this->_x, this->_w, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::grab() const { return vec4(this->_y, this->_x, this->_w, this->_z); } // readonly
TRICIBLE_FORCEINLINE swizzle4<vec4, float, 1, 0, 3, 2> vec4::grab() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec4 vec4::brab() const { return vec4(this->_z, this->_x, this->_w, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::arab() const { return vec4(this->_w, this->_x, this->_w, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::rgab() const { return vec4(this->_x, this->_y, this->_w, this->_z); } // readonly
TRICIBLE_FORCEINLINE swizzle4<vec4, float, 0, 1, 3, 2> vec4::rgab() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec4 vec4::ggab() const { return vec4(this->_y, this->_y, this->_w, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::bgab() const { return vec4(this->_z, this->_y, this->_w, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::agab() const { return vec4(this->_w, this->_y, this->_w, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::rbab() const { return vec4(this->_x, this->_z, this->_w, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::gbab() const { return vec4(this->_y, this->_z, this->_w, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::bbab() const { return vec4(this->_z, this->_z, this->_w, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::abab() const { return vec4(this->_w, this->_z, this->_w, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::raab() const { return vec4(this->_x, this->_w, this->_w, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::gaab() const { return vec4(this->_y, this->_w, this->_w, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::baab() const { return vec4(this->_z, this->_w, this->_w, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::aaab() const { return vec4(this->_w, this->_w, this->_w, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::rrra() const { return vec4(this->_x, this->_x, this->_x, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::grra() const { return vec4(this->_y, this->_x, this->_x, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::brra() const { return vec4(this->_z, this->_x, this->_x, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::arra() const { return vec4(this->_w, this->_x, this->_x, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::rgra() const { return vec4(this->_x, this->_y, this->_x, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::ggra() const { return vec4(this->_y, this->_y, this->_x, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::bgra() const { return vec4(this->_z, this->_y, this->_x, this->_w); } // readonly
TRICIBLE_FORCEINLINE swizzle4<vec4, float, 2, 1, 0, 3> vec4::bgra() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec4 vec4::agra() const { return vec4(this->_w, this->_y, this->_x, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::rbra() const { return vec4(this->_x, this->_z, this->_x, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::gbra() const { return vec4(this->_y, this->_z, this->_x, this->_w); } // readonly
TRICIBLE_FORCEINLINE swizzle4<vec4, float, 1, 2, 0, 3> vec4::gbra() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec4 vec4::bbra() const { return vec4(this->_z, this->_z, this->_x, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::abra() const { return vec4(this->_w, this->_z, this->_x, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::rara() const { return vec4(this->_x, this->_w, this->_x, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::gara() const { return vec4(this->_y, this->_w, this->_x, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::bara() const { return vec4(this->_z, this->_w, this->_x, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::aara() const { return vec4(this->_w, this->_w, this->_x, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::rrga() const { return vec4(this->_x, this->_x, this->_y, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::grga() const { return vec4(this->_y, this->_x, this->_y, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::brga() const { return vec4(this->_z, this->_x, this->_y, this->_w); } // readonly
TRICIBLE_FORCEINLINE swizzle4<vec4, float, 2, 0, 1, 3> vec4::brga() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec4 vec4::arga() const { return vec4(this->_w, this->_x, this->_y, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::rgga() const { return vec4(this->_x, this->_y, this->_y, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::ggga() const { return vec4(this->_y, this->_y, this->_y, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::bgga() const { return vec4(this->_z, this->_y, this->_y, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::agga() const { return vec4(this->_w, this->_y, this->_y, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::rbga() const { return vec4(this->_x, this->_z, this->_y, this->_w); } // readonly
TRICIBLE_FORCEINLINE swizzle4<vec4, float, 0, 2, 1, 3> vec4::rbga() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec4 vec4::gbga() const { return vec4(this->_y, this->_z, this->_y, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::bbga() const { return vec4(this->_z, this->_z, this->_y, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::abga() const { return vec4(this->_w, this->_z, this->_y, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::raga() const { return vec4(this->_x, this->_w, this->_y, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::gaga() const { return vec4(this->_y, this->_w, this->_y, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::baga() const { return vec4(this->_z, this->_w, this->_y, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::aaga() const { return vec4(this->_w, this->_w, this->_y, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::rrba() const { return vec4(this->_x, this->_x, this->_z, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::grba() const { return vec4(this->_y, this->_x, this->_z, this->_w); } // readonly
TRICIBLE_FORCEINLINE swizzle4<vec4, float, 1, 0, 2, 3> vec4::grba() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec4 vec4::brba() const { return vec4(this->_z, this->_x, this->_z, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::arba() const { return vec4(this->_w, this->_x, this->_z, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::rgba() const { return vec4(this->_x, this->_y, this->_z, this->_w); } // readonly
TRICIBLE_FORCEINLINE swizzle4<vec4, float, 0, 1, 2, 3> vec4::rgba() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec4 vec4::ggba() const { return vec4(this->_y, this->_y, this->_z, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::bgba() const { return vec4(this->_z, this->_y, this->_z, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::agba() const { return vec4(this->_w, this->_y, this->_z, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::rbba() const { return vec4(this->_x, this->_z, this->_z, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::gbba() const { return vec4(this->_y, this->_z, this->_z, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::bbba() const { return vec4(this->_z, this->_z, this->_z, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::abba() const { return vec4(this->_w, this->_z, this->_z, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::raba() const { return vec4(this->_x, this->_w, this->_z, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::gaba() const { return vec4(this->_y, this->_w, this->_z, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::baba() const { return vec4(this->_z, this->_w, this->_z, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::aaba() const { return vec4(this->_w, this->_w, this->_z, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::rraa() const { return vec4(this->_x, this->_x, this->_w, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::graa() const { return vec4(this->_y, this->_x, this->_w, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::braa() const { return vec4(this->_z, this->_x, this->_w, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::araa() const { return vec4(this->_w, this->_x, this->_w, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::rgaa() const { return vec4(this->_x, this->_y, this->_w, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::ggaa() const { return vec4(this->_y, this->_y, this->_w, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::bgaa() const { return vec4(this->_z, this->_y, this->_w, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::agaa() const { return vec4(this->_w, this->_y, this->_w, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::rbaa() const { return vec4(this->_x, this->_z, this->_w, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::gbaa() const { return vec4(this->_y, this->_z, this->_w, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::bbaa() const { return vec4(this->_z, this->_z, this->_w, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::abaa() const { return vec4(this->_w, this->_z, this->_w, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::raaa() const { return vec4(this->_x, this->_w, this->_w, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::gaaa() const { return vec4(this->_y, this->_w, this->_w, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::baaa() const { return vec4(this->_z, this->_w, this->_w, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::aaaa() const { return vec4(this->_w, this->_w, this->_w, this->_w); } // readonly

TRICIBLE_FORCEINLINE float vec4::s() const { return this->_x; } // readonly
TRICIBLE_FORCEINLINE swizzle1<vec4, float, 0> vec4::s() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE float vec4::t() const { return this->_y; } // readonly
TRICIBLE_FORCEINLINE swizzle1<vec4, float, 1> vec4::t() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE float vec4::p() const { return this->_z; } // readonly
TRICIBLE_FORCEINLINE swizzle1<vec4, float, 2> vec4::p() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE float vec4::q() const { return this->_w; } // readonly
TRICIBLE_FORCEINLINE swizzle1<vec4, float, 3> vec4::q() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec2 vec4::ss() const { return vec2(this->_x, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec2 vec4::ts() const { return vec2(this->_y, this->_x); } // readonly
TRICIBLE_FORCEINLINE swizzle2<vec4, float, 1, 0> vec4::ts() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec2 vec4::ps() const { return vec2(this->_z, this->_x); } // readonly
TRICIBLE_FORCEINLINE swizzle2<vec4, float, 2, 0> vec4::ps() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec2 vec4::qs() const { return vec2(this->_w, this->_x); } // readonly
TRICIBLE_FORCEINLINE swizzle2<vec4, float, 3, 0> vec4::qs() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec2 vec4::st() const { return vec2(this->_x, this->_y); } // readonly
TRICIBLE_FORCEINLINE swizzle2<vec4, float, 0, 1> vec4::st() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec2 vec4::tt() const { return vec2(this->_y, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec2 vec4::pt() const { return vec2(this->_z, this->_y); } // readonly
TRICIBLE_FORCEINLINE swizzle2<vec4, float, 2, 1> vec4::pt() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec2 vec4::qt() const { return vec2(this->_w, this->_y); } // readonly
TRICIBLE_FORCEINLINE swizzle2<vec4, float, 3, 1> vec4::qt() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec2 vec4::sp() const { return vec2(this->_x, this->_z); } // readonly
TRICIBLE_FORCEINLINE swizzle2<vec4, float, 0, 2> vec4::sp() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec2 vec4::tp() const { return vec2(this->_y, this->_z); } // readonly
TRICIBLE_FORCEINLINE swizzle2<vec4, float, 1, 2> vec4::tp() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec2 vec4::pp() const { return vec2(this->_z, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec2 vec4::qp() const { return vec2(this->_w, this->_z); } // readonly
TRICIBLE_FORCEINLINE swizzle2<vec4, float, 3, 2> vec4::qp() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec2 vec4::sq() const { return vec2(this->_x, this->_w); } // readonly
TRICIBLE_FORCEINLINE swizzle2<vec4, float, 0, 3> vec4::sq() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec2 vec4::tq() const { return vec2(this->_y, this->_w); } // readonly
TRICIBLE_FORCEINLINE swizzle2<vec4, float, 1, 3> vec4::tq() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec2 vec4::pq() const { return vec2(this->_z, this->_w); } // readonly
TRICIBLE_FORCEINLINE swizzle2<vec4, float, 2, 3> vec4::pq() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec2 vec4::qq() const { return vec2(this->_w, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec3 vec4::sss() const { return vec3(this->_x, this->_x, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec3 vec4::tss() const { return vec3(this->_y, this->_x, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec3 vec4::pss() const { return vec3(this->_z, this->_x, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec3 vec4::qss() const { return vec3(this->_w, this->_x, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec3 vec4::sts() const { return vec3(this->_x, this->_y, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec3 vec4::tts() const { return vec3(this->_y, this->_y, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec3 vec4::pts() const { return vec3(this->_z, this->_y, this->_x); } // readonly
TRICIBLE_FORCEINLINE swizzle3<vec4, float, 2, 1, 0> vec4::pts() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec3 vec4::qts() const { return vec3(this->_w, this->_y, this->_x); } // readonly
TRICIBLE_FORCEINLINE swizzle3<vec4, float, 3, 1, 0> vec4::qts() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec3 vec4::sps() const { return vec3(this->_x, this->_z, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec3 vec4::tps() const { return vec3(this->_y, this->_z, this->_x); } // readonly
TRICIBLE_FORCEINLINE swizzle3<vec4, float, 1, 2, 0> vec4::tps() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec3 vec4::pps() const { return vec3(this->_z, this->_z, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec3 vec4::qps() const { return vec3(this->_w, this->_z, this->_x); } // readonly
TRICIBLE_FORCEINLINE swizzle3<vec4, float, 3, 2, 0> vec4::qps() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec3 vec4::sqs() const { return vec3(this->_x, this->_w, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec3 vec4::tqs() const { return vec3(this->_y, this->_w, this->_x); } // readonly
TRICIBLE_FORCEINLINE swizzle3<vec4, float, 1, 3, 0> vec4::tqs() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec3 vec4::pqs() const { return vec3(this->_z, this->_w, this->_x); } // readonly
TRICIBLE_FORCEINLINE swizzle3<vec4, float, 2, 3, 0> vec4::pqs() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec3 vec4::qqs() const { return vec3(this->_w, this->_w, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec3 vec4::sst() const { return vec3(this->_x, this->_x, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec3 vec4::tst() const { return vec3(this->_y, this->_x, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec3 vec4::pst() const { return vec3(this->_z, this->_x, this->_y); } // readonly
TRICIBLE_FORCEINLINE swizzle3<vec4, float, 2, 0, 1> vec4::pst() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec3 vec4::qst() const { return vec3(this->_w, this->_x, this->_y); } // readonly
TRICIBLE_FORCEINLINE swizzle3<vec4, float, 3, 0, 1> vec4::qst() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec3 vec4::stt() const { return vec3(this->_x, this->_y, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec3 vec4::ttt() const { return vec3(this->_y, this->_y, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec3 vec4::ptt() const { return vec3(this->_z, this->_y, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec3 vec4::qtt() const { return vec3(this->_w, this->_y, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec3 vec4::spt() const { return vec3(this->_x, this->_z, this->_y); } // readonly
TRICIBLE_FORCEINLINE swizzle3<vec4, float, 0, 2, 1> vec4::spt() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec3 vec4::tpt() const { return vec3(this->_y, this->_z, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec3 vec4::ppt() const { return vec3(this->_z, this->_z, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec3 vec4::qpt() const { return vec3(this->_w, this->_z, this->_y); } // readonly
TRICIBLE_FORCEINLINE swizzle3<vec4, float, 3, 2, 1> vec4::qpt() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec3 vec4::sqt() const { return vec3(this->_x, this->_w, this->_y); } // readonly
TRICIBLE_FORCEINLINE swizzle3<vec4, float, 0, 3, 1> vec4::sqt() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec3 vec4::tqt() const { return vec3(this->_y, this->_w, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec3 vec4::pqt() const { return vec3(this->_z, this->_w, this->_y); } // readonly
TRICIBLE_FORCEINLINE swizzle3<vec4, float, 2, 3, 1> vec4::pqt() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec3 vec4::qqt() const { return vec3(this->_w, this->_w, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec3 vec4::ssp() const { return vec3(this->_x, this->_x, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec3 vec4::tsp() const { return vec3(this->_y, this->_x, this->_z); } // readonly
TRICIBLE_FORCEINLINE swizzle3<vec4, float, 1, 0, 2> vec4::tsp() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec3 vec4::psp() const { return vec3(this->_z, this->_x, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec3 vec4::qsp() const { return vec3(this->_w, this->_x, this->_z); } // readonly
TRICIBLE_FORCEINLINE swizzle3<vec4, float, 3, 0, 2> vec4::qsp() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec3 vec4::stp() const { return vec3(this->_x, this->_y, this->_z); } // readonly
TRICIBLE_FORCEINLINE swizzle3<vec4, float, 0, 1, 2> vec4::stp() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec3 vec4::ttp() const { return vec3(this->_y, this->_y, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec3 vec4::ptp() const { return vec3(this->_z, this->_y, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec3 vec4::qtp() const { return vec3(this->_w, this->_y, this->_z); } // readonly
TRICIBLE_FORCEINLINE swizzle3<vec4, float, 3, 1, 2> vec4::qtp() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec3 vec4::spp() const { return vec3(this->_x, this->_z, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec3 vec4::tpp() const { return vec3(this->_y, this->_z, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec3 vec4::ppp() const { return vec3(this->_z, this->_z, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec3 vec4::qpp() const { return vec3(this->_w, this->_z, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec3 vec4::sqp() const { return vec3(this->_x, this->_w, this->_z); } // readonly
TRICIBLE_FORCEINLINE swizzle3<vec4, float, 0, 3, 2> vec4::sqp() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec3 vec4::tqp() const { return vec3(this->_y, this->_w, this->_z); } // readonly
TRICIBLE_FORCEINLINE swizzle3<vec4, float, 1, 3, 2> vec4::tqp() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec3 vec4::pqp() const { return vec3(this->_z, this->_w, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec3 vec4::qqp() const { return vec3(this->_w, this->_w, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec3 vec4::ssq() const { return vec3(this->_x, this->_x, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec3 vec4::tsq() const { return vec3(this->_y, this->_x, this->_w); } // readonly
TRICIBLE_FORCEINLINE swizzle3<vec4, float, 1, 0, 3> vec4::tsq() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec3 vec4::psq() const { return vec3(this->_z, this->_x, this->_w); } // readonly
TRICIBLE_FORCEINLINE swizzle3<vec4, float, 2, 0, 3> vec4::psq() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec3 vec4::qsq() const { return vec3(this->_w, this->_x, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec3 vec4::stq() const { return vec3(this->_x, this->_y, this->_w); } // readonly
TRICIBLE_FORCEINLINE swizzle3<vec4, float, 0, 1, 3> vec4::stq() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec3 vec4::ttq() const { return vec3(this->_y, this->_y, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec3 vec4::ptq() const { return vec3(this->_z, this->_y, this->_w); } // readonly
TRICIBLE_FORCEINLINE swizzle3<vec4, float, 2, 1, 3> vec4::ptq() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec3 vec4::qtq() const { return vec3(this->_w, this->_y, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec3 vec4::spq() const { return vec3(this->_x, this->_z, this->_w); } // readonly
TRICIBLE_FORCEINLINE swizzle3<vec4, float, 0, 2, 3> vec4::spq() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec3 vec4::tpq() const { return vec3(this->_y, this->_z, this->_w); } // readonly
TRICIBLE_FORCEINLINE swizzle3<vec4, float, 1, 2, 3> vec4::tpq() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec3 vec4::ppq() const { return vec3(this->_z, this->_z, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec3 vec4::qpq() const { return vec3(this->_w, this->_z, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec3 vec4::sqq() const { return vec3(this->_x, this->_w, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec3 vec4::tqq() const { return vec3(this->_y, this->_w, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec3 vec4::pqq() const { return vec3(this->_z, this->_w, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec3 vec4::qqq() const { return vec3(this->_w, this->_w, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::ssss() const { return vec4(this->_x, this->_x, this->_x, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::tsss() const { return vec4(this->_y, this->_x, this->_x, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::psss() const { return vec4(this->_z, this->_x, this->_x, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::qsss() const { return vec4(this->_w, this->_x, this->_x, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::stss() const { return vec4(this->_x, this->_y, this->_x, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::ttss() const { return vec4(this->_y, this->_y, this->_x, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::ptss() const { return vec4(this->_z, this->_y, this->_x, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::qtss() const { return vec4(this->_w, this->_y, this->_x, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::spss() const { return vec4(this->_x, this->_z, this->_x, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::tpss() const { return vec4(this->_y, this->_z, this->_x, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::ppss() const { return vec4(this->_z, this->_z, this->_x, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::qpss() const { return vec4(this->_w, this->_z, this->_x, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::sqss() const { return vec4(this->_x, this->_w, this->_x, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::tqss() const { return vec4(this->_y, this->_w, this->_x, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::pqss() const { return vec4(this->_z, this->_w, this->_x, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::qqss() const { return vec4(this->_w, this->_w, this->_x, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::ssts() const { return vec4(this->_x, this->_x, this->_y, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::tsts() const { return vec4(this->_y, this->_x, this->_y, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::psts() const { return vec4(this->_z, this->_x, this->_y, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::qsts() const { return vec4(this->_w, this->_x, this->_y, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::stts() const { return vec4(this->_x, this->_y, this->_y, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::ttts() const { return vec4(this->_y, this->_y, this->_y, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::ptts() const { return vec4(this->_z, this->_y, this->_y, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::qtts() const { return vec4(this->_w, this->_y, this->_y, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::spts() const { return vec4(this->_x, this->_z, this->_y, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::tpts() const { return vec4(this->_y, this->_z, this->_y, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::ppts() const { return vec4(this->_z, this->_z, this->_y, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::qpts() const { return vec4(this->_w, this->_z, this->_y, this->_x); } // readonly
TRICIBLE_FORCEINLINE swizzle4<vec4, float, 3, 2, 1, 0> vec4::qpts() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec4 vec4::sqts() const { return vec4(this->_x, this->_w, this->_y, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::tqts() const { return vec4(this->_y, this->_w, this->_y, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::pqts() const { return vec4(this->_z, this->_w, this->_y, this->_x); } // readonly
TRICIBLE_FORCEINLINE swizzle4<vec4, float, 2, 3, 1, 0> vec4::pqts() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec4 vec4::qqts() const { return vec4(this->_w, this->_w, this->_y, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::ssps() const { return vec4(this->_x, this->_x, this->_z, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::tsps() const { return vec4(this->_y, this->_x, this->_z, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::psps() const { return vec4(this->_z, this->_x, this->_z, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::qsps() const { return vec4(this->_w, this->_x, this->_z, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::stps() const { return vec4(this->_x, this->_y, this->_z, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::ttps() const { return vec4(this->_y, this->_y, this->_z, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::ptps() const { return vec4(this->_z, this->_y, this->_z, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::qtps() const { return vec4(this->_w, this->_y, this->_z, this->_x); } // readonly
TRICIBLE_FORCEINLINE swizzle4<vec4, float, 3, 1, 2, 0> vec4::qtps() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec4 vec4::spps() const { return vec4(this->_x, this->_z, this->_z, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::tpps() const { return vec4(this->_y, this->_z, this->_z, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::ppps() const { return vec4(this->_z, this->_z, this->_z, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::qpps() const { return vec4(this->_w, this->_z, this->_z, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::sqps() const { return vec4(this->_x, this->_w, this->_z, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::tqps() const { return vec4(this->_y, this->_w, this->_z, this->_x); } // readonly
TRICIBLE_FORCEINLINE swizzle4<vec4, float, 1, 3, 2, 0> vec4::tqps() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec4 vec4::pqps() const { return vec4(this->_z, this->_w, this->_z, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::qqps() const { return vec4(this->_w, this->_w, this->_z, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::ssqs() const { return vec4(this->_x, this->_x, this->_w, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::tsqs() const { return vec4(this->_y, this->_x, this->_w, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::psqs() const { return vec4(this->_z, this->_x, this->_w, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::qsqs() const { return vec4(this->_w, this->_x, this->_w, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::stqs() const { return vec4(this->_x, this->_y, this->_w, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::ttqs() const { return vec4(this->_y, this->_y, this->_w, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::ptqs() const { return vec4(this->_z, this->_y, this->_w, this->_x); } // readonly
TRICIBLE_FORCEINLINE swizzle4<vec4, float, 2, 1, 3, 0> vec4::ptqs() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec4 vec4::qtqs() const { return vec4(this->_w, this->_y, this->_w, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::spqs() const { return vec4(this->_x, this->_z, this->_w, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::tpqs() const { return vec4(this->_y, this->_z, this->_w, this->_x); } // readonly
TRICIBLE_FORCEINLINE swizzle4<vec4, float, 1, 2, 3, 0> vec4::tpqs() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec4 vec4::ppqs() const { return vec4(this->_z, this->_z, this->_w, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::qpqs() const { return vec4(this->_w, this->_z, this->_w, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::sqqs() const { return vec4(this->_x, this->_w, this->_w, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::tqqs() const { return vec4(this->_y, this->_w, this->_w, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::pqqs() const { return vec4(this->_z, this->_w, this->_w, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::qqqs() const { return vec4(this->_w, this->_w, this->_w, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::ssst() const { return vec4(this->_x, this->_x, this->_x, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::tsst() const { return vec4(this->_y, this->_x, this->_x, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::psst() const { return vec4(this->_z, this->_x, this->_x, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::qsst() const { return vec4(this->_w, this->_x, this->_x, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::stst() const { return vec4(this->_x, this->_y, this->_x, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::ttst() const { return vec4(this->_y, this->_y, this->_x, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::ptst() const { return vec4(this->_z, this->_y, this->_x, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::qtst() const { return vec4(this->_w, this->_y, this->_x, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::spst() const { return vec4(this->_x, this->_z, this->_x, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::tpst() const { return vec4(this->_y, this->_z, this->_x, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::ppst() const { return vec4(this->_z, this->_z, this->_x, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::qpst() const { return vec4(this->_w, this->_z, this->_x, this->_y); } // readonly
TRICIBLE_FORCEINLINE swizzle4<vec4, float, 3, 2, 0, 1> vec4::qpst() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec4 vec4::sqst() const { return vec4(this->_x, this->_w, this->_x, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::tqst() const { return vec4(this->_y, this->_w, this->_x, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::pqst() const { return vec4(this->_z, this->_w, this->_x, this->_y); } // readonly
TRICIBLE_FORCEINLINE swizzle4<vec4, float, 2, 3, 0, 1> vec4::pqst() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec4 vec4::qqst() const { return vec4(this->_w, this->_w, this->_x, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::sstt() const { return vec4(this->_x, this->_x, this->_y, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::tstt() const { return vec4(this->_y, this->_x, this->_y, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::pstt() const { return vec4(this->_z, this->_x, this->_y, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::qstt() const { return vec4(this->_w, this->_x, this->_y, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::sttt() const { return vec4(this->_x, this->_y, this->_y, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::tttt() const { return vec4(this->_y, this->_y, this->_y, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::pttt() const { return vec4(this->_z, this->_y, this->_y, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::qttt() const { return vec4(this->_w, this->_y, this->_y, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::sptt() const { return vec4(this->_x, this->_z, this->_y, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::tptt() const { return vec4(this->_y, this->_z, this->_y, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::pptt() const { return vec4(this->_z, this->_z, this->_y, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::qptt() const { return vec4(this->_w, this->_z, this->_y, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::sqtt() const { return vec4(this->_x, this->_w, this->_y, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::tqtt() const { return vec4(this->_y, this->_w, this->_y, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::pqtt() const { return vec4(this->_z, this->_w, this->_y, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::qqtt() const { return vec4(this->_w, this->_w, this->_y, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::sspt() const { return vec4(this->_x, this->_x, this->_z, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::tspt() const { return vec4(this->_y, this->_x, this->_z, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::pspt() const { return vec4(this->_z, this->_x, this->_z, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::qspt() const { return vec4(this->_w, this->_x, this->_z, this->_y); } // readonly
TRICIBLE_FORCEINLINE swizzle4<vec4, float, 3, 0, 2, 1> vec4::qspt() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec4 vec4::stpt() const { return vec4(this->_x, this->_y, this->_z, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::ttpt() const { return vec4(this->_y, this->_y, this->_z, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::ptpt() const { return vec4(this->_z, this->_y, this->_z, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::qtpt() const { return vec4(this->_w, this->_y, this->_z, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::sppt() const { return vec4(this->_x, this->_z, this->_z, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::tppt() const { return vec4(this->_y, this->_z, this->_z, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::pppt() const { return vec4(this->_z, this->_z, this->_z, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::qppt() const { return vec4(this->_w, this->_z, this->_z, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::sqpt() const { return vec4(this->_x, this->_w, this->_z, this->_y); } // readonly
TRICIBLE_FORCEINLINE swizzle4<vec4, float, 0, 3, 2, 1> vec4::sqpt() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec4 vec4::tqpt() const { return vec4(this->_y, this->_w, this->_z, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::pqpt() const { return vec4(this->_z, this->_w, this->_z, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::qqpt() const { return vec4(this->_w, this->_w, this->_z, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::ssqt() const { return vec4(this->_x, this->_x, this->_w, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::tsqt() const { return vec4(this->_y, this->_x, this->_w, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::psqt() const { return vec4(this->_z, this->_x, this->_w, this->_y); } // readonly
TRICIBLE_FORCEINLINE swizzle4<vec4, float, 2, 0, 3, 1> vec4::psqt() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec4 vec4::qsqt() const { return vec4(this->_w, this->_x, this->_w, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::stqt() const { return vec4(this->_x, this->_y, this->_w, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::ttqt() const { return vec4(this->_y, this->_y, this->_w, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::ptqt() const { return vec4(this->_z, this->_y, this->_w, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::qtqt() const { return vec4(this->_w, this->_y, this->_w, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::spqt() const { return vec4(this->_x, this->_z, this->_w, this->_y); } // readonly
TRICIBLE_FORCEINLINE swizzle4<vec4, float, 0, 2, 3, 1> vec4::spqt() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec4 vec4::tpqt() const { return vec4(this->_y, this->_z, this->_w, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::ppqt() const { return vec4(this->_z, this->_z, this->_w, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::qpqt() const { return vec4(this->_w, this->_z, this->_w, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::sqqt() const { return vec4(this->_x, this->_w, this->_w, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::tqqt() const { return vec4(this->_y, this->_w, this->_w, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::pqqt() const { return vec4(this->_z, this->_w, this->_w, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::qqqt() const { return vec4(this->_w, this->_w, this->_w, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::sssp() const { return vec4(this->_x, this->_x, this->_x, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::tssp() const { return vec4(this->_y, this->_x, this->_x, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::pssp() const { return vec4(this->_z, this->_x, this->_x, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::qssp() const { return vec4(this->_w, this->_x, this->_x, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::stsp() const { return vec4(this->_x, this->_y, this->_x, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::ttsp() const { return vec4(this->_y, this->_y, this->_x, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::ptsp() const { return vec4(this->_z, this->_y, this->_x, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::qtsp() const { return vec4(this->_w, this->_y, this->_x, this->_z); } // readonly
TRICIBLE_FORCEINLINE swizzle4<vec4, float, 3, 1, 0, 2> vec4::qtsp() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec4 vec4::spsp() const { return vec4(this->_x, this->_z, this->_x, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::tpsp() const { return vec4(this->_y, this->_z, this->_x, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::ppsp() const { return vec4(this->_z, this->_z, this->_x, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::qpsp() const { return vec4(this->_w, this->_z, this->_x, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::sqsp() const { return vec4(this->_x, this->_w, this->_x, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::tqsp() const { return vec4(this->_y, this->_w, this->_x, this->_z); } // readonly
TRICIBLE_FORCEINLINE swizzle4<vec4, float, 1, 3, 0, 2> vec4::tqsp() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec4 vec4::pqsp() const { return vec4(this->_z, this->_w, this->_x, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::qqsp() const { return vec4(this->_w, this->_w, this->_x, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::sstp() const { return vec4(this->_x, this->_x, this->_y, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::tstp() const { return vec4(this->_y, this->_x, this->_y, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::pstp() const { return vec4(this->_z, this->_x, this->_y, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::qstp() const { return vec4(this->_w, this->_x, this->_y, this->_z); } // readonly
TRICIBLE_FORCEINLINE swizzle4<vec4, float, 3, 0, 1, 2> vec4::qstp() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec4 vec4::sttp() const { return vec4(this->_x, this->_y, this->_y, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::tttp() const { return vec4(this->_y, this->_y, this->_y, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::pttp() const { return vec4(this->_z, this->_y, this->_y, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::qttp() const { return vec4(this->_w, this->_y, this->_y, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::sptp() const { return vec4(this->_x, this->_z, this->_y, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::tptp() const { return vec4(this->_y, this->_z, this->_y, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::pptp() const { return vec4(this->_z, this->_z, this->_y, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::qptp() const { return vec4(this->_w, this->_z, this->_y, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::sqtp() const { return vec4(this->_x, this->_w, this->_y, this->_z); } // readonly
TRICIBLE_FORCEINLINE swizzle4<vec4, float, 0, 3, 1, 2> vec4::sqtp() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec4 vec4::tqtp() const { return vec4(this->_y, this->_w, this->_y, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::pqtp() const { return vec4(this->_z, this->_w, this->_y, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::qqtp() const { return vec4(this->_w, this->_w, this->_y, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::sspp() const { return vec4(this->_x, this->_x, this->_z, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::tspp() const { return vec4(this->_y, this->_x, this->_z, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::pspp() const { return vec4(this->_z, this->_x, this->_z, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::qspp() const { return vec4(this->_w, this->_x, this->_z, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::stpp() const { return vec4(this->_x, this->_y, this->_z, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::ttpp() const { return vec4(this->_y, this->_y, this->_z, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::ptpp() const { return vec4(this->_z, this->_y, this->_z, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::qtpp() const { return vec4(this->_w, this->_y, this->_z, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::sppp() const { return vec4(this->_x, this->_z, this->_z, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::tppp() const { return vec4(this->_y, this->_z, this->_z, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::pppp() const { return vec4(this->_z, this->_z, this->_z, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::qppp() const { return vec4(this->_w, this->_z, this->_z, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::sqpp() const { return vec4(this->_x, this->_w, this->_z, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::tqpp() const { return vec4(this->_y, this->_w, this->_z, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::pqpp() const { return vec4(this->_z, this->_w, this->_z, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::qqpp() const { return vec4(this->_w, this->_w, this->_z, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::ssqp() const { return vec4(this->_x, this->_x, this->_w, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::tsqp() const { return vec4(this->_y, this->_x, this->_w, this->_z); } // readonly
TRICIBLE_FORCEINLINE swizzle4<vec4, float, 1, 0, 3, 2> vec4::tsqp() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec4 vec4::psqp() const { return vec4(this->_z, this->_x, this->_w, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::qsqp() const { return vec4(this->_w, this->_x, this->_w, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::stqp() const { return vec4(this->_x, this->_y, this->_w, this->_z); } // readonly
TRICIBLE_FORCEINLINE swizzle4<vec4, float, 0, 1, 3, 2> vec4::stqp() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec4 vec4::ttqp() const { return vec4(this->_y, this->_y, this->_w, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::ptqp() const { return vec4(this->_z, this->_y, this->_w, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::qtqp() const { return vec4(this->_w, this->_y, this->_w, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::spqp() const { return vec4(this->_x, this->_z, this->_w, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::tpqp() const { return vec4(this->_y, this->_z, this->_w, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::ppqp() const { return vec4(this->_z, this->_z, this->_w, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::qpqp() const { return vec4(this->_w, this->_z, this->_w, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::sqqp() const { return vec4(this->_x, this->_w, this->_w, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::tqqp() const { return vec4(this->_y, this->_w, this->_w, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::pqqp() const { return vec4(this->_z, this->_w, this->_w, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::qqqp() const { return vec4(this->_w, this->_w, this->_w, this->_z); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::sssq() const { return vec4(this->_x, this->_x, this->_x, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::tssq() const { return vec4(this->_y, this->_x, this->_x, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::pssq() const { return vec4(this->_z, this->_x, this->_x, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::qssq() const { return vec4(this->_w, this->_x, this->_x, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::stsq() const { return vec4(this->_x, this->_y, this->_x, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::ttsq() const { return vec4(this->_y, this->_y, this->_x, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::ptsq() const { return vec4(this->_z, this->_y, this->_x, this->_w); } // readonly
TRICIBLE_FORCEINLINE swizzle4<vec4, float, 2, 1, 0, 3> vec4::ptsq() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec4 vec4::qtsq() const { return vec4(this->_w, this->_y, this->_x, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::spsq() const { return vec4(this->_x, this->_z, this->_x, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::tpsq() const { return vec4(this->_y, this->_z, this->_x, this->_w); } // readonly
TRICIBLE_FORCEINLINE swizzle4<vec4, float, 1, 2, 0, 3> vec4::tpsq() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec4 vec4::ppsq() const { return vec4(this->_z, this->_z, this->_x, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::qpsq() const { return vec4(this->_w, this->_z, this->_x, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::sqsq() const { return vec4(this->_x, this->_w, this->_x, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::tqsq() const { return vec4(this->_y, this->_w, this->_x, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::pqsq() const { return vec4(this->_z, this->_w, this->_x, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::qqsq() const { return vec4(this->_w, this->_w, this->_x, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::sstq() const { return vec4(this->_x, this->_x, this->_y, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::tstq() const { return vec4(this->_y, this->_x, this->_y, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::pstq() const { return vec4(this->_z, this->_x, this->_y, this->_w); } // readonly
TRICIBLE_FORCEINLINE swizzle4<vec4, float, 2, 0, 1, 3> vec4::pstq() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec4 vec4::qstq() const { return vec4(this->_w, this->_x, this->_y, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::sttq() const { return vec4(this->_x, this->_y, this->_y, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::tttq() const { return vec4(this->_y, this->_y, this->_y, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::pttq() const { return vec4(this->_z, this->_y, this->_y, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::qttq() const { return vec4(this->_w, this->_y, this->_y, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::sptq() const { return vec4(this->_x, this->_z, this->_y, this->_w); } // readonly
TRICIBLE_FORCEINLINE swizzle4<vec4, float, 0, 2, 1, 3> vec4::sptq() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec4 vec4::tptq() const { return vec4(this->_y, this->_z, this->_y, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::pptq() const { return vec4(this->_z, this->_z, this->_y, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::qptq() const { return vec4(this->_w, this->_z, this->_y, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::sqtq() const { return vec4(this->_x, this->_w, this->_y, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::tqtq() const { return vec4(this->_y, this->_w, this->_y, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::pqtq() const { return vec4(this->_z, this->_w, this->_y, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::qqtq() const { return vec4(this->_w, this->_w, this->_y, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::sspq() const { return vec4(this->_x, this->_x, this->_z, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::tspq() const { return vec4(this->_y, this->_x, this->_z, this->_w); } // readonly
TRICIBLE_FORCEINLINE swizzle4<vec4, float, 1, 0, 2, 3> vec4::tspq() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec4 vec4::pspq() const { return vec4(this->_z, this->_x, this->_z, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::qspq() const { return vec4(this->_w, this->_x, this->_z, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::stpq() const { return vec4(this->_x, this->_y, this->_z, this->_w); } // readonly
TRICIBLE_FORCEINLINE swizzle4<vec4, float, 0, 1, 2, 3> vec4::stpq() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec4 vec4::ttpq() const { return vec4(this->_y, this->_y, this->_z, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::ptpq() const { return vec4(this->_z, this->_y, this->_z, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::qtpq() const { return vec4(this->_w, this->_y, this->_z, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::sppq() const { return vec4(this->_x, this->_z, this->_z, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::tppq() const { return vec4(this->_y, this->_z, this->_z, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::pppq() const { return vec4(this->_z, this->_z, this->_z, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::qppq() const { return vec4(this->_w, this->_z, this->_z, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::sqpq() const { return vec4(this->_x, this->_w, this->_z, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::tqpq() const { return vec4(this->_y, this->_w, this->_z, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::pqpq() const { return vec4(this->_z, this->_w, this->_z, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::qqpq() const { return vec4(this->_w, this->_w, this->_z, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::ssqq() const { return vec4(this->_x, this->_x, this->_w, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::tsqq() const { return vec4(this->_y, this->_x, this->_w, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::psqq() const { return vec4(this->_z, this->_x, this->_w, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::qsqq() const { return vec4(this->_w, this->_x, this->_w, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::stqq() const { return vec4(this->_x, this->_y, this->_w, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::ttqq() const { return vec4(this->_y, this->_y, this->_w, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::ptqq() const { return vec4(this->_z, this->_y, this->_w, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::qtqq() const { return vec4(this->_w, this->_y, this->_w, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::spqq() const { return vec4(this->_x, this->_z, this->_w, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::tpqq() const { return vec4(this->_y, this->_z, this->_w, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::ppqq() const { return vec4(this->_z, this->_z, this->_w, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::qpqq() const { return vec4(this->_w, this->_z, this->_w, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::sqqq() const { return vec4(this->_x, this->_w, this->_w, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::tqqq() const { return vec4(this->_y, this->_w, this->_w, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::pqqq() const { return vec4(this->_z, this->_w, this->_w, this->_w); } // readonly
TRICIBLE_FORCEINLINE vec4 vec4::qqqq() const { return vec4(this->_w, this->_w, this->_w, this->_w); } // readonly
