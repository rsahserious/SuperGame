#pragma once

#include <iostream>
#include <string>

#include <SDL\SDL.h>
#include <glew\glew.h>

using std::string;

namespace Engine
{
	class Window
	{
	public:
		Window();
		Window(const string& title, unsigned int width, unsigned int height, unsigned int flags = 0);
		~Window();

		void Clear(float red, float green, float blue, float alpha);
		void SwapBuffers();

	private:
		SDL_Window* sdlWindow;
		SDL_GLContext glContext;
	};
}