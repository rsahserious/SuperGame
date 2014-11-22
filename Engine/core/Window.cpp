#include "Window.h"

namespace Engine
{
	Window::Window(const string& title, unsigned int width, unsigned int height, unsigned int flags)
	{
		// Init SDL
		SDL_Init(SDL_INIT_EVERYTHING);

		// Set attributes
		SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
		SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
		SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
		SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
		SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 28);

		SDL_ShowCursor(SDL_DISABLE);
		SDL_SetRelativeMouseMode(SDL_TRUE);

		// Create main window
		this->sdlWindow = SDL_CreateWindow(
			title.c_str(),
			SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED,
			width,
			height,
			SDL_WINDOW_OPENGL | flags
		);

		// Create OpenGL context
		SDL_GL_CreateContext(this->sdlWindow);

		// Init GLEW
		GLenum res = glewInit();
		if (res != GLEW_OK)
		{
			std::cerr << "Error: GLEW failed to initialize" << std::endl;
		}

		// Enable back-face culling
		glEnable(GL_CULL_FACE);
		glCullFace(GL_BACK);

		// Enable depth test
		glEnable(GL_DEPTH_TEST);
	}

	Window::~Window()
	{
		SDL_GL_DeleteContext(this->glContext);
		SDL_DestroyWindow(this->sdlWindow);
		SDL_Quit();
	}

	void Window::Clear(float red, float green, float blue, float alpha)
	{
		glClearColor(red, green, blue, alpha);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	void Window::SwapBuffers()
	{
		SDL_GL_SwapWindow(this->sdlWindow);
	}
}