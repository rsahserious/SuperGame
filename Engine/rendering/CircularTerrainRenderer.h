#pragma once

#include "TerrainRenderer.h"

namespace Engine
{
	class CircularTerrainRenderer : public TerrainRenderer
	{
	public:
		CircularTerrainRenderer();
		~CircularTerrainRenderer();

		void Update(const glm::vec3& position);

	private:
		
	};
}