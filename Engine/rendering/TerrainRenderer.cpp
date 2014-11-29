#include "TerrainRenderer.h"

namespace Engine
{
	TerrainRenderer::TerrainRenderer(glm::vec3 initialPosition, float grain)
	{
		this->position = initialPosition;
		this->grain = grain;
	}

	TerrainRenderer::~TerrainRenderer()
	{

	}

	void TerrainRenderer::Update(glm::vec3 position)
	{
		this->mesh.Update(this->vertexModel);
	}
}