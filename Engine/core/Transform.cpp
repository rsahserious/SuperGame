#include "Transform.h"

namespace Engine
{
	Transform::Transform(const glm::vec3& pos, const glm::vec3& rot, const glm::vec3& scale)
	{
		this->pos = pos;
		this->rot = rot;
		this->scale = scale;
	}

	Transform::~Transform()
	{

	}

	glm::mat4 Transform::GetModel()
	{
		glm::mat4 posMatrix = glm::translate(this->pos);
		glm::mat4 rotXMatrix = glm::rotate(this->rot.x, glm::vec3(1.0f, 0.0f, 0.0f));
		glm::mat4 rotYMatrix = glm::rotate(this->rot.y, glm::vec3(0.0f, 1.0f, 0.0f));
		glm::mat4 rotZMatrix = glm::rotate(this->rot.z, glm::vec3(0.0f, 0.0f, 1.0f));
		glm::mat4 scaleMatrix = glm::scale(this->scale);

		glm::mat4 rotMatrix = rotXMatrix * rotYMatrix * rotZMatrix;

		glm::mat4 matrix = posMatrix * rotMatrix * scaleMatrix;

		return matrix;
	}
}