#pragma once

#include "../Tools/Point3.hpp"
#include "../Tools/3x3Matrix.hpp"

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
			focale = 10.0f;// 40.f / tanf(45.f / 2.f);
			_position._x = 0.f;
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

			_position += vecForward * MOVEMENTS_SPEED;
		}

		void MoveBackward()
		{
			Point3 vecBackward = yawMat * (pitchMat *  Point3::backward);

			vecBackward.Normalize();

			_position += vecBackward * MOVEMENTS_SPEED;
		}
		void MoveRight()
		{
			Point3 vecRight = yawMat * (pitchMat *  Point3::right);

			vecRight.Normalize();

			_position += vecRight * MOVEMENTS_SPEED;
		}
		void MoveLeft()
		{
			Point3 vecLeft = yawMat * (pitchMat *  Point3::left);

			vecLeft.Normalize();

			_position += vecLeft * MOVEMENTS_SPEED;
		}
	};
}