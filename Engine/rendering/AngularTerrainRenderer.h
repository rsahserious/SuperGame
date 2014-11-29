#pragma once

#include "TerrainRenderer.h"

namespace Engine
{
	class AngularTerrainRenderer : public TerrainRenderer
	{
	public:
		AngularTerrainRenderer(glm::vec3 initialPosition, float grain, float minDistance);
		~AngularTerrainRenderer();

		void Update(glm::vec3 position);

	private:
		void addPoint(glm::vec2 point);
		bool pointExists(glm::vec2 point);
		glm::vec3 getGrainedPosition();

		float minDistance = 0.0f;
		vector<glm::vec2> points;
	};
}