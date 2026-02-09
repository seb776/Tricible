#pragma once
#include "../Tools/Vector3.hpp"
#include "../Tools/Tools.hpp"

namespace Tricible
{
	/// <summary>
	/// Aligned-Axis-Bounding-Box
	/// </summary>
	class AABB
	{
	private:
		Vector3 _min;
		Vector3 _max;
	public:
		AABB() :
			_min(), _max()
		{
		}

		Vector3 Center() const 
		{
			return (_min + _max) / 2.0;
		}

		void Grow(const Vector3& point)
		{
			_min._x = min(_min._x, point._x);
			_min._y = min(_min._y, point._y);
			_min._z = min(_min._z, point._z);

			_max._x = min(_max._x, point._x);
			_max._y = min(_max._y, point._y);
			_max._z = min(_max._z, point._z);

		}

		float Volume() const 
		{
			auto &sides = Vector3::abs(_max - _min);
			return sides._x * sides._y * sides._z;
		}
	};
}