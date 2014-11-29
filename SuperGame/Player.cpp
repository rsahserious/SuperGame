#include "Player.h"

Player::Player()
{

}

void Player::ExecuteAction(const t_Action action)
{
	switch (action)
	{
	case PlayerAction::MOVE_FORWARD:	this->moveForward();	break;
	case PlayerAction::MOVE_BACKWARD:	this->moveBackward();	break;
	case PlayerAction::MOVE_LEFT:		this->moveLeft();		break;
	case PlayerAction::MOVE_RIGHT:		this->moveRight();		break;
	}
}

void Player::moveForward()
{
	static PlayerCamera* camera = &PlayerCamera::GetInstance();
	const float factor = Misc::GetCameraSpeedFactor();
	const float horizontalFactor = factor * (1.0f - abs(camera->GetTilt()));

	camera->GetPosition().x += sinf(-camera->GetAngle() / RADIAN_OF_DEGREES) * horizontalFactor;
	camera->GetPosition().z += cosf(-camera->GetAngle() / RADIAN_OF_DEGREES) * horizontalFactor;

	camera->GetPosition().y += camera->GetTilt() * factor;

	camera->UpdatePosition();
}

void Player::moveBackward()
{
	static PlayerCamera* camera = &PlayerCamera::GetInstance();
	const float factor = Misc::GetCameraSpeedFactor();
	const float horizontalFactor = factor * (1.0f - abs(camera->GetTilt()));

	camera->GetPosition().x -= sinf(-camera->GetAngle() / RADIAN_OF_DEGREES) * horizontalFactor;
	camera->GetPosition().z -= cosf(-camera->GetAngle() / RADIAN_OF_DEGREES) * horizontalFactor;
	camera->GetPosition().y += -camera->GetTilt() * factor;

	camera->UpdatePosition();
}

void Player::moveLeft()
{
	static PlayerCamera* camera = &PlayerCamera::GetInstance();
	const float factor = Misc::GetCameraSpeedFactor();

	camera->GetPosition().x += cosf(camera->GetAngle() / RADIAN_OF_DEGREES) * factor;
	camera->GetPosition().z += sinf(camera->GetAngle() / RADIAN_OF_DEGREES) * factor;

	camera->UpdatePosition();
}

void Player::moveRight()
{
	static PlayerCamera* camera = &PlayerCamera::GetInstance();
	const float factor = Misc::GetCameraSpeedFactor();

	camera->GetPosition().x -= cosf(camera->GetAngle() / RADIAN_OF_DEGREES) * factor;
	camera->GetPosition().z -= sinf(camera->GetAngle() / RADIAN_OF_DEGREES) * factor;

	camera->UpdatePosition();
}