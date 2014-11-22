#include "DynamicObject.h"

namespace Engine
{
	DynamicObject::DynamicObject(const string& objPath, const string& texturePath)
		: Object(objPath, texturePath)
	{

	}

	DynamicObject::DynamicObject(const string& objPath, const string& texturePath,
		Collider* collider)
		: Object(objPath, texturePath, collider)
	{

	}

	DynamicObject::~DynamicObject()
	{

	}

	void DynamicObject::Update()
	{
		*this->transform->GetPos() += *this->physicsData->GetVelocity();
		*this->transform->GetRot() += *this->physicsData->GetAngularVelocity();

		Object::Update();
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

		// temporary
		float surfaceHeight = 1.0f;
		float height = this->transform->GetPos()->y - surfaceHeight;

		if (height < 0.0f)
		{
			this->transform->GetPos()->y -= height;
			this->physicsData->GetVelocity()->y *= -this->physicsData->GetElasticity();
		}
	}
}