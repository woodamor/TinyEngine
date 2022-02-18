#pragma once


namespace Engine {

	typedef unsigned int GLenum;

	class Mesh;
	class Material;

	class Render
	{
	public:
		Render();
		Render(Mesh* mesh, Material* material) :m_mesh(mesh), m_material(material) {};
		virtual ~Render();

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