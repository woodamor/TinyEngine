#pragma once

#include <glm/glm.hpp>

namespace Engine {
	class Frustum {
	public:
		Frustum();
		~Frustum();

		enum class ProjectType {
			ortho,
			perspective
		};

	public:
		glm::mat4 updateMatrix();

		glm::mat4 getMatrix();

	public:
		ProjectType m_projectionType = ProjectType::perspective;

		float m_fov = 45.0f;
		float m_farDist = 10000.0f;
		float m_nearDist = 0.1f;
		float m_height = 400.0f;
		float m_width = 400.0f;

	private:
		float m_aspectRatio = 1.0f; // width/height
		glm::mat4 m_projectionMatrix = glm::mat4(1.0f);
	};
}