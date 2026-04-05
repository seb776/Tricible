#pragma once

#include "../GLSLRendererCPP/vec3.hpp"
#include "../GLSLRendererCPP/mat3.hpp"
#include "../GLSLRendererCPP/SwizzleProxies.hpp"

#define MOVEMENTS_SPEED 0.001f

namespace Tricible
{
	class Camera : public AObject
	{
	public:
		float pitch;
		float yaw;
		float roll;
		mat3 pitchMat;
		mat3 yawMat;

		float NearClip;
		float FarClip;
		float focale;
	public:
		void SetPitch(float pitch_)
		{
			pitch = pitch_;
			pitchMat.SetRotationZ(pitch);
		}

		void SetYaw(float yaw_)
		{
			yaw = yaw_;
			yawMat.SetRotationY(yaw);
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

		void GetRay(int x_, int y_, vec3& vec)
		{
			// TODO Replace 80 by FOV Calculation
			vec.x() = focale;
			vec.y() = -(y_ / 80.f);
			vec.z() = x_ / 80.f;

			// rotate
			vec = pitchMat * (yawMat * vec);
			//vec = vec + this->position;
		}

		void MoveForward()
		{
			vec3 vecForward = vec3(
				cos(pitch) * sin(yaw),   // X
				-sin(pitch),               // Y (up)
				cos(pitch) * cos(yaw)    // Z
			);
			_position += vecForward * MOVEMENTS_SPEED;
		}
		void MoveBackward()
		{
			vec3 vecForward = vec3(
				cos(pitch) * sin(yaw),
				-sin(pitch),
				cos(pitch) * cos(yaw)
			);
			_position -= vecForward * MOVEMENTS_SPEED;
		}
		void MoveRight()
		{
			vec3 vecRight = yawMat * vec3(1., 0., 0.);  // only yaw affects horizontal strafe
			_position += vecRight * MOVEMENTS_SPEED;
		}
		void MoveLeft()
		{
			vec3 vecLeft = yawMat * vec3(-1., 0., 0.);
			_position += vecLeft * MOVEMENTS_SPEED;
		}
	};
}