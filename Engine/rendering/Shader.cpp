#include "Shader.h"

namespace Engine
{
	Shader::Shader(const string& vsFilePath, const string& fsFilePath)
	{
		GLchar errorBuffer[1024];

		this->program = glCreateProgram();

		this->vertexShader = create(load(vsFilePath), GL_VERTEX_SHADER);
		this->fragmentShader = create(load(fsFilePath), GL_FRAGMENT_SHADER);

		glAttachShader(this->program, this->vertexShader);
		glAttachShader(this->program, this->fragmentShader);

		glBindAttribLocation(this->program, 0, "position");
		glBindAttribLocation(this->program, 1, "UV");
		glBindAttribLocation(this->program, 2, "normal");

		glLinkProgram(this->program);
		if (this->getProgramError(GL_LINK_STATUS, sizeof errorBuffer, &errorBuffer[0]))
		{
			std::cerr << "Error: Linking shader program failed: " << errorBuffer << std::endl;
		}

		glValidateProgram(this->program);
		if (this->getProgramError(GL_VALIDATE_STATUS, sizeof errorBuffer, &errorBuffer[0]))
		{
			std::cerr << "Error: Linking shader program failed: " << errorBuffer << std::endl;
		}

		this->uniform[Uniforms::cameraTransform] = glGetUniformLocation(this->program, "cameraTransform");
		this->uniform[Uniforms::objectTransform] = glGetUniformLocation(this->program, "objectTransform");
	}

	Shader::~Shader()
	{
		glDetachShader(this->program, this->vertexShader);
		glDetachShader(this->program, this->fragmentShader);

		glDeleteShader(this->vertexShader);
		glDeleteShader(this->fragmentShader);

		glDeleteProgram(this->program);
	}

	void Shader::Bind()
	{
		glUseProgram(this->program);
	}

	void Shader::Unbind()
	{
		glUseProgram(0);
	}

	void Shader::Update(Transform& transform, Camera& camera)
	{
		glm::mat4 transformModel = transform.GetModel();
		glm::mat4 cameraTransformModel = camera.GetViewProjection() * transformModel;

		glUniformMatrix4fv(this->uniform[Uniforms::cameraTransform], 1, GL_FALSE, &cameraTransformModel[0][0]);
		glUniformMatrix4fv(this->uniform[Uniforms::objectTransform], 1, GL_FALSE, &transformModel[0][0]);

	}

	bool Shader::getProgramError(unsigned int flag, unsigned int bufferLength, GLchar* errorBuffer)
	{
		GLint success = 0;

		glGetProgramiv(this->program, flag, &success);

		if (success == GL_FALSE)
		{
			glGetProgramInfoLog(this->program, bufferLength, NULL, errorBuffer);
			return true;
		}

		return false;
	}

	bool Shader::getShaderError(GLuint shader, unsigned int flag, unsigned int bufferLength, GLchar* errorBuffer)
	{
		GLint success = 0;

		glGetShaderiv(shader, flag, &success);

		if (success == GL_FALSE)
		{
			glGetShaderInfoLog(shader, bufferLength, NULL, errorBuffer);
			return true;
		}

		return false;
	}

	string Shader::load(const string& filePath)
	{
		std::ifstream file;
		std::string output, line;

		file.open(filePath.c_str());

		if (file.is_open())
		{
			while (file.good())
			{
				getline(file, line);
				output.append(line + "\n");
			}
		}
		else
		{
			std::cerr << "Error: Unable to load shader from file \"" << filePath << "\"" << std::endl;
		}

		return output;
	}

	GLuint Shader::create(const string& source, unsigned int type)
	{
		GLchar errorBuffer[1024];

		GLuint shader = glCreateShader(type);

		if (shader == 0)
		{
			std::cerr << "Error: Creating shader of type " << type << " failed" << std::endl;
		}

		const GLchar* sourcePtr = source.c_str();
		glShaderSource(shader, 1, &sourcePtr, nullptr);
		glCompileShader(shader);

		if (getShaderError(shader, GL_COMPILE_STATUS, sizeof errorBuffer, &errorBuffer[0]))
		{
			std::cerr << "Error: Compiling shader failed: " << errorBuffer << std::endl;
		}

		return shader;
	}
}