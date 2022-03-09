#include "pch.h"

#include <glm/gtc/matrix_transform.hpp>

#include "Frustum.h"

using namespace Engine;

Frustum::Frustum()
{

}

Frustum::~Frustum()
{

}

glm::mat4 Frustum::updateMatrix()
{
	m_aspectRatio = m_width / (m_height <= 0.0f ? 1.0f : m_height);

	if(m_projectionType == ProjectType::ortho)
	{
		m_projectionMatrix = glm::ortho(m_width * -0.5f, m_width * 0.5f,
			m_height * -0.5f, m_height * 0.5f, m_nearDist, m_farDist);
	}
	else
	{
		m_projectionMatrix = glm::perspective(m_fov, m_aspectRatio, m_nearDist, m_farDist);
	}

	return m_projectionMatrix;
}

glm::mat4 Frustum::getMatrix()
{
	return m_projectionMatrix;
}