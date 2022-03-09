#pragma once

#include <string>
#include <vector>
#include <memory>

#include <glm/glm.hpp>

namespace Engine {
	
	/*
		SceneNode is a warper of ONLY ONE object that displayed in a scene
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
		SceneNode(const std::string& name) :m_name(name) {};
		virtual ~SceneNode();

		typedef std::vector<SceneNode*> nodeList;

	public:
		std::string getName() const;
		void bindObject(Object* object);

		void addSceneNode(SceneNode* node);
		void deleteSceneNode(SceneNode* node);

		virtual void display();		// display object and recursively display all children

	private:
		std::string m_name;
		glm::mat4 m_transform = glm::mat4(1.0f);

		Object* m_object = nullptr;
		
		SceneNode* m_parent;
		nodeList m_childern;
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

		Camera* getOrCreateCamera(const std::string& name);
		void attachCamera(Camera* camera);

		SceneNode* getOrCreateSceneNode(const std::string& name);
		void bindSceneNode(SceneNode* node);
		void bindSceneNode(const std::vector<SceneNode*>& nodes);

		void display() const;

	private:
		std::unique_ptr<Lighting> m_lighting;
		std::vector<std::shared_ptr<Camera>> m_cameras;
		std::vector<std::shared_ptr<SceneNode>> m_nodes;
	};
}