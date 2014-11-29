#pragma once

#include "Collider.h"
#include "IntersectData.h"

namespace Engine
{
	class RectangularCollider : public Collider
	{
	public:
		RectangularCollider(const glm::vec3& maxExtents, const glm::vec3& minExtents);
		~RectangularCollider();

		glm::vec3 GetMaxExtents() const;
		glm::vec3 GetMinExtents() const;
			
		IntersectData Intersect(Collider* otherCollider);

	private:			
		glm::vec3 maxExtents;
		glm::vec3 minExtents;
	};
}