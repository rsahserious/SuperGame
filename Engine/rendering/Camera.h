#pragma once

#include <iostream>
#include <glm\glm.hpp>
#include <glm\gtx\transform.hpp>
#include <glew\glew.h>

#define RADIAN_OF_DEGREES 57.2957795

namespace Engine
{
	class Camera
	{
	public:
		Camera();
		Camera(const glm::vec3& position, float angle, float tilt, const glm::vec3& upVector, 
			float aspectRatio, float FOV, float zNear, float zFar);
		~Camera();

		inline void SetPosition(const glm::vec3& position) { this->position = position; }
		void SetEyeDirection(float angle, float tilt);

		glm::mat4 GetViewProjection();

	private:
		glm::mat4 perspective;
		glm::vec3 position;
		glm::vec3 forwardVector;
		glm::vec3 upVector;
	};
}