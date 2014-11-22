#include "PhysicsWorld.h"

namespace Engine
{
	PhysicsWorld::PhysicsWorld()
	{

	}

	PhysicsWorld::~PhysicsWorld()
	{

	}

	void PhysicsWorld::AddObject(Object* object)
	{
		this->objects.push_back(object);
	}

	void PhysicsWorld::RemoveObject(Object* object)
	{
		std::vector<Object*>::iterator iterator
			= std::find(this->objects.begin(), this->objects.end(), object);

		if (iterator != this->objects.end())
		{
			this->objects.erase(iterator);
		}
	}

	void PhysicsWorld::Simulate()
	{
		for (unsigned int i = 0; i < this->objects.size(); i++)
		{
			DynamicObject* dynamicObject = dynamic_cast<DynamicObject*>(this->objects[i]);

			if (dynamicObject != NULL)
			{
				dynamicObject->HandleCollisions(this->objects);

				// gravity
				float gDelta = 0.00003f;
				glm::vec3 gFactor = gDelta * this->gravityStrength * dynamicObject->GetPhysicsData()->GetMass() * this->gravityVector;
				*dynamicObject->GetPhysicsData()->GetVelocity() += gFactor;

				// air resistance
				float rDelta = 0.003;
				float rFactor = 1.0f - (this->airDensity * rDelta);
				if (rDelta > 0.0f)
				{
					*dynamicObject->GetPhysicsData()->GetVelocity() *= rFactor;
				}
			}

			this->objects[i]->Update();
		}
	}
}