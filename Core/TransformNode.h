#pragma once

#include <glm/glm.hpp>

#include "LiteMathLib/Point.h"

#include "Tree.h"

namespace Engine {

	/*
		MovableObject: camera, light
	*/
	class TransformNode : public TreeNode
	{
	public:
		TransformNode(const std::string& name, TreeNode* parent = nullptr);
		virtual ~TransformNode();

	public:
		void setTransformMatrix(const glm::mat4& mat);
		glm::mat4 getTransformMatrix() const;

		void apply() override;
		virtual void draw(); // send GL draw calls

		void translate(float x = 0.0, float y = 0.0, float z = 0.0);
		void translate(const Vector& point);
		void rotate(const Vector& axis, float angle);
		void scale(float x = 1.0, float y = 1.0, float z = 1.0);

	protected:
		glm::mat4 m_transform = glm::mat4(1.0f);		// geometric relationship relative to parent object
	};
}