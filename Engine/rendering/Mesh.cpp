#include "Mesh.h"

namespace Engine
{
	Mesh::Mesh(VertexModel& model)
	{
		this->init(model);
	}

	Mesh::Mesh(const string& filePath)
	{
		VertexModel* model = IOManager::ReadObjModel(filePath);

		this->init(*model);
	}

	Mesh::~Mesh()
	{
		glDeleteBuffers(VertexArray::_length, this->vertexArrayBuffers);
		glDeleteVertexArrays(1, &this->vertexArrayObject);
	}

	void Mesh::init(VertexModel& model)
	{
		this->numVertices = model.GetVerticesCount();

		glGenVertexArrays(1, &this->vertexArrayObject);
		glBindVertexArray(this->vertexArrayObject);

		glGenBuffers(VertexArray::_length, this->vertexArrayBuffers);

		// position
		glBindBuffer(GL_ARRAY_BUFFER, this->vertexArrayBuffers[VertexArray::positions]);
		glBufferData(GL_ARRAY_BUFFER, 
			model.GetVertices().size() * sizeof(model.GetVertices()[0]), &model.GetVertices()[0], GL_STATIC_DRAW);

		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

		// texture UV
		glBindBuffer(GL_ARRAY_BUFFER, this->vertexArrayBuffers[VertexArray::texturePositions]);
		glBufferData(GL_ARRAY_BUFFER, 
			model.GetUVs().size() * sizeof(model.GetUVs()[0]), &model.GetUVs()[0], GL_STATIC_DRAW);

		glEnableVertexAttribArray(1);
		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, 0);

		// normals
		glBindBuffer(GL_ARRAY_BUFFER, this->vertexArrayBuffers[VertexArray::normals]);
		glBufferData(GL_ARRAY_BUFFER,
			model.GetNormals().size() * sizeof(model.GetNormals()[0]), &model.GetNormals()[0], GL_STATIC_DRAW);

		glEnableVertexAttribArray(2);
		glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 0, 0);
	}

	void Mesh::Draw()
	{
		glBindVertexArray(this->vertexArrayObject);

		glDrawArrays(GL_TRIANGLES, 0, this->numVertices);

		glBindVertexArray(0);
	}
}