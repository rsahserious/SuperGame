#include "Camera.h"

namespace Engine
{
	Camera::Camera(const glm::vec3& position, float angle, float tilt, const glm::vec3& upVector,
		float aspectRatio, float FOV, float zNear, float zFar)
	{
		this->position = position;
		this->upVector = upVector;

		this->SetEyeDirection(angle, tilt);

		this->perspective = glm::perspective(FOV, aspectRatio, zNear, zFar);
	}

	Camera::~Camera()
	{
	}

	void Camera::SetEyeDirection(float angle, float tilt)
	{
		static const float HALF_PI = 3.14 / 2;

		float nAngle = -angle / RADIAN_OF_DEGREES;
		float nTilt = tilt * HALF_PI;

		float vX = cosf(nTilt) * sinf(nAngle);
		float vY = sinf(nTilt);
		float vZ = cosf(nTilt) * cosf(nAngle);

		this->forwardVector = glm::vec3(vX, vY, vZ);

		//std::cout << "Eye | x: " << this->forwardVector.x << " y: " << this->forwardVector.y << " z: " << this->forwardVector.z << std::endl;
	}

	glm::mat4 Camera::GetViewProjection()
	{
		return this->perspective
			* glm::lookAt(this->position, this->position + this->forwardVector, this->upVector);
	}
}