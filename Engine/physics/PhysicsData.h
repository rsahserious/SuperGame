#pragma once

#include <glm\glm.hpp>

namespace Engine
{
	class PhysicsData
	{
	public:
		inline float GetMass() { return this->mass; }
		inline void SetMass(float mass) { this->mass = mass; }

		inline float GetElasticity() { return this->elasticity; }
		inline void SetElasticity(float elasticity)
		{
			this->elasticity = glm::clamp(elasticity, 0.0f, 1.0f);
		}

		inline glm::vec3& GetVelocity() { return this->velocity; }
		inline void SetVelocity(const glm::vec3& velocity) { this->velocity = velocity; }

		inline glm::vec3& GetAngularVelocity() { return this->angularVelocity; }
		inline void SetAngularVelocity(const glm::vec3& angularVelocity) { this->angularVelocity = angularVelocity; }

	private:
		float mass = 15.0f;
		float elasticity = 0.85f;

		glm::vec3 velocity = glm::vec3(0.0f, 0.0f, 0.0f);
		glm::vec3 angularVelocity = glm::vec3(0.0f, 0.0f, 0.0f);
	};
}