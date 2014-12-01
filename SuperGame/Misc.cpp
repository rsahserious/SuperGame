#include "Misc.h"

float Misc::GetCameraSpeedFactor()
{
	static InputManager* input = &InputManager::GetInstance();

	float factor = Constants::CAMERA_SPEED;

	bool leftRight = input->IsKeyDown(SDLK_a) || input->IsKeyDown(SDLK_d);
	if ((input->IsKeyDown(SDLK_w) && leftRight) || (input->IsKeyDown(SDLK_s) && leftRight))
	{
		static const float HALF_SPEED_FACTOR = 3.1416f / 4.0f;
		factor *= HALF_SPEED_FACTOR;
	}

	if (input->IsKeyDown(SDLK_CAPSLOCK) || input->IsKeyDown(SDLK_LSHIFT))
	{
		factor *= Constants::CAMERA_SPRINT_BOOST;
	}

	return factor;
}