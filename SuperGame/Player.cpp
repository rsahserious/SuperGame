#include "Player.h"

Player::Player()
{

}

void Player::ExecuteAction(const t_Action action, float deltaTime)
{
	switch (action)
	{
	case PlayerAction::MOVE_FORWARD:	this->moveForward(deltaTime);	break;
	case PlayerAction::MOVE_BACKWARD:	this->moveBackward(deltaTime);	break;
	case PlayerAction::MOVE_LEFT:		this->moveLeft(deltaTime);		break;
	case PlayerAction::MOVE_RIGHT:		this->moveRight(deltaTime);		break;
	}
}

void Player::moveForward(float deltaTime)
{
	static PlayerCamera* camera = &PlayerCamera::GetInstance();
	const float factor = Misc::GetCameraSpeedFactor() * deltaTime;
	const float horizontalFactor = factor * (1.0f - abs(camera->GetTilt()));

	camera->GetPosition().x += sinf(-camera->GetAngle() / RADIAN_OF_DEGREES) * horizontalFactor;
	camera->GetPosition().z += cosf(-camera->GetAngle() / RADIAN_OF_DEGREES) * horizontalFactor;

	camera->GetPosition().y += camera->GetTilt() * factor;

	camera->UpdatePosition();
}

void Player::moveBackward(float deltaTime)
{
	static PlayerCamera* camera = &PlayerCamera::GetInstance();
	const float factor = Misc::GetCameraSpeedFactor() * deltaTime;
	const float horizontalFactor = factor * (1.0f - abs(camera->GetTilt()));

	camera->GetPosition().x -= sinf(-camera->GetAngle() / RADIAN_OF_DEGREES) * horizontalFactor;
	camera->GetPosition().z -= cosf(-camera->GetAngle() / RADIAN_OF_DEGREES) * horizontalFactor;
	camera->GetPosition().y += -camera->GetTilt() * factor;

	camera->UpdatePosition();
}

void Player::moveLeft(float deltaTime)
{
	static PlayerCamera* camera = &PlayerCamera::GetInstance();
	const float factor = Misc::GetCameraSpeedFactor() * deltaTime;

	camera->GetPosition().x += cosf(camera->GetAngle() / RADIAN_OF_DEGREES) * factor;
	camera->GetPosition().z += sinf(camera->GetAngle() / RADIAN_OF_DEGREES) * factor;

	camera->UpdatePosition();
}

void Player::moveRight(float deltaTime)
{
	static PlayerCamera* camera = &PlayerCamera::GetInstance();
	const float factor = Misc::GetCameraSpeedFactor() * deltaTime;

	camera->GetPosition().x -= cosf(camera->GetAngle() / RADIAN_OF_DEGREES) * factor;
	camera->GetPosition().z -= sinf(camera->GetAngle() / RADIAN_OF_DEGREES) * factor;

	camera->UpdatePosition();
}