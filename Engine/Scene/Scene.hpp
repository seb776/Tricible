#pragma once

#include <vector>
#include "AObject.hpp"

namespace Tricible
{
	class Scene : public AObject, public AIntersectable
	{
		std::vector<AObject *> Objects;
	};
}
