#include "Object.h"

namespace Engine
{
	Object::Object(VertexModel& vertexModel, Material& material)
	{
		this->mesh = new Mesh(vertexModel);
		this->material = &material;

		this->init();
	}

	Object::Object(const string& objPath, const string& texturePath)
	{
		this->mesh = new Mesh(objPath);
		this->material = new Material(texturePath);
		
		this->init();
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

	void Object::SetCollider(Collider* collider)
	{
		this->collider = collider;
		this->collider->SetTransform(this->transform);
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

	void Object::init()
	{
		this->transform = new Transform();
		this->physicsData = new PhysicsData();
	}
}