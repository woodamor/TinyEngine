#include "pch.h"

#include <gl/GL.h>

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Camera.h"

using namespace Engine;

Camera::Camera()
{

}

Camera::Camera(const std::string& name) : SceneNode(name)
{

}

Camera::~Camera()
{

}

void Camera::setFrustum(const Frustum& frustum)
{
	m_frustum = frustum;
}

Frustum& Camera::getFrustum()
{
	return m_frustum;
}

void Camera::updateCamera(const Point& eye, const Point& focus, const Vector& upVec)
{
	m_eye = eye;
	m_center = focus;
	m_upVec = upVec;
}

glm::mat4 Camera::updateViewMatrix()
{
	m_viewMatrix = glm::lookAt(m_eye.getVec3(), m_center.getVec3(), m_upVec.getVec3());
	return m_viewMatrix;
}

glm::mat4 Camera::updateProjectionMatrix()
{
	return m_frustum.updateMatrix();
}

glm::mat4 Camera::getViewMatrix()
{
	return m_viewMatrix;
}

glm::mat4 Camera::getProjectionMatrix()
{
	return m_frustum.getMatrix();
}

void Camera::display()
{
	glMatrixMode(GL_MODELVIEW);
	glMultMatrixf(glm::value_ptr(m_viewMatrix));
}