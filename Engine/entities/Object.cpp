#include "Object.h"

namespace Engine
{
	Object::Object(const string& objPath, const string& texturePath)
	{
		this->mesh = new Mesh(objPath);
		this->material = new Material(texturePath);
		this->transform = new Transform();
		this->physicsData = new PhysicsData();
	}

	Object::Object(const string& objPath, const string& texturePath, Collider* collider)
		: Object(objPath, texturePath)
	{
		this->collider = collider;

		if (this->HasCollider())
		{
			this->collider->SetTransform(this->transform);
		}
	}

	Object::~Object()
	{
		delete this->transform;
		delete this->material;
		delete this->mesh;

		if (this->HasCollider())
		{
			delete this->collider;
		}
	}

	bool Object::HasCollider()
	{
		return this->collider != nullptr;
	}

	void Object::Update()
	{
		
	}

	void Object::Render()
	{
		this->material->GetTexture()->Bind();
		this->mesh->Draw();
	}
}