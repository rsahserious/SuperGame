#include <picopng\picopng.hpp>
#include "Texture.h"

namespace Engine
{
	Texture::Texture(const string& filePath)
	{
		vector<unsigned char> fileStream, imageStream;
		unsigned long width, height;

		Engine::IOManager::ReadFile(filePath, fileStream);

		if (int error = decodePNG(imageStream, width, height, &fileStream[0], fileStream.size(), true))
		{
			std::cout << "Error: Unable to decode PNG image (" << error << ")" << std::endl;
		}

		glGenTextures(1, &this->texture);

		glBindTexture(GL_TEXTURE_2D, this->texture);

		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, &imageStream[0]);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAX_ANISOTROPY_EXT, ENGINE_DEFAULT_ANISO_LEVEL);

		glGenerateMipmap(GL_TEXTURE_2D);
	}

	Texture::~Texture()
	{
		glDeleteTextures(1, &this->texture);
	}

	void Texture::Bind()
	{
		glBindTexture(GL_TEXTURE_2D, this->texture);
	}
}