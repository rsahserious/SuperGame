#pragma once

#include <vector>
#include "../entities/DynamicObject.h"

namespace Engine
{
	class PhysicsWorld
	{
	public:
		PhysicsWorld();
		~PhysicsWorld();

		void AddObject(Object* object);
		void RemoveObject(Object* object);

		void Simulate();

		inline glm::vec3& GetGravityVector() { return this->gravityVector; }
		inline void SetGravityVector(const glm::vec3& vector) { this->gravityVector = vector; }

		inline float GetGravityStrength() { return this->gravityStrength; }
		inline void SetGravityStrength(float strength) { this->gravityStrength = strength; }

		inline float GetAirDensity() { return this->airDensity; }
		inline void SetAirDensity(float density) { this->airDensity = density; }

	private:
		glm::vec3 gravityVector = glm::vec3(0.0f, -1.0f, 0.0f);
		float gravityStrength = 0.0f;
		float airDensity = 0.5f;

		std::vector<Object*> objects;
	};
}