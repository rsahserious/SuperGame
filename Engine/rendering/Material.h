#pragma once

#include <string>
#include "Texture.h"

using std::string;

namespace Engine
{
	class Material
	{
	public:
		Material();
		Material(const string& texturePath);
		~Material();

		inline Texture* GetTexture() { return this->texture; }

		void SetAnisotropyLevel(float level);

	private:
		Texture* texture;

		//Texture bumpMapTexture;
		//Texture specularMapTexture;
	};
}