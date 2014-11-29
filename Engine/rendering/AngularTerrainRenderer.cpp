#include "AngularTerrainRenderer.h"

namespace Engine
{
	AngularTerrainRenderer::AngularTerrainRenderer(glm::vec3 initialPosition, float grain, float minDistance)
		: TerrainRenderer(initialPosition, grain)
	{
		this->minDistance = minDistance;

		this->Update(initialPosition);
	}

	AngularTerrainRenderer::~AngularTerrainRenderer()
	{

	}

	void AngularTerrainRenderer::Update(glm::vec3 position)
	{
		this->position = position;

		bool changed = false;

		glm::vec3 pos = this->getGrainedPosition();

		float maxX = pos.x + this->minDistance;
		float maxZ = pos.z + this->minDistance;

		for (float x = pos.x - this->minDistance; x <= maxX; x += this->grain)
		{
			for (float z = pos.z - this->minDistance; z <= maxZ; z += this->grain)
			{
				glm::vec2 point(x, z);

				if (!this->pointExists(point))
				{
					this->addPoint(point);
					changed = true;
				}
			}
		}

		if (changed)
		{
			TerrainRenderer::Update(position);
		}
	}

	void AngularTerrainRenderer::addPoint(glm::vec2 point)
	{
		// tmp
		static float height = 0.0f;
		static glm::vec3 normal(0.0f, 1.0f, 0.0f);

		static float hg = this->grain / 2;

		glm::vec3 v1(point.x + hg, height, point.y + hg);
		glm::vec3 v2(point.x + hg, height, point.y - hg);
		glm::vec3 v3(point.x - hg, height, point.y + hg);
		glm::vec3 v4(point.x - hg, height, point.y - hg);

		glm::vec2 uv1( 1.0f,  1.0f);
		glm::vec2 uv2( 1.0f, -1.0f);
		glm::vec2 uv3(-1.0f,  1.0f);
		glm::vec2 uv4(-1.0f, -1.0f);

		this->vertexModel.Add(v1, uv1, normal);
		this->vertexModel.Add(v2, uv2, normal);
		this->vertexModel.Add(v3, uv3, normal);

		this->vertexModel.Add(v2, uv2, normal);
		this->vertexModel.Add(v4, uv4, normal);
		this->vertexModel.Add(v3, uv3, normal);

		this->points.push_back(point);
	}

	bool AngularTerrainRenderer::pointExists(glm::vec2 point)
	{
		if (std::find(this->points.begin(), this->points.end(), point) != this->points.end())
		{
			return true;
		}

		return false;
	}

	glm::vec3 AngularTerrainRenderer::getGrainedPosition()
	{
		glm::vec3 pos = this->position;

		for (char i = 0; i <= 2; i += 2)
		{
			float rounded = 0.0f;

			if (pos[i] >= 0.0f)
			{
				while (rounded < pos[i]) rounded += this->grain;
			}
			else
			{
				while (rounded > pos[i]) rounded -= this->grain;
			}

			float offset = rounded - pos[i];
			pos[i] += offset;
		}
		
		assert(fmod(pos.x, this->grain) == 0.0f);
		assert(fmod(pos.z, this->grain) == 0.0f);

		return pos;
	}
}