#pragma once

#include "Collider.h"
#include "IntersectData.h"
#include "MeshCollider.h"
#include "..\core\Utils.h"

namespace Engine
{
	class SphericalCollider : public Collider
	{
	public:
		SphericalCollider(const glm::vec3& center, float radius);
		~SphericalCollider();

		glm::vec3 GetCenter() const;
		float GetRadius() const;

		IntersectData& Intersect(Collider* otherCollider);

	private:
		glm::vec3 center;
		float radius;
	};
}