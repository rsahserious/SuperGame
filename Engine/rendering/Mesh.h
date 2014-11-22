#pragma once

#include <glew\glew.h>
#include <glm\glm.hpp>
#include <vector>
#include "..\core\VertexModel.h"
#include "..\core\IOManager.h"

using std::string;
using std::vector;

namespace Engine
{
	namespace VertexArray
	{
		enum VertexArray
		{
			positions,
			texturePositions,
			normals,
			indices,

			_length
		};
	}

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