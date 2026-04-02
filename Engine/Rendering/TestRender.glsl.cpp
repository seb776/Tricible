#ifndef OPENGL_SHADER_CODE
#include "../GLSLRendererCPP/GLSLFunctions.hpp"
#include "../GLSLRendererCPP/VariableArray.hpp"
#include "../GLSLRendererCPP/Swizzle.hpp"
#endif // !OPENGL_SHADER_CODE

struct Triangle
{
	uint A;
	uint B;
	uint C;
	// TODO normals + attributes
};

#ifdef OPENGL_SHADER_CODE
out vec4 FragColor;
//vec3 vertices[];

layout(std430) readonly buffer Objects
{
	struct Object
	{
		uint MaterialId;
		Triangle Triangles[];
	};
}

layout(std430) readonly buffer Vertices
{
	vec3 vertices[];
}

#else


struct Object
{
	unsigned int MaterialId;
	VariableArray<Triangle> Triangles;
};

VariableArray<Object> Objects;
void main(vec4& FragColor, const vec4& gl_FragCoord);
int mainShaderCall(const vec4& gl_FragCoord)
{
	vec4 fragColor = vec4(0.);
	main(fragColor, gl_FragCoord);
	return fragColor.ToInt();
}
#endif


#ifdef OPENGL_SHADER_CODE
bool intersectTriangle(Triangle triangle, vec3 origin, vec3 direction, out float distance)
#else
bool intersectTriangle(const Triangle& triangle, vec3 origin, vec3 direction, float& distance)
#endif
{
	// TODO
	distance = 42.0f;
	return true;
}
#ifdef OPENGL_SHADER_CODE
#define UNIFORM(TYPE, NAME) uniform TYPE NAME;
#else
#include <map>
std::map<std::string, void*> UniformsMap;
#define UNIFORM(TYPE, NAME) TYPE NAME; auto dummy##NAME = UniformsMap.insert_or_assign(#NAME, (void*)&NAME);
#endif

UNIFORM(float, cameraPitch);

#ifdef OPENGL_SHADER_CODE
void main()
#else
void main(vec4& FragColor, const vec4& gl_FragCoord)
#endif
{
	vec2 uv = gl_FragCoord.XY_; // TODO center and normalize coordinates

	// TODO get coordinates
	// TODO move and rotate camera
	vec3 ro = vec3(0.);
	vec3 rd = vec3(0.);

	const float FLOAT_MAX = 1000000.0f; // TODO proper FLTMAX
	float nearestDist = FLOAT_MAX;
	Object nearestObject;
	Triangle nearestTriangle;
	for (int i = 0; i < Objects.length(); ++i)
	{
		for (int j = 0; j < Objects[i].Triangles.length(); ++j)
		{
			float curDistance = 0.0f;
			if (intersectTriangle(Objects[i].Triangles[j], ro, rd, curDistance))
			{
				if (curDistance < nearestDist)
				{
					nearestDist = curDistance;
					nearestObject = Objects[i];
					nearestTriangle = Objects[i].Triangles[j];
				}
			}
		}
	}
	
	vec3 color = vec3(0.); // TODO Sky
	// We hit something
	if (nearestDist < FLOAT_MAX)
	{
		vec3 p = ro + rd * nearestDist;
		// TODO basic lighting + normal
		color = vec3(1.0, 0.5, 0.0);
	}

	FragColor = vec4(color, 1.);
}


