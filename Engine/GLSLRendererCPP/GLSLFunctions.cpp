#define GLAD_GL_IMPLEMENTATION
#include <glad/gl.h>
#include "Swizzle.hpp"
#include "GLSLFunctions.hpp"


TRICIBLE_FORCEINLINE vec3 abs(const vec3& a)
{
	return vec3(::abs(a.X_), ::abs(a.Y_), ::abs(a.Z_));
}


