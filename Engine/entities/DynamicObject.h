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
		DynamicObject(const string& objPath, const string& texturePath);
		~DynamicObject();

		void Update() override;
		void HandleCollisions(const std::vector<Object*>& otherObjects);

	private:
	};
}