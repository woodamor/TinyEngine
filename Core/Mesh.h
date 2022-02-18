#pragma once

#include <vector>
#include <memory>

#include "../LiteMathLib/Point.h"

namespace Engine
{
	// to simplify, one mesh has uniform color
	// use texture to achieve fancy effect instead setting color for each vertex
	struct Vertex
	{
		Point position;
		Vector normal;
		glm::vec2 uv;
	};

	class Mesh
	{
	public:
		Mesh() = default;
		Mesh(const Mesh& mesh);
		~Mesh() = default;

	static std::shared_ptr<Mesh> createUnitCubeMesh();
	static Mesh* createBoxMesh(float x, float y, float z); // user holds object

	public:
		std::vector<Vertex> m_vertices;
		std::vector<unsigned int> m_indices;

	private:
		static std::shared_ptr<Mesh> m_unitCubeMesh;
	};


}