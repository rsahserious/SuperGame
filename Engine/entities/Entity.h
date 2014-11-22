#pragma once

namespace Engine
{
	class Entity
	{
	public:
		virtual void Update() = 0;
		virtual void Render() = 0;
	};
}