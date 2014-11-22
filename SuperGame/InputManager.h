#pragma once

#include <map>
#include <unordered_map>
#include <SDL\SDL.h>
#include "Player.h"

class InputManager
{
public:
	static InputManager& GetInstance()
	{
		static InputManager instance;
		return instance;
	}

	void UpdateKey(const SDL_Keycode keyCode, bool state);
	bool IsKeyDown(const SDL_Keycode keyCode);

private:
	InputManager();

	std::unordered_map<SDL_Keycode, bool> keyStates;
};

