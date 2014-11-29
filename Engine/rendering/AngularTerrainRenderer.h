#pragma once

#include "TerrainRenderer.h"

namespace Engine
{
	class AngularTerrainRenderer : public TerrainRenderer
	{
	public:
		AngularTerrainRenderer(const glm::vec3& initialPosition, float grain, float minDistance);
		~AngularTerrainRenderer();

		void Update(const glm::vec3& position);

	private:
		void addPoint(const glm::vec2& point);
		bool pointExists(const glm::vec2& point);
		glm::vec3 getGrainedPosition();

		float minDistance = 0.0f;
		vector<glm::vec2> points;
	};
}