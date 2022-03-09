#pragma once

#include "SceneManager.h"
#include "LiteMathLib/Point.h"
#include "LiteMathLib/Frustum.h"

namespace Engine
{
	class Camera : public SceneNode {
	public:
		Camera();
		Camera(const std::string& name);
		virtual ~Camera();

		void setFrustum(const Frustum& frustum);
		Frustum& getFrustum();

		void updateCamera(const Point& eye, const Point& focus, const Vector& upVec);

		glm::mat4 updateViewMatrix();
		glm::mat4 updateProjectionMatrix();

		glm::mat4 getViewMatrix();
		glm::mat4 getProjectionMatrix();

		virtual void display() override;	// apply viewMatrix

	private:
		Frustum m_frustum;

		Point m_eye;
		Point m_center;
		Vector m_upVec;

		// cache matrix
		glm::mat4 m_viewMatrix = glm::mat4(1.0);
	};
}