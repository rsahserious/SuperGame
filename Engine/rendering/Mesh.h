#pragma once

#include <glew\glew.h>
#include <glm\glm.hpp>
#include <vector>
#include "..\core\VertexModel.h"
#include "..\core\IOManager.h"
#include "..\core\VertexArray.h"

using std::string;
using std::vector;

namespace Engine
{
	class Mesh
	{
	public:
		Mesh();
		Mesh(VertexModel& model);
		Mesh(const string& filePath);
		~Mesh();

		void Draw();

	private:
		void init(VertexModel& model);

		unsigned int numVertices;
		GLuint vertexArrayObject;
		GLuint vertexArrayBuffers[VertexArray::_length];
	};
}