#pragma once

namespace Engine
{
	class IObject
	{
	public:
		virtual void Update(float deltaTime) = 0;
		virtual void Render() = 0;
	};
}