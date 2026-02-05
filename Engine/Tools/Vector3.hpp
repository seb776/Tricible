#pragma once

#include <sstream>
#include "Macros.hpp"
#include <math.h>

namespace Tricible
{
	class Vector3
	{
	public:
		float _x;
		float _y;
		float _z;
	public:
		explicit Vector3(float x, float y, float z)
		{
			_x = x;
			_y = y;
			_z = z;
		}
		Vector3() :
			Vector3(0.0f, 0.0f, 0.0f)
		{
		}

		explicit Vector3(float x) :
			Vector3(x, x, x)
		{

		}

		TRICIBLE_FORCEINLINE float Dot(const Vector3& rhs) const
		{
			return (_x * rhs._x) + (_y * rhs._y) + (_z * rhs._z);
		}

		TRICIBLE_FORCEINLINE float LengthSquare() const
		{
			return this->Dot(*this);
		}

		TRICIBLE_FORCEINLINE float Length() const
		{
			float l = this->LengthSquare();
			return sqrtf(l);
		}

		TRICIBLE_FORCEINLINE Vector3 Normalize() const
		{
			return Normalize(this->Length());
		}

		TRICIBLE_FORCEINLINE Vector3 Normalize(float length) const
		{
			Vector3 p = *this;
			const float revLength = 1.f / length;
			p._x *= revLength;
			p._y *= revLength;
			p._z *= revLength;
			return p;
		}

		TRICIBLE_FORCEINLINE void Normalize()
		{
			const float revLength = 1.f / this->Length();
			_x *= revLength;
			_y *= revLength;
			_z *= revLength;
		}

		TRICIBLE_FORCEINLINE Vector3	Cross(const Vector3& rhs) const
		{
			return Vector3((_y * rhs._z) - (_z * rhs._y), (_z * rhs._x) - (_x * rhs._z), (_x * rhs._y) - (_y * rhs._x));
		}

		TRICIBLE_FORCEINLINE Vector3 Reverse() const
		{
			return -(*this);
		}

		TRICIBLE_FORCEINLINE Vector3 operator+(const Vector3& rhs) const
		{
			return Vector3(_x + rhs._x, _y + rhs._y, _z + rhs._z);
		}

		TRICIBLE_FORCEINLINE Vector3 operator-(const Vector3& rhs) const
		{
			return Vector3(_x - rhs._x, _y - rhs._y, _z - rhs._z);
		}

		TRICIBLE_FORCEINLINE Vector3 operator*(const Vector3& rhs) const
		{
			return Vector3(_x * rhs._x, _y * rhs._y, _z * rhs._z);
		}

		TRICIBLE_FORCEINLINE Vector3 operator*(const float rhs) const
		{
			return Vector3(_x * rhs, _y * rhs, _z * rhs);
		}

		TRICIBLE_FORCEINLINE Vector3 operator/(const float rhs) const
		{
			return Vector3(_x / rhs, _y / rhs, _z / rhs);
		}

		TRICIBLE_FORCEINLINE void operator+=(const Vector3& rhs)
		{
			this->_x += rhs._x;
			this->_y += rhs._y;
			this->_z += rhs._z;
		}

		TRICIBLE_FORCEINLINE void operator-=(const Vector3& rhs)
		{
			this->_x -= rhs._x;
			this->_y -= rhs._y;
			this->_z -= rhs._z;
		}
		TRICIBLE_FORCEINLINE Vector3 operator-() const
		{
			return Vector3(-this->_x, -this->_y, -this->_z);
		}

		TRICIBLE_FORCEINLINE std::string ToString() const
		{
			std::stringstream ss;
			ss << "(" << _x << ", " << _y << ", " << _z << ")";
			return ss.str();
		}

		static const Vector3 x;
		static const Vector3 y;
		static const Vector3 z;
		static const Vector3 forward;
		static const Vector3 backward;
		static const Vector3 up;
		static const Vector3 down;
		static const Vector3 left;
		static const Vector3 right;
	};
}


