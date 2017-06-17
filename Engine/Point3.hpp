#pragma once

#include "Macros.hpp"

namespace Tricible
{
	class Point3
	{
	public:
		float _x;
		float _y;
		float _z;
	public:
		explicit Point3(float x, float y, float z)
		{
			_x = x;
			_y = y;
			_z = z;
		}
		Point3()
		{
			_x = _y = _z = 0.f;
		}

		TRICIBLE_FORCEINLINE float Dot(const Point3& rhs) const
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
			return sqrtf(l); // TODO courte_p : Renvoyer une valeur absolue ? ou laisser comme ça ? z0rg: c'est déjà une valeur absolue
		}

		TRICIBLE_FORCEINLINE void Normalize()
		{
			const float revLength = 1.f / this->Length();
			_x *= revLength; // z0rg Multiplication is faster than division
			_y *= revLength;
			_z *= revLength;
		}

		TRICIBLE_FORCEINLINE Point3	Cross(const Point3& rhs) const
		{
			return Point3((_y * rhs._z) - (_z * rhs._y), (_z * rhs._x) - (_x * rhs._z), (_x * rhs._y) - (_y - rhs._x));
		}

		TRICIBLE_FORCEINLINE Point3 Reverse() const
		{
			return -(*this);
		}

		TRICIBLE_FORCEINLINE Point3 operator+(const Point3& rhs) const
		{
			return Point3(_x + rhs._x, _y + rhs._y, _z + rhs._z);
		}

		TRICIBLE_FORCEINLINE Point3 operator-(const Point3& rhs) const
		{
			return Point3(_x - rhs._x, _y - rhs._y, _z - rhs._z);
		}

		TRICIBLE_FORCEINLINE Point3 operator*(const Point3& rhs) const
		{
			return Point3(_x * rhs._x, _y * rhs._y, _z * rhs._z);
		}

		TRICIBLE_FORCEINLINE Point3 operator*(const float rhs) const
		{
			return Point3(_x * rhs, _y * rhs, _z * rhs);
		}

		TRICIBLE_FORCEINLINE Point3 operator/(const float rhs) const
		{
			return Point3(_x / rhs, _y / rhs, _z / rhs);
		}

		TRICIBLE_FORCEINLINE void operator+=(const Point3& rhs)
		{
			this->_x += rhs._x;
			this->_y += rhs._y;
			this->_z += rhs._z;
		}

		TRICIBLE_FORCEINLINE void operator-=(const Point3& rhs)
		{
			this->_x -= rhs._x;
			this->_y -= rhs._y;
			this->_z -= rhs._z;
		}
		TRICIBLE_FORCEINLINE Point3 operator-() const
		{
			return Point3(-this->_x, -this->_y, -this->_z);
		}

		static const Point3 x;
		static const Point3 y;
		static const Point3 z;
		static const Point3 forward;
		static const Point3 backward;
		static const Point3 up;
		static const Point3 down;
		static const Point3 left;
		static const Point3 right;
	};
}

const Tricible::Point3 Tricible::Point3::x = Point3(1.0f, 0.0f, 0.0f);
const Tricible::Point3 Tricible::Point3::y = Point3(0.0f, 1.0f, 0.0f);
const Tricible::Point3 Tricible::Point3::z = Point3(0.0f, 0.0f, 1.0f);
const Tricible::Point3 Tricible::Point3::forward = Tricible::Point3::x;
const Tricible::Point3 Tricible::Point3::backward = -Tricible::Point3::x;
const Tricible::Point3 Tricible::Point3::up = Tricible::Point3::y;
const Tricible::Point3 Tricible::Point3::down = -Tricible::Point3::y;
const Tricible::Point3 Tricible::Point3::right = Tricible::Point3::z;
const Tricible::Point3 Tricible::Point3::left = -Tricible::Point3::z;
