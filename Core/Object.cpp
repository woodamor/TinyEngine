#include "pch.h"

#include <gl/GL.h>

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

Object::Object()
{

}

Object::~Object()
{
	for (auto& x : m_children)
	{
		delete x;
	}
}

Object* Object::createChild()
{
	Object* obj = new Object();
	m_children.push_back(obj);
	return obj;
}

Object* Object::attachChild(Object* object)
{
	m_children.push_back(object);

	return object;
}

inline void Object::setTransformMatrix(const glm::mat4& mat)
{
	m_transform = mat;
}

inline glm::mat4 Object::getTransformMatrix() const
{
	return m_transform;
}

void Object::apply()
{
	glPushMatrix();

	glMatrixMode(GL_MODELVIEW);
	glMultMatrixf(glm::value_ptr(m_transform));

	draw();

	for (auto& child : m_children)
	{
		if(!child) continue;
		child->apply();
	}

	glPopMatrix();
}

void Engine::Object::draw() const
{

}

void Object::translate(float x /*= 0.0*/, float y /*= 0.0*/, float z /*= 0.0*/)
{
	m_transform = glm::translate(m_transform, glm::vec3(x, y, z));
}

void Object::translate(const Vector& point)
{

}

void Object::rotate(const Vector& axis, float angle)
{
	m_transform = glm::rotate(m_transform, angle, axis.getVec3());
}

void Engine::Object::scale(float x /*= 1.0*/, float y /*= 1.0*/, float z /*= 1.0*/)
{
	m_transform = glm::scale(m_transform, glm::vec3(x, y, z));
}


//////////////////////////////////////////////////////////////////////////
DrawableObject::DrawableObject()
{

}

DrawableObject::DrawableObject(const std::string& name) : Object(name)
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

void Engine::DrawableObject::draw() const
{
	m_render->bindMaterial(m_material.get());
	m_render->bindMesh(m_mesh.get());
	m_render->render();
}