#include "InputManager.h"

InputManager::InputManager()
{

}

void InputManager::UpdateKey(const SDL_Keycode keyCode, bool state)
{
	this->keyStates[keyCode] = state;
}

bool InputManager::IsKeyDown(const SDL_Keycode keyCode)
{
	std::unordered_map<SDL_Keycode, bool>::iterator iterator = keyStates.find(keyCode);

	if (iterator == this->keyStates.end())
	{
		return false;
	}

	return iterator->second;
}