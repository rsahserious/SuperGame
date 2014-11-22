#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <glew\glew.h>
#include <vector>
#include "..\core\Transform.h"
#include "Camera.h"

using std::string;

namespace Engine
{
	namespace Uniforms
	{
		enum Uniforms
		{
			cameraTransform,
			objectTransform,

			_length
		};
	}

	class Shader
	{
	public:
		Shader();
		Shader(const string& vsFilePath, const string& fsFilePath);
		~Shader();

		void Bind();
		void Unbind();
		void Update(Transform& transform, Camera& camera);

	private:
		string load(const string& filePath);
		GLuint create(const string& source, unsigned int type);
		bool getProgramError(unsigned int flag, unsigned int bufferLength, GLchar* errorBuffer);
		bool getShaderError(GLuint shader, unsigned int flag, unsigned int bufferLength, GLchar* errorBuffer);
	
		GLuint program;
		GLuint vertexShader;
		GLuint fragmentShader;
		GLuint uniform[Uniforms::_length];
	};
}