#include "../GLSLRendererCPP/Swizzle.glsl.hpp"

#ifndef OPENGL_SHADER_CODE
#include "../GLSLRendererCPP/SwizzleProxies.hpp"
#include "../GLSLRendererCPP/GLSLFunctions.hpp"
#include "../GLSLRendererCPP/VariableArray.hpp"
#endif // !OPENGL_SHADER_CODE

struct TriangleData
{
	// TODO indices
	//uint A;
	//uint B;
	//uint C;
	// TODO normals + attributes

	float A[4];
	float B[4];
	float C[4];
};
struct ObjectData
{
	uint MaterialId;
	uint TriangleOffset; // index into the triangle buffer
	uint TriangleCount;
	uint _pad;
};

#ifdef OPENGL_SHADER_CODE
out vec4 FragColor;

layout(std430, binding = 0) readonly buffer ObjectBuffer { ObjectData objects[]; };
layout(std430, binding = 1) readonly buffer TriangleBuffer { TriangleData triangles[]; };

#else


VariableArray<ObjectData> objects;
VariableArray<TriangleData> triangles;
void main(vec4& FragColor, const vec4& gl_FragCoord);
int mainShaderCall(const vec4& gl_FragCoord)
{
	vec4 fragColor = vec4(0.);
	main(fragColor, gl_FragCoord);
	return fragColor.ToInt();
}
#endif

#ifdef OPENGL_SHADER_CODE
bool intersectTriangle(TriangleData triangle, vec3 origin, vec3 direction, out float distance)
#else
bool intersectTriangle(const TriangleData& triangle, vec3 origin, vec3 direction, float& distance)
#endif
{
	// Möller–Trumbore algorithm
	vec3 A = vec3(triangle.A[0], triangle.A[1], triangle.A[2]);
	vec3 B = vec3(triangle.B[0], triangle.B[1], triangle.B[2]);
	vec3 C = vec3(triangle.C[0], triangle.C[1], triangle.C[2]);

	vec3 AB = B - A;
	vec3 AC = C - A;

	vec3 h = cross(direction, AC);
	float det = dot(AB, h);

	// ray is parallel to triangle
	if (det > -0.00001f && det < 0.00001f)
		return false;

	float invDet = 1.0f / det;
	vec3 s = origin - A;
	float u = invDet * dot(s, h);

	if (u < 0.0f || u > 1.0f)
		return false;

	vec3 q = cross(s, AB);
	float v = invDet * dot(direction, q);

	if (v < 0.0f || u + v > 1.0f)
		return false;

	float t = invDet * dot(AC, q);

	if (t < 0.00001f)
		return false; // intersection behind ray origin

	distance = t;
	return true;
}

#ifdef OPENGL_SHADER_CODE
#define UNIFORM(TYPE, NAME) uniform TYPE NAME;
#else
#include <map>
std::map<std::string, void*> UniformsMap;
#define UNIFORM(TYPE, NAME) TYPE NAME; auto dummy##NAME = UniformsMap.insert_or_assign(#NAME, (void*)&NAME);
#endif

UNIFORM(vec3, cameraPosition);
UNIFORM(float, cameraPitch);
UNIFORM(float, cameraYaw);
UNIFORM(vec2, resolution);

#define rot(a) mat2(cos(a), -sin(a), sin(a), cos(a))

vec3 indexToColor(unsigned int i) {
	vec3 colors[10];
	colors[0] = vec3(1.0, 0.2, 0.2);  // red
	colors[1] = vec3(0.2, 0.6, 1.0);  // blue
	colors[2] = vec3(0.2, 1.0, 0.4);  // green
	colors[3] = vec3(1.0, 0.8, 0.2);  // yellow
	colors[4] = vec3(1.0, 0.5, 0.1);  // orange
	colors[5] = vec3(0.8, 0.2, 1.0);  // purple
	colors[6] = vec3(0.2, 1.0, 1.0);  // cyan
	colors[7] = vec3(1.0, 0.2, 0.8);  // pink
	colors[8] = vec3(0.5, 1.0, 0.2);  // lime
	colors[9] = vec3(1.0, 1.0, 1.0);  // white
	return colors[i % 10];
}


#ifdef OPENGL_SHADER_CODE
#define sat(a) clamp(a, 0., 1.)
void main()
#else
#define sat(a) a
#define sign(a) a
void main(vec4& FragColor, const vec4& gl_FragCoord)
#endif
{
	vec2 uv = (gl_FragCoord.XY_ - resolution * 0.5) / resolution.XX_; // TODO center and normalize coordinates
	uv.Y_ = -uv.Y_;
	// TODO get coordinates
	// TODO move and rotate camera
	vec3 ro = cameraPosition;
	vec3 rd = normalize(vec3(uv.X_, uv.Y_, 1.));

	rd.ZY_ = rot(cameraPitch) * rd.ZY_;
	rd.XZ_ = rot(cameraYaw) * rd.XZ_;

	const float FLOAT_MAX = 1000000.0f;
	float nearestDist = FLOAT_MAX;
	int nearestObjectIdx = -1;
	TriangleData nearestTriangle;

	for (int i = 0; i < objects.length(); ++i)
	{
		for (int j = 0; j < objects[i].TriangleCount; ++j)
		{
			float curDistance = 0.0f;
			TriangleData tri = triangles[objects[i].TriangleOffset + j];
			if (intersectTriangle(tri, ro, rd, curDistance))
			{
				if (curDistance < nearestDist)
				{
					nearestDist = curDistance;
					nearestObjectIdx = i;
					nearestTriangle = tri;
				}
			}
		}
	}

	vec3 color = vec3(0.); // TODO Sky
	// We hit something
	if (nearestDist < FLOAT_MAX && nearestObjectIdx != -1 && nearestObjectIdx < objects.length())
	{
		vec3 p = ro + rd * nearestDist;
		vec3 A = vec3(nearestTriangle.A[0], nearestTriangle.A[1], nearestTriangle.A[2]);
		vec3 B = vec3(nearestTriangle.B[0], nearestTriangle.B[1], nearestTriangle.B[2]);
		vec3 C = vec3(nearestTriangle.C[0], nearestTriangle.C[1], nearestTriangle.C[2]);
		vec3 n = normalize(cross(B - A, C - A));
		n = n * sign(dot(rd, n));
		vec3 ldir = normalize(vec3(1., -1., 1.));
		// TODO basic lighting + normal
		vec3 rgb = indexToColor(objects[nearestObjectIdx].MaterialId);
		color = rgb * 0.5 + rgb * sat(dot(ldir, n));
		
	}
		//color = vec3(triangles.length() > 0 && triangles[1].A[0] != 101011. ? 1 : 0, 0., objects.length());
		//color += vec3(0, 1., 0.);
	//color = vec3(uv.X_, uv.Y_, 0.);
	FragColor = vec4(color, 1.);
}


