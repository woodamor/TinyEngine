#include "pch.h"

#include "TransformNode.h"

namespace Engine {
	//////////////////////////////////////////////////////////////////////////
	TransformNode::TransformNode(const std::string& name, TreeNode* parent /*= nullptr*/) :
		TreeNode(name, parent)
	{

	}

	TransformNode::~TransformNode()
	{

	}

	void TransformNode::apply()
	{
		glPushMatrix();

		glMatrixMode(GL_MODELVIEW);
		glMultMatrixf(glm::value_ptr(m_transform));

		draw();

		for (auto& child : m_children)
		{
			if (!child) continue;
			child->apply();
		}

		glPopMatrix();
	}

	void TransformNode::draw()
	{

	}

	inline void TransformNode::setTransformMatrix(const glm::mat4& mat)
	{
		m_transform = mat;
	}

	inline glm::mat4 TransformNode::getTransformMatrix() const
	{
		return m_transform;
	}

	void TransformNode::translate(float x /*= 0.0*/, float y /*= 0.0*/, float z /*= 0.0*/)
	{
		m_transform = glm::translate(m_transform, glm::vec3(x, y, z));
	}

	void TransformNode::translate(const Vector& point)
	{

	}

	void TransformNode::rotate(const Vector& axis, float angle)
	{
		m_transform = glm::rotate(m_transform, angle, axis.getVec3());
	}

	void TransformNode::scale(float x /*= 1.0*/, float y /*= 1.0*/, float z /*= 1.0*/)
	{
		m_transform = glm::scale(m_transform, glm::vec3(x, y, z));
	}

}