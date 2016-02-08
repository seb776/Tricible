#pragma once

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

		float Dot(const Point3& rhs) const
		{
			return (_x * rhs._x) + (_y * rhs._y) + (_z * rhs._z);
		}

		float LengthSquare() const
		{
			return this->Dot(*this);
		}

		float Length() const
		{
			float l = this->LengthSquare();
			return sqrtf(l); // TODO courte_p : Renvoyer une valeur absolue ? ou laisser comme ça ?
		}

		void Normalize()
		{
			float length = this->Length();
			_x /= length;
			_y /= length;
			_z /= length;
		}

		Point3	Cross(const Point3& rhs) const
		{
			return Point3((_y * rhs._z) - (_z * rhs._y), (_z * rhs._x) - (_x * rhs._z), (_x * rhs._y) - (_y - rhs._x));
		}

		Point3 Reverse() const
		{
			return Point3(-_x, -_y, -_z);
		}

		Point3 operator+(const Point3& rhs) const
		{
			return Point3(_x + rhs._x, _y + rhs._y, _z + rhs._z);
		}

		Point3 operator-(const Point3& rhs) const
		{
			return Point3(_x - rhs._x, _y - rhs._y, _z - rhs._z);
		}

		Point3 operator*(const Point3& rhs) const
		{
			return Point3(_x * rhs._x, _y * rhs._y, _z * rhs._z);
		}

		Point3 operator*(const float rhs) const
		{
			return Point3(_x * rhs, _y * rhs, _z * rhs);
		}

		Point3 operator/(const float rhs) const 
		{
			return Point3(_x / rhs, _y / rhs, _z / rhs);
		}

		void operator+=(const Point3& rhs)
		{
			this->_x += rhs._x;
			this->_y += rhs._y;
			this->_z += rhs._z;
		}

		void operator-=(const Point3& rhs)
		{
			this->_x -= rhs._x;
			this->_y -= rhs._y;
			this->_z -= rhs._z;
		}
	};
}