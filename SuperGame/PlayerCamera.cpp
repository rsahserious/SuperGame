#include "PlayerCamera.h"

PlayerCamera::PlayerCamera() :

	position(glm::vec3(-40, 45.0f, 0.0f)),
	angle(270.0f),
	tilt(0.0f)

{
	const glm::vec3 upVector(0.0f, 1.0f, 0.0f);

	this->camera = Engine::Camera(
		this->position,
		this->angle,
		this->tilt,
		upVector,
		Constants::ASPECT_RATIO,
		Constants::FOV,
		Constants::MIN_DRAW_DISTANCE,
		Constants::MAX_DRAW_DISTANCE
	);
}

PlayerCamera::~PlayerCamera()
{

}

void PlayerCamera::UpdatePosition()
{
	this->camera.SetPosition(this->position);
	//std::cout << "Camera | x: " << this->position.x << " y: " << this->position.y << " z: " << this->position.z << std::endl;
}

void PlayerCamera::UpdateEyeDirection(const float xOffset, const float yOffset)
{
	static const float factorX = Constants::MOUSE_SENSITIVITY * Constants::ASPECT_RATIO;
	static const float factorY = Constants::MOUSE_SENSITIVITY / 180.0f;

	this->angle += xOffset * 0.1f;

	if (this->angle >= 360.0f)	this->angle -= 360.0f;
	else if (this->angle < 0)	this->angle += 360.0f;

	this->tilt += -(yOffset * 0.0025f);

	if (this->tilt > 1.0f)			this->tilt = 1.0f;
	else if (this->tilt < -1.0f)	this->tilt = -1.0f;

	this->camera.SetEyeDirection(this->angle, this->tilt);
}