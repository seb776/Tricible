#include "Scene.hpp"

//using namespace Tricible::Scene;

namespace Tricible
{
	namespace Scene
	{

		bool Scene::IntersectsRay(const Point3 & origin, const Point3 & vec, IntersectionInfo *interInfo, float nearClip, float farClip)
		{
			float nearestDist = -1.0f;
			interInfo->Origin = origin;
			IntersectionInfo retainedInterInfo;

			for (Tricible::AIntersectable *o : Objects)
			{
				IntersectionInfo curInterInfo;

				if (o->IntersectsRay(origin, vec, &curInterInfo, CurrentCamera->NearClip, CurrentCamera->FarClip))
				{
					float interDist = curInterInfo.Distance;

					if ((nearestDist < 0.f || interDist < nearestDist) && (interDist > CurrentCamera->NearClip && interDist < CurrentCamera->FarClip))
					{
						curInterInfo.Object = o;
						retainedInterInfo = curInterInfo;
						nearestDist = interDist;
					}
				}
			}

			retainedInterInfo.Intersection = retainedInterInfo.Origin + retainedInterInfo.Direction * retainedInterInfo.Distance;

			*interInfo = retainedInterInfo;
			return !!interInfo->Object;
		}

		void Scene::ComputeNormal(const IntersectionInfo & interInfo, Point3 & normal)
		{
			auto &normalDir = interInfo.Intersection - this->_position;

			normalDir.Normalize();
			normal = normalDir;
		}
	}
}
