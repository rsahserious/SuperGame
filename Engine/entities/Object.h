#pragma once

#include <string>
#include "Entity.h"
#include "..\core\Transform.h"
#include "..\rendering\Mesh.h"
#include "..\rendering\Material.h"
#include "..\physics\RectangularCollider.h"
#include "..\physics\PhysicsData.h"

using std::string;

namespace Engine
{
	class Object : public Entity
	{
	public:
		Object(Mesh* mesh, Material* material);
		~Object();

		inline Mesh* GetMesh() { return this->mesh; }
		inline Material* GetMaterial() { return this->material; }
		inline Transform* GetTransform() { return this->transform; }
		inline Collider* GetCollider() { return this->collider; }
		inline PhysicsData* GetPhysicsData() { return this->physicsData; }

		void SetCollider(Collider* collider);

		bool HasCollider();

		virtual void Update();
		virtual void Render();

	protected:
		Mesh* mesh;
		Material* material;
		Transform* transform;
		Collider* collider = nullptr;
		PhysicsData* physicsData;

	private:
		virtual void init();
	};
}