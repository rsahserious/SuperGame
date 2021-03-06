#pragma once

#include "PlayerCamera.h"
#include "Misc.h"

namespace PlayerAction
{
	enum
	{
		MOVE_FORWARD = 1,
		MOVE_BACKWARD = 2,
		MOVE_LEFT = 4,
		MOVE_RIGHT = 8,
		SPRINT = 16
	};
}

typedef unsigned long t_Action;

class Player
{
public:
	static Player& GetInstance()
	{
		static Player instance;
		return instance;
	}

	void ExecuteAction(const t_Action action, float deltaTime);

private:
	Player();

	void moveForward(float deltaTime);
	void moveBackward(float deltaTime);
	void moveLeft(float deltaTime);
	void moveRight(float deltaTime);
};