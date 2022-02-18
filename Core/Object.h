#pragma once

#include <string>
#include <vector>
#include <memory>

#include <glm/glm.hpp>

#include "../LiteMathLib/Point.h"

namespace Engine {

	/*
		Base class of all the objects in graphic scene: drawable object, camera, light source etc.
	*/

	class Object
	{
	public:
		Object();
		Object(const std::string& name) :m_name(name) {};
		virtual ~Object();	// base dtor will recursively delete its children

	public:
		Object* createChild();
		Object* attachChild(Object* object); // if object already exits, return nullptr

	public:
		void setTransformMatrix(const glm::mat4& mat);
		glm::mat4 getTransformMatrix() const;

		void apply();		 // object is going to do something with draw()
		virtual void draw(); // send GL draw calls

		void translate(float x = 0.0, float y = 0.0, float z = 0.0);
		void translate(const Vector& point);
		void rotate(const Vector& axis, float angle);
		void scale(float x = 1.0, float y = 1.0, float z = 1.0);

	protected:
		std::string m_name;
		std::vector<Object*> m_children;

		glm::mat4 m_transform = glm::mat4(1.0f);
	};


	/*
		any drawable object: entity with geomtry and material
	*/
	class Render;
	class Mesh;
	class Material;

	class DrawableObject : public Object
	{
	public:
		DrawableObject();
		DrawableObject(const std::string& name);
		~DrawableObject();

		virtual Material* getOrCreateMaterial();
		virtual Mesh* getOrCreateMesh();
		virtual Render* getOrCreateRender();

		void draw() override;

	private:
		bool m_isVisible = true;
		bool m_isInScene = true;

		std::shared_ptr<Render> m_render;
		std::shared_ptr<Mesh> m_mesh;
		std::shared_ptr<Material> m_material;
	};
}