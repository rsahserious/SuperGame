#pragma once

#include <glm\glm.hpp>
#include <Engine\rendering\Camera.h>
#include "Constants.h"

class PlayerCamera
{
public:
	static PlayerCamera& GetInstance()
	{
		static PlayerCamera instance;
		return instance;
	}
	~PlayerCamera();

	void UpdatePosition();
	void UpdateEyeDirection(const float xOffset, const float yOffset);

	inline Engine::Camera& GetCamera() { return *this->camera; }
	inline glm::vec3* GetPosition() { return &this->position; }
	inline float GetAngle() { return this->angle; }
	inline float GetTilt() { return this->tilt; }

private:
	PlayerCamera();
	
	Engine::Camera* camera;
	glm::vec3 position;
	float angle;
	float tilt;
};

