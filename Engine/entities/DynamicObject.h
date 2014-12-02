#pragma once

#include <string>
#include "Object.h"
#include "..\physics\PhysicsData.h"
#include "..\physics\RectangularCollider.h"
#include "..\physics\CollisionHandler.h"
#include "..\core\Utils.h"

using std::string;

namespace Engine
{
	class DynamicObject : public Object
	{
	public:
		DynamicObject(Mesh* mesh, Material* material);
		~DynamicObject();

		void Update(float deltaTime) override;
		void HandleCollisions(const std::vector<Object*>& otherObjects);

	private:
	};
}