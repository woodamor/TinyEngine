#include "pch.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#ifdef DEBUG
#include <glm/gtx/string_cast.hpp>
#endif

#include "Material.h"
#include "Mesh.h"
#include "Render.h"

#include "Object.h"

using namespace Engine;



//////////////////////////////////////////////////////////////////////////
DrawableObject::DrawableObject()
{

}

DrawableObject::DrawableObject(const std::string& name, TreeNode* parent /*= nullptr*/) : 
	TreeNode(name, parent)
{

}

DrawableObject::~DrawableObject()
{

}

Material* DrawableObject::getOrCreateMaterial()
{
	if (!m_material) m_material.reset(new Material());
	return m_material.get();
}

Mesh* DrawableObject::getOrCreateMesh()
{
	if (!m_mesh) m_mesh.reset(new Mesh());
	return m_mesh.get();
}

Render* DrawableObject::getOrCreateRender()
{
	if (!m_render) m_render.reset(new Render());
	return m_render.get();
}

void Engine::DrawableObject::apply()
{
	m_render->bindMaterial(m_material.get());
	m_render->bindMesh(m_mesh.get());
	m_render->render();
}