#include "pch.h"

#include <vector>

#include "Mesh.h"

using namespace Engine;

std::shared_ptr<Mesh> Mesh::m_unitCubeMesh = nullptr;

std::shared_ptr<Mesh> Mesh::createUnitCubeMesh()
{
	// top bottom front back left right
	static float vertices[] = {
		0.5f, 0.5f, 0.5f,
		-0.5f, 0.5f, 0.5f,
		-0.5f, -0.5f, 0.5f,
		0.5f, -0.5f, 0.5f,

		0.5f, 0.5f, -0.5f,
		0.5f, -0.5f, -0.5f,
		-0.5f, -0.5f, -0.5f,
		-0.5f, 0.5f, -0.5f,

		0.5f, 0.5f, 0.5f,
		0.5f, 0.5f, -0.5f,
		-0.5f, 0.5f, -0.5f,
		-0.5f, 0.5f, 0.5f,

		0.5f, -0.5f, 0.5f,
		-0.5f, -0.5f, 0.5f,
		-0.5f, -0.5f, -0.5f,
		0.5f, -0.5f, -0.5f,

		-0.5f, -0.5f, 0.5f,
		-0.5f, 0.5f, 0.5f,
		-0.5f, 0.5f, -0.5f,
		-0.5f, -0.5f, -0.5f,

		0.5f, 0.5f, 0.5f,
		0.5f, -0.5f, 0.5f,
		0.5f, -0.5f, -0.5f,
		0.5f, 0.5f, -0.5f
	};

	static float normal[] = {
		0.0f, 0.0f, 1.0f,
		0.0f, 0.0f, 1.0f,
		0.0f, 0.0f, 1.0f,
		0.0f, 0.0f, 1.0f,

		0.0f, 0.0f, -1.0f,
		0.0f, 0.0f, -1.0f,
		0.0f, 0.0f, -1.0f,
		0.0f, 0.0f, -1.0f,

		0.0f, 1.0f, 0.0f,
		0.0f, 1.0f, 0.0f,
		0.0f, 1.0f, 0.0f,
		0.0f, 1.0f, 0.0f,

		0.0f, -1.0f, 0.0f,
		0.0f, -1.0f, 0.0f,
		0.0f, -1.0f, 0.0f,
		0.0f, -1.0f, 0.0f,

		-1.0f, 0.0f, 0.0f,
		-1.0f, 0.0f, 0.0f,
		-1.0f, 0.0f, 0.0f,
		-1.0f, 0.0f, 0.0f,

		1.0f, 0.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
	};

	static std::vector<unsigned int> indices = {
		0,  1,  2,  2,  3,  0,
		4,  5,  6,  6,  7,  4,
		8,  9,  10, 10, 11, 8,
		12, 13, 14, 14, 15, 12,
		16, 17, 18, 18, 19, 16,
		20, 21, 22, 22, 23, 20
	};

	static glm::vec2 texCoord[] = {
		{1,1},
		{0,1},
		{0,0},
		{1,0}
	};

	if (m_unitCubeMesh) return m_unitCubeMesh;

	m_unitCubeMesh->m_vertices.resize(24);
	for (size_t i = 0; i < m_unitCubeMesh->m_vertices.size(); ++i) {
		m_unitCubeMesh->m_vertices[i].position.set(vertices[i * 3], vertices[i * 3 + 1], vertices[i * 3 + 2]);
		m_unitCubeMesh->m_vertices[i].normal.set(normal[i * 3], normal[i * 3 + 1], normal[i * 3 + 2]);
	}

	m_unitCubeMesh->m_indices = indices;

	return m_unitCubeMesh;
}
Mesh* Mesh::createBoxMesh(float x, float y, float z)
{
	if (!m_unitCubeMesh) createUnitCubeMesh();
	Mesh* mesh = new Mesh(*m_unitCubeMesh);

	for (size_t i = 0; i < mesh->m_vertices.size(); ++i) {
		mesh->m_vertices[i].position.scaleSelf(x, y, z);
	}

	return mesh;
}

Mesh::Mesh(const Mesh& mesh)
{
	m_indices = mesh.m_indices;
	m_vertices = mesh.m_vertices;
}