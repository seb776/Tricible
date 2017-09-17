#include "Scene.hpp"

//using namespace Tricible::Scene;

namespace Tricible
{
	namespace Scene
	{

		bool Scene::IntersectsRay(const Point3 & origin, const Point3 & vec, IntersectionInfo *interInfo)
		{
			float nearestDist = -1.0f;
			for (Tricible::AIntersectable *o : Objects)
			{
				if (o->IntersectsRay(CurrentCamera->getPosition() + vec, vec, interInfo))
				{
					float interDist = interInfo->Distance;

					if (interInfo->Distance > CurrentCamera->NearClip && interInfo->Distance < CurrentCamera->FarClip)
					{
						if (nearestDist < 0.f || interDist < nearestDist)
						{
							interInfo->Object = o;
							nearestDist = interDist;
						}
					}
				}
			}
			return !!interInfo->Object;
		}

		void Scene::ComputeNormal(const IntersectionInfo & interInfo, Point3 & normal)
		{
		}
	}
}
