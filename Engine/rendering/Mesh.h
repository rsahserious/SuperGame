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
		virtual ~Mesh();

		void Draw();

	protected:
		void init(VertexModel& model);

	private:
		unsigned int numVertices;
		GLuint vertexArrayObject;
		GLuint vertexArrayBuffers[VertexArray::_length];
	};
}