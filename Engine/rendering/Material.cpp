#include "Material.h"

namespace Engine
{
	Material::Material(const string& texturePath)
	{
		this->texture = new Texture(texturePath);
	}

	Material::~Material()
	{
		delete this->texture;
	}

	void Material::SetAnisotropyLevel(float level)
	{
		if (level < ENGINE_MIN_ANISO_LEVEL) level = ENGINE_MIN_ANISO_LEVEL;
		if (level > ENGINE_MAX_ANISO_LEVEL) level = ENGINE_MAX_ANISO_LEVEL;

		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAX_ANISOTROPY_EXT, level);
	}
}