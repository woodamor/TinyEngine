#include "pch.h"

#include "Mesh.h"
#include "Material.h"

#include "Render.h"

using namespace Engine;

void Render::setDrawType(GLenum drawType)
{
	m_drawType = drawType;
}

void Render::render()
{
	if (!m_mesh || !m_mesh->isValid()) return;
	
	if (m_material) m_material->apply();

	glVertexPointer(3, GL_FLOAT, sizeof(Vertex), &(m_mesh->m_vertices.data()[0].position));
	glEnableClientState(GL_VERTEX_ARRAY);

	glNormalPointer(GL_FLOAT, sizeof(Vertex), &(m_mesh->m_vertices.data()[0].normal));
	glEnableClientState(GL_NORMAL_ARRAY);


	glDrawElements(GL_TRIANGLES, m_mesh->m_indices.size(), GL_UNSIGNED_INT, m_mesh->m_indices.data());

	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_NORMAL_ARRAY);

	if (m_material) m_material->restore();
}

void Render::bindMesh(Mesh* mesh)
{
	m_mesh = mesh;
}

void Render::bindMaterial(Material* material)
{
	m_material = material;
}