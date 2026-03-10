#include <sstream>
#include "GLSLFunctions.hpp"
#include "vec2.hpp"

vec2::vec2() :
	vec2(0.0f)
{
}
vec2::vec2(const vec2& rhs)
{
	*this = rhs;
}
vec2::vec2(float x_, float y_)
{
	_x = x_;
	_y = y_;
}
vec2::vec2(float x_) :
	vec2(x_, x_)
{
}


TRICIBLE_FORCEINLINE vec2 vec2::operator-() const
{
	return vec2(-this->_x, -this->_y);
}

TRICIBLE_FORCEINLINE vec2 vec2::operator+(const vec2& rhs) const
{
	return vec2(_x + rhs._x, _y + rhs._y);
}

TRICIBLE_FORCEINLINE vec2 vec2::operator-(const vec2& rhs) const
{
	return vec2(_x - rhs._x, _y - rhs._y);
}

TRICIBLE_FORCEINLINE vec2 vec2::operator*(const vec2& rhs) const
{
	return vec2(_x * rhs._x, _y * rhs._y);
}

TRICIBLE_FORCEINLINE vec2 vec2::operator*(const float rhs) const
{
	return vec2(_x * rhs, _y * rhs);
}

TRICIBLE_FORCEINLINE vec2 vec2::operator/(const vec2& rhs) const
{
	return vec2(_x / rhs._x, _y / rhs._y);
}
TRICIBLE_FORCEINLINE vec2 vec2::operator/(const float rhs) const
{
	return vec2(_x / rhs, _y / rhs);
}

TRICIBLE_FORCEINLINE vec2 vec2::operator=(const vec2& rhs)
{
	this->_x = rhs._x;
	this->_y = rhs._y;
	return *this;
}

TRICIBLE_FORCEINLINE vec2 vec2::operator+=(const vec2& rhs)
{
	this->_x += rhs._x;
	this->_y += rhs._y;
	return *this;
}

TRICIBLE_FORCEINLINE vec2 vec2::operator-=(const vec2& rhs)
{
	this->_x -= rhs._x;
	this->_y -= rhs._y;
	return *this;
}

TRICIBLE_FORCEINLINE vec2 vec2::operator*=(const vec2& rhs)
{
	this->_x *= rhs._x;
	this->_y *= rhs._y;
	return *this;
}
TRICIBLE_FORCEINLINE vec2 vec2::operator/=(const vec2& rhs)
{
	this->_x /= rhs._x;
	this->_y /= rhs._y;
	return *this;
}
TRICIBLE_FORCEINLINE vec2 vec2::operator*=(const float rhs)
{
	this->_x *= rhs;
	this->_y *= rhs;
	return *this;
}
TRICIBLE_FORCEINLINE vec2 vec2::operator/=(const float rhs)
{
	this->_x /= rhs;
	this->_y /= rhs;
	return *this;
}


TRICIBLE_FORCEINLINE std::string vec2::ToString() const
{
	std::stringstream ss;
	ss << "(" << _x << ", " << _y << ")";
	return ss.str();
}

