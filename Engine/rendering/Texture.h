#pragma once

#include <glew\glew.h>
#include "..\core\IOManager.h"

#define ENGINE_MIN_ANISO_LEVEL 1.0f
#define ENGINE_MAX_ANISO_LEVEL 16.0f
#define ENGINE_DEFAULT_ANISO_LEVEL 16.0f

using std::string;

namespace Engine
{
	class Texture
	{
	public:
		Texture();
		Texture(const string& filePath);
		~Texture();

		void Bind();

	private:
		GLuint texture;
	};
}