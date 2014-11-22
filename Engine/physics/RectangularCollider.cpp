#include "RectangularCollider.h"

namespace Engine
{
	RectangularCollider::RectangularCollider(const glm::vec3& maxExtents, const glm::vec3& minExtents)
	{
		this->maxExtents = maxExtents;
		this->minExtents = minExtents;
	}

	RectangularCollider::~RectangularCollider()
	{

	}

	glm::vec3 RectangularCollider::GetMaxExtents() const
	{
		return this->maxExtents + *this->transform->GetPos();
	}

	glm::vec3 RectangularCollider::GetMinExtents() const
	{
		return this->minExtents + *this->transform->GetPos();
	}

	IntersectData& RectangularCollider::Intersect(Collider* otherCollider)
	{
		RectangularCollider* otherRect = dynamic_cast<RectangularCollider*>(otherCollider);

		glm::vec3 distances1 = otherRect->GetMinExtents() - this->GetMaxExtents();
		glm::vec3 distances2 = this->GetMinExtents() - otherRect->GetMaxExtents();

		glm::vec3 distances = glm::max(distances1, distances2);
		float maxDistance = glm::max(distances.x, glm::max(distances.y, distances.z));

		return IntersectData(maxDistance < 0);
	}
}