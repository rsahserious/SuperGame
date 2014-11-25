#pragma once

#include "..\entities\Object.h"
#include "..\core\Utils.h"
#include "SphericalCollider.h"
#include "MeshCollider.h"

namespace Engine
{
	#define COLLIDER_TYPE_CMP(c1, c2) (dynamic_cast<c1*>(colliderA)&&dynamic_cast<c2*>(colliderB)) //||(dynamic_cast<c1*>(colliderB)&&dynamic_cast<c2*>(colliderA))

	class CollisionHandler
	{
	public:
		static void HandleObjects(Object* objectA, Object* objectB, IntersectData& intersectData);

	private:
		static void sphereWithSphere(Object* objectA, Object* objectB, IntersectData& intersectData);
		static void sphereWithRect(Object* objectA, Object* objectB, IntersectData& intersectData);
		static void sphereWithMesh(Object* objectA, Object* objectB, IntersectData& intersectData);
	};
}