#pragma once

#include <iostream>
#include <SDL\SDL.h>
#include "Constants.h"
#include "InputManager.h"

class Misc
{
public:
	Misc();
	~Misc();

	static float GetCameraSpeedFactor();
};

