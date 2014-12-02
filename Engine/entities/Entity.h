#pragma once

namespace Engine
{
	class Entity
	{
	public:
		virtual void Update(float deltaTime) = 0;
		virtual void Render() = 0;
	};
}