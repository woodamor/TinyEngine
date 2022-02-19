#pragma once

#include <vector>
#include <memory>

#include <glm/glm.hpp>

namespace Engine {
	
	/*
		SceneNode is a warper of one object that displayed in a scene
		Ways to organize SceneNodes varies in different scenarios.
		For example, one may use octree and frustum culling to handle a 3D scene 
		with a large amount of drawable objects

		While SceneNode hierarchy manages how objects are organized, the Object hierarchy only 
		represents the geometric relationship of objects
	*/

	class Object;

	class SceneNode {
	public:
		SceneNode();
		virtual ~SceneNode();

	public:
		void bindObject(Object* object);
		Object* createObject();

		void addSceneNode(SceneNode* node);
		void deleteSceneNode(SceneNode* node);

		virtual void display() const;		// display object and recursively display all children

	private:
		glm::mat4 m_transform = glm::mat4(1.0f);

		std::shared_ptr<Object> m_object;
		std::vector<SceneNode*> m_childern;
	};

	class Camera;
	class Lighting;
	/*
		SceneManager manages:
		1. organization of SceneNodes
		2. setting of cameras with viewports, frustum
		3. setting of lightings
		4. culling techniques
		5. global GL settings
		6. user interaction
		7. ......
	*/

	class SceneManager {
	public:
		SceneManager();
		virtual ~SceneManager();

	public:
		Lighting* getOrCreateLighting();

		Camera* getOrCreateMainCamera();
		void attachCamera(Camera* camera);

		SceneNode* getOrCreateSceneNode();
		void bindSceneNode(SceneNode* node);
		void bindSceneNode(const std::vector<SceneNode*>& nodes);

		void display() const;

	private:
		std::unique_ptr<Lighting> m_lighting;
		std::vector<std::shared_ptr<Camera>> m_cameras;
		std::vector<std::shared_ptr<SceneNode>> m_nodes;
	};
}