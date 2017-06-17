#pragma once

#include "Point3.hpp"
#include <math.h>

namespace Tricible
{
	class Matrix3x3
	{
	public:
		Point3 matrix[3];
		Matrix3x3()
		{
			InitToIdentity();
		}
		void InitToIdentity()
		{
			matrix[0] = Point3::x;
			matrix[1] = Point3::y;
			matrix[2] = Point3::z;
		}
		void InitToZero()
		{
			for (int i = 0; i < 3; ++i)
				matrix[i] = Point3();
		}

		Point3 operator*(const Point3& rhs) const
		{
			float res[3];
			for (int i = 0; i < 3; ++i)
				res[i] = matrix[i].Dot(rhs);
			return Point3(res[0], res[1], res[2]);
		}

		// https://fr.wikipedia.org/wiki/Matrice_de_rotation
		void SetRotationX(float roll)
		{
			InitToZero();
			matrix[0]._x = 1.f;
			matrix[1]._y = matrix[2]._z = cosf(roll);
			matrix[2]._y = matrix[1]._z = sinf(roll);
			matrix[1]._z *= -1.f;
		}
		void SetRotationY(float pitch)
		{
			InitToZero();
			matrix[0]._x = matrix[2]._z = cosf(pitch);
			matrix[1]._y = 1.f;
			matrix[2]._x = matrix[0]._z = sinf(pitch);
			matrix[2]._x *= -1.f;
		}

		void SetRotationZ(float yaw)
		{
			InitToZero();
			matrix[0]._x = matrix[1]._y = cosf(yaw);
			matrix[1]._x = matrix[0]._y = sinf(yaw);
			matrix[2]._z = 1.f;
			matrix[0]._y *= -1.f;
		}
	};
}