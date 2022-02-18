#pragma once

#include <gl/GL.h>

namespace Engine {

	class Mesh;
	class Material;

	class Render
	{
	public:
		Render() = default;
		Render(Mesh* mesh, Material* material) :m_mesh(mesh), m_material(material) {};
		virtual ~Render() = default;

		void setDrawType(GLenum drawType);

		void render();	// apply GL draw calls
		void bindMesh(Mesh* mesh);
		void bindMaterial(Material* material);

	private:
		GLenum m_drawType;
		Mesh* m_mesh = nullptr;
		Material* m_material = nullptr;
	};
}