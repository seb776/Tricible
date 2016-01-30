#pragma once

#include "Point3.hpp"
#include "3x3Matrix.hpp"

namespace Tricible
{
	class Camera
	{
	public:
		float pitch;
		float yaw;
		float roll;
		Matrix3x3 pitchMat;
		Matrix3x3 yawMat;
		Point3 position;
		float focale;
	public:
		void SetPitch(float pitch_)
		{
			pitch = pitch_;
			pitchMat.SetRotationY(pitch);
		}

		void SetYaw(float yaw_)
		{
			yaw = yaw_;
			yawMat.SetRotationZ(yaw);
		}
		Camera()
		{
			pitch = yaw = roll = 0.f;
			SetPitch(0.f);
			SetYaw(0.f);
			focale = 40.f / tanf(45.f / 2.f);
			position._x = 0.f;
		}
		void GetRay(int x_, int y_, Point3& vec)
		{
			vec._x = focale;
			vec._y = x_ / 80.f;
			vec._z = -(y_ / 80.f);

			// rotate
			vec = yawMat * (pitchMat * vec);
			//vec = vec + this->position;
		}
	};
}