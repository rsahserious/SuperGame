#include "DynamicObject.h"

namespace Engine
{
	DynamicObject::DynamicObject(Mesh* mesh, Material* material)
		: Object(mesh, material)
	{

	}

	DynamicObject::~DynamicObject()
	{

	}

	void DynamicObject::Update(float deltaTime)
	{
		this->transform->GetPos() += this->physicsData->GetVelocity() * deltaTime;
		this->transform->GetRot() += this->physicsData->GetAngularVelocity() * deltaTime;

		Object::Update(deltaTime);
	}

	void DynamicObject::HandleCollisions(const std::vector<Object*>& otherObjects)
	{
		for (unsigned int i = 0; i < otherObjects.size(); i++)
		{
			if (otherObjects[i] == this || !this->HasCollider() || !otherObjects[i]->HasCollider())
			{
				continue;
			}

			IntersectData intersectData = this->collider->Intersect(otherObjects[i]->GetCollider());
			
			if (intersectData.GetDoesIntersect())
			{
				CollisionHandler::HandleObjects(this, otherObjects[i], intersectData);
			}
		}

		// temporary surface
		float surfaceHeight = 1.0f;
		float height = this->transform->GetPos().y - surfaceHeight;

		if (height < 0.0f)
		{
			this->transform->GetPos().y -= height;
			this->physicsData->GetVelocity().y *= -this->physicsData->GetElasticity();
		}
	}
}