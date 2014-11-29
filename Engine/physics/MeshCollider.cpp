#include "MeshCollider.h"
#include "SphericalCollider.h"

namespace Engine
{
	MeshCollider::MeshCollider(VertexModel& vertexModel)
	{
		this->vertices = vertexModel.GetVertices();
	}

	MeshCollider::~MeshCollider()
	{

	}

	IntersectData MeshCollider::Intersect(Collider* otherCollider)
	{
		SphericalCollider* otherSphere = dynamic_cast<SphericalCollider*>(otherCollider);

		float distance = 0.0f;

		if (distance < 0)
		{
			return IntersectData(true, distance);
		}

		return IntersectData(false);
	}
}