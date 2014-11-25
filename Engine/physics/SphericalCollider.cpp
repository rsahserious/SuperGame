#include "SphericalCollider.h"

namespace Engine
{
	SphericalCollider::SphericalCollider(const glm::vec3& center, float radius)
	{
		this->center = center;
		this->radius = radius;
	}

	SphericalCollider::~SphericalCollider()
	{

	}

	glm::vec3 SphericalCollider::GetCenter() const
	{
		return this->center + *this->transform->GetPos();
	}

	float SphericalCollider::GetRadius() const
	{
		return radius;
	}

	IntersectData& SphericalCollider::Intersect(Collider* otherCollider)
	{
		SphericalCollider* otherSphere = dynamic_cast<SphericalCollider*>(otherCollider);
		RectangularCollider* otherRect = dynamic_cast<RectangularCollider*>(otherCollider);
		MeshCollider* otherMesh = dynamic_cast<MeshCollider*>(otherCollider);

		if (otherSphere != NULL)
		{
			float distance = glm::length(this->GetCenter() - otherSphere->GetCenter());
			distance -= this->GetRadius();
			distance -= otherSphere->GetRadius();

			if (distance < 0)
			{
				return IntersectData(true, distance);
			}
		}
		else if (otherRect)
		{
			float distance = glm::length(this->GetCenter() - otherRect->GetMinExtents());
			printf("%f\n", distance);
			if (distance < 15)
			{
				return IntersectData(true, distance);
			}
		}
		else if (otherMesh != NULL)
		{
			// TODO
			/*vector<glm::vec3> vertices = otherMesh->GetVertices();
			assert(vertices.size() % 3 == 0);

			for (unsigned int i = 0; i < vertices.size() - 2; i += 3)
			{
				
			}*/
		}

		return IntersectData(false);
	}
}