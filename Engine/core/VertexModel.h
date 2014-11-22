#pragma once

#include <glew\glew.h>
#include <vector>
#include <glm\glm.hpp>

using std::vector;

namespace Engine
{
	class VertexModel
	{
	public:
		VertexModel();
		VertexModel(const vector<glm::vec3>& vertices,
			const vector<glm::vec2>& UVs,
			const vector<glm::vec3>& normals)
		{
			this->vertices = vertices;
			this->UVs = UVs;
			this->normals = normals;
		}

		inline unsigned int GetVerticesCount() { return this->vertices.size(); }

		inline vector<glm::vec3>& GetVertices() { return this->vertices; }
		inline vector<glm::vec2>& GetUVs() { return this->UVs; }
		inline vector<glm::vec3>& GetNormals() { return this->normals; }

	private:
		vector<glm::vec3> vertices;
		vector<glm::vec2> UVs;
		vector<glm::vec3> normals;
	};
}