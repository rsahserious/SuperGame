#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <glm\glm.hpp>
#include "..\core\VertexModel.h"

using std::string;
using std::vector;

namespace Engine
{
	class IOManager
	{
	public:
		static bool ReadFile(const string& filePath, vector<unsigned char>& output);
		static VertexModel* ReadObjModel(const string& filePath);
	};
}