TRICIBLE_FORCEINLINE float vec2::x() const { return this->_x; } // readonly
TRICIBLE_FORCEINLINE swizzle1<vec2, float, 0> vec2::x() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE float vec2::y() const { return this->_y; } // readonly
TRICIBLE_FORCEINLINE swizzle1<vec2, float, 1> vec2::y() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec2 vec2::xx() const { return vec2(this->_x, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec2 vec2::yx() const { return vec2(this->_y, this->_x); } // readonly
TRICIBLE_FORCEINLINE swizzle2<vec2, float, 1, 0> vec2::yx() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec2 vec2::xy() const { return vec2(this->_x, this->_y); } // readonly
TRICIBLE_FORCEINLINE swizzle2<vec2, float, 0, 1> vec2::xy() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec2 vec2::yy() const { return vec2(this->_y, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec3 vec2::xxx() const { return vec3(this->_x, this->_x, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec3 vec2::yxx() const { return vec3(this->_y, this->_x, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec3 vec2::xyx() const { return vec3(this->_x, this->_y, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec3 vec2::yyx() const { return vec3(this->_y, this->_y, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec3 vec2::xxy() const { return vec3(this->_x, this->_x, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec3 vec2::yxy() const { return vec3(this->_y, this->_x, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec3 vec2::xyy() const { return vec3(this->_x, this->_y, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec3 vec2::yyy() const { return vec3(this->_y, this->_y, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec2::xxxx() const { return vec4(this->_x, this->_x, this->_x, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec2::yxxx() const { return vec4(this->_y, this->_x, this->_x, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec2::xyxx() const { return vec4(this->_x, this->_y, this->_x, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec2::yyxx() const { return vec4(this->_y, this->_y, this->_x, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec2::xxyx() const { return vec4(this->_x, this->_x, this->_y, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec2::yxyx() const { return vec4(this->_y, this->_x, this->_y, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec2::xyyx() const { return vec4(this->_x, this->_y, this->_y, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec2::yyyx() const { return vec4(this->_y, this->_y, this->_y, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec2::xxxy() const { return vec4(this->_x, this->_x, this->_x, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec2::yxxy() const { return vec4(this->_y, this->_x, this->_x, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec2::xyxy() const { return vec4(this->_x, this->_y, this->_x, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec2::yyxy() const { return vec4(this->_y, this->_y, this->_x, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec2::xxyy() const { return vec4(this->_x, this->_x, this->_y, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec2::yxyy() const { return vec4(this->_y, this->_x, this->_y, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec2::xyyy() const { return vec4(this->_x, this->_y, this->_y, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec2::yyyy() const { return vec4(this->_y, this->_y, this->_y, this->_y); } // readonly

TRICIBLE_FORCEINLINE float vec2::r() const { return this->_x; } // readonly
TRICIBLE_FORCEINLINE swizzle1<vec2, float, 0> vec2::r() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE float vec2::g() const { return this->_y; } // readonly
TRICIBLE_FORCEINLINE swizzle1<vec2, float, 1> vec2::g() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec2 vec2::rr() const { return vec2(this->_x, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec2 vec2::gr() const { return vec2(this->_y, this->_x); } // readonly
TRICIBLE_FORCEINLINE swizzle2<vec2, float, 1, 0> vec2::gr() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec2 vec2::rg() const { return vec2(this->_x, this->_y); } // readonly
TRICIBLE_FORCEINLINE swizzle2<vec2, float, 0, 1> vec2::rg() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec2 vec2::gg() const { return vec2(this->_y, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec3 vec2::rrr() const { return vec3(this->_x, this->_x, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec3 vec2::grr() const { return vec3(this->_y, this->_x, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec3 vec2::rgr() const { return vec3(this->_x, this->_y, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec3 vec2::ggr() const { return vec3(this->_y, this->_y, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec3 vec2::rrg() const { return vec3(this->_x, this->_x, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec3 vec2::grg() const { return vec3(this->_y, this->_x, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec3 vec2::rgg() const { return vec3(this->_x, this->_y, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec3 vec2::ggg() const { return vec3(this->_y, this->_y, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec2::rrrr() const { return vec4(this->_x, this->_x, this->_x, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec2::grrr() const { return vec4(this->_y, this->_x, this->_x, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec2::rgrr() const { return vec4(this->_x, this->_y, this->_x, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec2::ggrr() const { return vec4(this->_y, this->_y, this->_x, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec2::rrgr() const { return vec4(this->_x, this->_x, this->_y, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec2::grgr() const { return vec4(this->_y, this->_x, this->_y, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec2::rggr() const { return vec4(this->_x, this->_y, this->_y, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec2::gggr() const { return vec4(this->_y, this->_y, this->_y, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec2::rrrg() const { return vec4(this->_x, this->_x, this->_x, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec2::grrg() const { return vec4(this->_y, this->_x, this->_x, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec2::rgrg() const { return vec4(this->_x, this->_y, this->_x, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec2::ggrg() const { return vec4(this->_y, this->_y, this->_x, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec2::rrgg() const { return vec4(this->_x, this->_x, this->_y, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec2::grgg() const { return vec4(this->_y, this->_x, this->_y, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec2::rggg() const { return vec4(this->_x, this->_y, this->_y, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec2::gggg() const { return vec4(this->_y, this->_y, this->_y, this->_y); } // readonly

TRICIBLE_FORCEINLINE float vec2::s() const { return this->_x; } // readonly
TRICIBLE_FORCEINLINE swizzle1<vec2, float, 0> vec2::s() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE float vec2::t() const { return this->_y; } // readonly
TRICIBLE_FORCEINLINE swizzle1<vec2, float, 1> vec2::t() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec2 vec2::ss() const { return vec2(this->_x, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec2 vec2::ts() const { return vec2(this->_y, this->_x); } // readonly
TRICIBLE_FORCEINLINE swizzle2<vec2, float, 1, 0> vec2::ts() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec2 vec2::st() const { return vec2(this->_x, this->_y); } // readonly
TRICIBLE_FORCEINLINE swizzle2<vec2, float, 0, 1> vec2::st() { return { *this }; } // Assignable
TRICIBLE_FORCEINLINE vec2 vec2::tt() const { return vec2(this->_y, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec3 vec2::sss() const { return vec3(this->_x, this->_x, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec3 vec2::tss() const { return vec3(this->_y, this->_x, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec3 vec2::sts() const { return vec3(this->_x, this->_y, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec3 vec2::tts() const { return vec3(this->_y, this->_y, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec3 vec2::sst() const { return vec3(this->_x, this->_x, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec3 vec2::tst() const { return vec3(this->_y, this->_x, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec3 vec2::stt() const { return vec3(this->_x, this->_y, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec3 vec2::ttt() const { return vec3(this->_y, this->_y, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec2::ssss() const { return vec4(this->_x, this->_x, this->_x, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec2::tsss() const { return vec4(this->_y, this->_x, this->_x, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec2::stss() const { return vec4(this->_x, this->_y, this->_x, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec2::ttss() const { return vec4(this->_y, this->_y, this->_x, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec2::ssts() const { return vec4(this->_x, this->_x, this->_y, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec2::tsts() const { return vec4(this->_y, this->_x, this->_y, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec2::stts() const { return vec4(this->_x, this->_y, this->_y, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec2::ttts() const { return vec4(this->_y, this->_y, this->_y, this->_x); } // readonly
TRICIBLE_FORCEINLINE vec4 vec2::ssst() const { return vec4(this->_x, this->_x, this->_x, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec2::tsst() const { return vec4(this->_y, this->_x, this->_x, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec2::stst() const { return vec4(this->_x, this->_y, this->_x, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec2::ttst() const { return vec4(this->_y, this->_y, this->_x, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec2::sstt() const { return vec4(this->_x, this->_x, this->_y, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec2::tstt() const { return vec4(this->_y, this->_x, this->_y, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec2::sttt() const { return vec4(this->_x, this->_y, this->_y, this->_y); } // readonly
TRICIBLE_FORCEINLINE vec4 vec2::tttt() const { return vec4(this->_y, this->_y, this->_y, this->_y); } // readonly