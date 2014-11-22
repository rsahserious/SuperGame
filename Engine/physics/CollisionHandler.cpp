#include "CollisionHandler.h"

namespace Engine
{
	void CollisionHandler::HandleObjects(Object* objectA, Object* objectB, IntersectData& intersectData)
	{
		Collider* colliderA = objectA->GetCollider();
		Collider* colliderB = objectB->GetCollider();

		if (COLLIDER_TYPE_CMP(SphericalCollider, SphericalCollider))
		{
			sphereWithSphere(objectA, objectB, intersectData);
		}
		else if (COLLIDER_TYPE_CMP(SphericalCollider, MeshCollider))
		{
			sphereWithMesh(objectA, objectB, intersectData);
		}
	}

	void CollisionHandler::sphereWithSphere(Object* objectA, Object* objectB, IntersectData& intersectData)
	{
		glm::vec3 v1 = *objectA->GetPhysicsData()->GetVelocity();
		glm::vec3 v2 = *objectB->GetPhysicsData()->GetVelocity();

		glm::vec3 pos1 = *objectA->GetTransform()->GetPos();
		glm::vec3 pos2 = *objectB->GetTransform()->GetPos();

		glm::vec3 dist1 = pos1 - pos2;
		glm::vec3 dist2 = pos2 - pos1;

		glm::vec3 nv1 = v1 + Utils::project(v2, dist2) - Utils::project(v1, dist1);
		glm::vec3 nv2 = v2 + Utils::project(v1, dist2) - Utils::project(v2, dist1);

		*objectA->GetTransform()->GetPos() -= glm::normalize(nv1) * intersectData.GetDistance();

		objectA->GetPhysicsData()->SetVelocity(nv1);
		objectB->GetPhysicsData()->SetVelocity(nv2);
	}

	void CollisionHandler::sphereWithMesh(Object* objectA, Object* objectB, IntersectData& intersectData)
	{
		objectA->GetPhysicsData()->SetVelocity(-*objectA->GetPhysicsData()->GetVelocity());
		objectB->GetPhysicsData()->SetVelocity(-*objectB->GetPhysicsData()->GetVelocity());
	}
}