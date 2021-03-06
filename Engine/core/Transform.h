#pragma once

#include <glm\glm.hpp>
#include <glm\gtx\transform.hpp>

namespace Engine
{
	class Transform
	{
	public:
		Transform(
			const glm::vec3& pos = glm::vec3(),
			const glm::vec3& rot = glm::vec3(),
			const glm::vec3& scale = glm::vec3(1.0f, 1.0f, 1.0f)
		);
		~Transform();

		glm::mat4 GetModel();

		inline glm::vec3& GetPos() { return this->pos; };
		inline glm::vec3& GetRot() { return this->rot; };
		inline glm::vec3& GetScale() { return this->scale; };

		inline void SetPos(const glm::vec3& pos) { this->pos = pos; }
		inline void SetRot(const glm::vec3& rot) { this->rot = rot; }
		inline void SetScale(const glm::vec3& scale) { this->scale = scale; }

	private:
		glm::vec3 pos;
		glm::vec3 rot;
		glm::vec3 scale;
	};
}