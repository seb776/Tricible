#pragma once

#include "Point3.hpp"
#include "3x3Matrix.hpp"

#define MOVEMENTS_SPEED 1.f

namespace Tricible
{
	class Camera : public AObject
	{
	public:
		float pitch;
		float yaw;
		float roll;
		Matrix3x3 pitchMat;
		Matrix3x3 yawMat;

		float NearClip;
		float FarClip;
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
			NearClip = 0.1f;
			FarClip = 10000.f;
		}

		void GetRay(int x_, int y_, Point3& vec)
		{
			vec._x = focale;
			vec._y = -(y_ / 80.f);
			vec._z = x_ / 80.f;

			// rotate
			vec = pitchMat * (yawMat * vec);
			//vec = vec + this->position;
		}

		void MoveForward()
		{
			Point3 vecForward = yawMat * (pitchMat *  Point3::forward);
			//Point3 vecForward(lookAt - position);

			vecForward.Normalize();

			position += vecForward * MOVEMENTS_SPEED;
		}

		void MoveBackward()
		{
			Point3 vecBackward = yawMat * (pitchMat *  Point3::backward);

			vecBackward.Normalize();

			position += vecBackward * MOVEMENTS_SPEED;
		}
	};
}