#include "Mesh.hpp"

bool Tricible::Scene::Mesh::IntersectsRay(const Point3 & origin, const Point3 & vec, IntersectionInfo * interInfo, float nearClip, float farClip)
{
	float nearestDist = -1.0f;
	interInfo->Origin = origin;
	IntersectionInfo retainedInterInfo;

	for (Tricible::AIntersectable *o : SubMeshes)
	{
		IntersectionInfo curInterInfo;

		if (o->IntersectsRay(origin, vec, &curInterInfo, nearClip, farClip))
		{
			float interDist = curInterInfo.Distance;

			if ((nearestDist < 0.f || interDist < nearestDist) && (interDist > nearClip && interDist < farClip))
			{
				curInterInfo.Object = o;
				retainedInterInfo = curInterInfo;
				nearestDist = interDist;
			}
		}
	}

	if (!!retainedInterInfo.Object)
	{
		retainedInterInfo.Intersection = retainedInterInfo.Origin + retainedInterInfo.Direction * retainedInterInfo.Distance;
		*interInfo = retainedInterInfo;
		return true;
	}
	return false;
}

void Tricible::Scene::Mesh::ComputeNormal(const IntersectionInfo & interInfo, Point3 & normal)
{
	// TODO
	interInfo.Object->ComputeNormal(interInfo, normal);
	//auto &normalDir = interInfo.Intersection - this->_position;

	//normalDir.Normalize();
	//normal = normalDir;
}
