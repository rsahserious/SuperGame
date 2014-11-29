#pragma once

#include <glm\glm.hpp>
#include "..\core\VertexModel.h"
#include "..\rendering\DynamicMesh.h"

namespace Engine
{
	class TerrainRenderer
	{
	public:
		TerrainRenderer(const glm::vec3& initialPosition, float grain);
		virtual ~TerrainRenderer();

		virtual void Update(const glm::vec3& position) = 0;

		inline VertexModel& GetVertexModel() { return this->vertexModel; }
		inline DynamicMesh& GetMesh() { return this->mesh; }

	protected:
		glm::vec3 position;
		float grain = 1.0f;
		VertexModel vertexModel;
		DynamicMesh mesh;
	};
}