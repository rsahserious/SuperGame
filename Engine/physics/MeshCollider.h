#pragma once

#include "Collider.h"
#include "IntersectData.h"
#include "..\core\VertexModel.h"

namespace Engine
{
	class MeshCollider : public Collider
	{
	public:
		MeshCollider(VertexModel& vertexModel);
		~MeshCollider();

		IntersectData& Intersect(Collider* otherCollider);

		inline vector<glm::vec3>& GetVertices() { return this->vertices; }

	private:
		vector<glm::vec3> vertices;
	};
}