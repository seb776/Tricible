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
				if (o->IntersectsRay(origin, vec, interInfo))
				{
					float interDist = interInfo->Distance;

					if (interDist > CurrentCamera->NearClip && interDist < CurrentCamera->FarClip)
					{
						if (nearestDist < 0.f || interDist < nearestDist)
						{
							interInfo->Object = o;
							nearestDist = interDist;
						}
					}
				}
			}
			interInfo->Intersection = interInfo->Origin + interInfo->Direction * interInfo->Distance;
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
