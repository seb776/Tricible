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
		TRICIBLE_FORCEINLINE const Point3& getPosition() const
		{
			return this->position;
		}
		Point3 lookAt; // TODO courte_p -> lookAt ne prends pas en compte les rotations yaw/pitch
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
			lookAt._x = 1.0f; // TODO courte_p -> lookAt ne prends pas en compte les rotations yaw/pitch
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

		void MoveForward()
		{
			Point3 vecForward = yawMat * (pitchMat *  Point3::forward);
			//Point3 vecForward(lookAt - position);

			vecForward.Normalize();

			position += vecForward * MOVEMENTS_SPEED;
		}

		void MoveBackward()
		{
			Point3 vecForward(lookAt - position);

			vecForward.Normalize();

			position -= vecForward * MOVEMENTS_SPEED;
			lookAt -= vecForward * MOVEMENTS_SPEED;
			// TODO courte_p -> lookAt ne prends pas en compte les rotations yaw/pitch
		}
	};
}