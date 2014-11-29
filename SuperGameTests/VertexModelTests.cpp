#include "stdafx.h"
#include "CppUnitTest.h"
#include <Engine\core\VertexModel.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SuperGameTests
{		
	TEST_CLASS(VertexModelTests)
	{
	private:
		Engine::VertexModel* vertexModel = nullptr;

	public:
		VertexModelTests()
		{
			vector<glm::vec3> vertices;
			vector<glm::vec2> uvs;
			vector<glm::vec3> normals;

			vertices.push_back(glm::vec3(1, 2, 3));
			vertices.push_back(glm::vec3(-1, -2, -3));
			vertices.push_back(glm::vec3(0, 1, -1));

			uvs.push_back(glm::vec2(0, 0));
			uvs.push_back(glm::vec2(1, 1));
			uvs.push_back(glm::vec2(-1, -1));
			uvs.push_back(glm::vec2(0, -1));

			normals.push_back(glm::vec3(1, 2, 3));
			normals.push_back(glm::vec3(-1, -2, -3));

			this->vertexModel = new Engine::VertexModel(vertices, uvs, normals);
		}

		~VertexModelTests()
		{
			delete this->vertexModel;
		}

		TEST_METHOD(ShouldHaveCorrectLengthsOfMembers)
		{
			int verticesNum = this->vertexModel->GetVertices().size();
			int uvsNum = this->vertexModel->GetUVs().size();
			int normalsNum = this->vertexModel->GetNormals().size();

			Assert::AreEqual(verticesNum, 3);
			Assert::AreEqual(uvsNum, 4);
			Assert::AreEqual(normalsNum, 2);
		}

		TEST_METHOD(ShouldReturnCorrectVerticesCount)
		{
			unsigned int verticesCount = this->vertexModel->GetVerticesCount();

			Assert::AreEqual(verticesCount, (unsigned int)3);
		}
	};
}