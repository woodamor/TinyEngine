#pragma once

#include "Tree.h"

namespace Engine {

	/*
		any drawable object: entity with geomtry and material
	*/
	class Render;
	class Mesh;
	class Material;

	class DrawableObject : public TreeNode
	{
	public:
		DrawableObject();
		DrawableObject(const std::string& name, TreeNode* parent = nullptr);
		virtual ~DrawableObject();

		virtual Material* getOrCreateMaterial();
		virtual Mesh* getOrCreateMesh();
		virtual Render* getOrCreateRender();

		void apply() override;

	private:
		bool m_isVisible = true;
		bool m_isInScene = true;

		std::shared_ptr<Render> m_render;
		std::shared_ptr<Mesh> m_mesh;
		std::shared_ptr<Material> m_material;
	};


}