#include "Object.h"

namespace Engine
{
	Object::Object(Mesh* mesh, Material* material)
	{
		this->mesh = mesh;
		this->material = material;

		this->init();
	}

	Object::~Object()
	{
		delete this->transform;

		if (this->HasCollider())
		{
			delete this->collider;
		}
	}

	void Object::SetCollider(Collider* collider)
	{
		this->collider = collider;
		this->collider->SetTransform(this->transform);
	}

	bool Object::HasCollider()
	{
		return this->collider != nullptr;
	}

	void Object::Update(float deltaTime)
	{
		
	}

	void Object::Render()
	{
		this->material->GetTexture()->Bind();
		this->mesh->Draw();
	}

	void Object::init()
	{
		this->transform = new Transform();
		this->physicsData = new PhysicsData();
	}
}