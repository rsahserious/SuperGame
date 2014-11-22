#pragma once

#include <SDL\SDL.h>
#include <glm\glm.hpp>

namespace Engine
{
	class Utils
	{
	public:
		static float Utils::GetFPS()
		{
			static const unsigned char TIME_BUFFER_LENGTH = 50;

			int ticks = SDL_GetTicks();
			float fps = 0;

			static int ticks_old = ticks;
			static float samples[TIME_BUFFER_LENGTH];
			static unsigned char count = 0;

			float diff = ticks - ticks_old;

			if (diff > 0)
			{
				samples[count++] = 1000.0f / diff;
			}

			for (unsigned char i = 0; i < TIME_BUFFER_LENGTH; i++)
			{
				fps += samples[i];
			}

			fps /= TIME_BUFFER_LENGTH;

			if (count == TIME_BUFFER_LENGTH) count = 0;
			ticks_old = ticks;

			return fps;
		}

		static glm::vec3 Utils::project(const glm::vec3& u, const glm::vec3& v)
		{
			return v * (glm::dot(u, v) / glm::dot(v, v));
		}

		static inline float sign(glm::vec3& a, glm::vec3& b, glm::vec3& c)
		{
			return ((a.x - c.x) * (b.y - c.y)) - ((b.x - c.x) * (a.y - c.y));
		}
	};
}