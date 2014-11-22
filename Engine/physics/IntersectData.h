#pragma once

#include "Collider.h"
#include "PhysicsData.h"

namespace Engine
{
	class IntersectData
	{
	public:
		IntersectData(bool doesIntersect)
		{
			this->doesIntersect = doesIntersect;
		}

		IntersectData(bool doesIntersect, float distance)
		{
			this->doesIntersect = doesIntersect;
			this->distance = distance;
		}

		/*IntersectData(bool doesIntersect, PhysicsData* newPhysicsData)
		{
			this->doesIntersect = doesIntersect;
			this->newPhysicsData = newPhysicsData;
		}*/

		inline bool GetDoesIntersect() { return this->doesIntersect; }
		inline float GetDistance() { return this->distance; }

	private:
		bool doesIntersect = false;
		float distance = 0.0f;
			
		//PhysicsData* newPhysicsData = nullptr;
	};
}