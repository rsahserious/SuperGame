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
		return IntersectData(false);
	}
}