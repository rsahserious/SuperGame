#pragma once

#include "Mesh.h"

namespace Engine
{
	class DynamicMesh : public Mesh
	{
	public:
		DynamicMesh() : Mesh() { }
		DynamicMesh(VertexModel& model) : Mesh(model) { }
		DynamicMesh(const string& filePath) : Mesh(filePath) { }

		void Update(VertexModel& model);
	
	private:
		
	};
}