#pragma once

#include "../Tools/Vector3.hpp"
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
			_position[0] = 0.f;
			NearClip = 0.1f;
			FarClip = 10000.f;
		}

		void GetRay(int x_, int y_, Vector3& vec)
		{
			// TODO Replace 80 by FOV Calculation
			vec._x = focale;
			vec._y = -(y_ / 80.f);
			vec._z = x_ / 80.f;

			// rotate
			vec = pitchMat * (yawMat * vec);
			//vec = vec + this->position;
		}

		void MoveForward()
		{
			vec3 vecForward = vec3(0., 0., 1.);//yawMat* (pitchMat * vec3(0., 0., 1.));// TODO
			//Point3 vecForward(lookAt - position);

			_position += vecForward * MOVEMENTS_SPEED;
		}

		void MoveBackward()
		{
			vec3 vecBackward = vec3(0., 0., -1.);//yawMat* (pitchMat * vec3(0., 0., -1.)); // TODO

			_position += vecBackward * MOVEMENTS_SPEED;
		}
		void MoveRight()
		{
			vec3 vecRight = vec3(1., 0., 0.);//yawMat* (pitchMat * vec3(1., 0., 0.));

			_position += vecRight * MOVEMENTS_SPEED;
		}
		void MoveLeft()
		{
			vec3 vecLeft = vec3(1., 0., 0.);//yawMat* (pitchMat * vec3(-1., 0., 0.));

			_position += vecLeft * MOVEMENTS_SPEED;
		}
	};
}