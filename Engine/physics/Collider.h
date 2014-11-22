#pragma once

#include <glm\glm.hpp>
#include "IntersectData.h"
#include "..\core\Transform.h"

namespace Engine
{
	class Collider
	{
	public:
		Collider();
		virtual ~Collider();

		inline Transform* GetTransform() { return this->transform; }
		inline void SetTransform(Transform* transform) { this->transform = transform; }

		virtual IntersectData& Intersect(Collider* otherCollider) = 0;

	protected:
		Transform* transform;
	};
}