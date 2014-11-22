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
		else if (otherMesh != NULL)
		{
			vector<glm::vec3> vertices = otherMesh->GetVertices();
			assert(vertices.size() % 3 == 0);

			for (unsigned int i = 0; i < vertices.size() - 2; i += 3)
			{
				glm::vec3& vertexA = vertices[i];
				glm::vec3& vertexB = vertices[i + 1];
				glm::vec3& vertexC = vertices[i + 2];
				glm::vec3& center = this->GetCenter();

				bool b1 = Utils::sign(center, vertexA, vertexB) < 0.0f;
				bool b2 = Utils::sign(center, vertexB, vertexC) < 0.0f;
				bool b3 = Utils::sign(center, vertexC, vertexA) < 0.0f;

				if (b1 == b2 && b2 == b3)
				{
					return IntersectData(true, 1.0f);
				}
			}
		}

		return IntersectData(false);
	}
}