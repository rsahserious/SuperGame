#include "TerrainRenderer.h"

namespace Engine
{
	TerrainRenderer::TerrainRenderer(const glm::vec3& initialPosition, float grain)
	{
		this->position = initialPosition;
		this->grain = grain;
	}

	TerrainRenderer::~TerrainRenderer()
	{

	}

	void TerrainRenderer::Update(const glm::vec3& position)
	{
		this->mesh.Update(this->vertexModel);
	}
}