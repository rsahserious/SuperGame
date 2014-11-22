#include "IOManager.h"

namespace Engine
{
	bool IOManager::ReadFile(const string& filePath, std::vector<unsigned char>& output)
	{
		std::cout << "Reading file \"" + filePath + "\" ... ";

		std::ifstream file(filePath, std::ios::binary);

		if (file.fail())
		{
			std::cout << "Error: Cannot open file \"" << filePath << "\"" << std::endl;
			return false;
		}

		file.seekg(0, std::ios::end);
		int length = file.tellg();

		// subtract length by header data that might be here
		file.seekg(0, std::ios::beg);
		length -= file.tellg();

		output.resize(length);
		file.read(reinterpret_cast<char*>(&output[0]), length);

		file.close();

		std::cout << "done" << std::endl;

		return true;
	}

	VertexModel* IOManager::ReadObjModel(const string& filePath)
	{
		std::cout << "Reading OBJ model \"" + filePath + "\" ... ";

		std::fstream file(filePath, std::ios::in);

		if (file.fail())
		{
			std::cerr << std::endl << "Error: Cannot open OBJ file \"" << filePath << "\"" << std::endl;
			return false;
		}

		vector<glm::vec3> in_vertices, out_vertices;
		vector<glm::vec2> in_textureUVs, out_textureUVs;
		vector<glm::vec3> in_normals, out_normals;
		vector<unsigned int> vertexIndices, uvIndices, normalIndices;

		string buffer;
		while (!file.eof())
		{
			static const unsigned short MAX_LINE_LENGTH = 128;

			std::getline(file, buffer);

			if (!buffer.length())
			{
				continue;
			}

			char lineHeader[MAX_LINE_LENGTH];
			sscanf_s(&buffer[0], "%s", lineHeader, sizeof(lineHeader));

			// vertex
			if (strcmp(lineHeader, "v") == 0)
			{
				glm::vec3 vertex;
				float test;
				sscanf_s(&buffer[0] + sizeof("v"), "%f %f %f", &vertex.x, &vertex.y, &vertex.z);
				in_vertices.push_back(vertex);
			}

			// texture UV
			else if (strcmp(lineHeader, "vt") == 0)
			{
				glm::vec2 uv;
				sscanf_s(&buffer[0] + sizeof("vt"), "%f %f", &uv.x, &uv.y);
				in_textureUVs.push_back(uv);
			}

			// normal vector
			else if (strcmp(lineHeader, "vn") == 0)
			{
				glm::vec3 normal;
				sscanf_s(&buffer[0] + sizeof("vn"), "%f %f %f", &normal.x, &normal.y, &normal.z);
				in_normals.push_back(normal);
			}

			// face
			else if (strcmp(lineHeader, "f") == 0)
			{
				unsigned int index[9];
				sscanf_s(&buffer[0] + sizeof("f"), "%d/%d/%d %d/%d/%d %d/%d/%d",
					&index[0], &index[1], &index[2],
					&index[3], &index[4], &index[5],
					&index[6], &index[7], &index[8]
				);

				vertexIndices.push_back(index[0] - 1);
				vertexIndices.push_back(index[3] - 1);
				vertexIndices.push_back(index[6] - 1);

				uvIndices.push_back(index[1] - 1);
				uvIndices.push_back(index[4] - 1);
				uvIndices.push_back(index[7] - 1);

				normalIndices.push_back(index[2] - 1);
				normalIndices.push_back(index[5] - 1);
				normalIndices.push_back(index[8] - 1);
			}
		}

		file.close();

		for (unsigned int i = 0; i < vertexIndices.size(); i++)
		{
			out_vertices.push_back(in_vertices[vertexIndices[i]]);
			out_textureUVs.push_back(in_textureUVs[uvIndices[i]]);
			out_normals.push_back(in_normals[normalIndices[i]]);
		}

		std::cout << "done" << std::endl;

		return new VertexModel(out_vertices, out_textureUVs, out_normals);
	}
}