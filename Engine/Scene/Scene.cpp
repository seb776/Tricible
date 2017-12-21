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
			for (Tricible::AIntersectable *o : Objects)
			{
				if (o->IntersectsRay(origin, vec, interInfo, CurrentCamera->NearClip, CurrentCamera->FarClip))
				{
					float interDist = interInfo->Distance;

					if ((nearestDist < 0.f || interDist < nearestDist) && (interDist > CurrentCamera->NearClip && interDist < CurrentCamera->FarClip))
					{
						interInfo->Object = o;
						nearestDist = interDist;
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
