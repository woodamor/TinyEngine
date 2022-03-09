#include "pch.h"

#include <assert.h>

#include "Camera.h"
#include "Lighting.h"

#include "SceneManager.h"

using namespace Engine;

SceneNode::SceneNode()
{

}

SceneNode::~SceneNode()
{
	delete m_object;
	for (auto& node : m_childern) {
		delete node;
	}
}

std::string SceneNode::getName() const
{
	return m_name;
}

void SceneNode::bindObject(Object* object)
{
	if (!object || object == m_object) return;
	m_object = object;
}

void SceneNode::addSceneNode(SceneNode* node)
{
	assert(node != nullptr);
	m_childern.push_back(node);
}

void SceneNode::deleteSceneNode(SceneNode* node)
{

}

void SceneNode::display()
{

}

//////////////////////////////////////////////////////////////////////////
SceneManager::SceneManager()
{

}

SceneManager::~SceneManager()
{

}

Lighting* SceneManager::getOrCreateLighting()
{
	m_lighting.reset(new Lighting());
	return m_lighting.get();
}

Camera* SceneManager::getOrCreateCamera(const std::string& name)
{
	auto it = std::find_if(m_cameras.begin(), m_cameras.end(), 
		[&](const Camera& cam) {return cam.getName() == name; });
	if (it == m_cameras.end()) {
		std::shared_ptr<Camera> cam = std::make_shared<Camera>(new Camera(name));
		m_cameras.push_back(cam);
		return cam.get();
	}
	else {
		return (*it).get();
	}
}

void SceneManager::attachCamera(Camera* camera)
{
	std::shared_ptr<Camera> cam = std::make_shared<Camera>(new Camera(*camera));
	m_cameras.push_back(cam);
}

SceneNode* SceneManager::getOrCreateSceneNode(const std::string& name)
{
	auto it = std::find_if(m_nodes.begin(), m_nodes.end(),
		[&](const SceneNode& node) {return node.getName() == name; });
	if (it == m_nodes.end()) {
		std::shared_ptr<SceneNode> node = std::make_shared<SceneNode>(new SceneNode(name));
		m_nodes.push_back(node);
		return node.get();
	}
	else {
		return (*it).get();
	}
}

void SceneManager::bindSceneNode(SceneNode* node)
{
	std::shared_ptr<SceneNode> tmp_node = std::make_shared<SceneNode>(new SceneNode(*node));
	m_nodes.push_back(tmp_node);
}

void SceneManager::bindSceneNode(const std::vector<SceneNode*>& nodes)
{

}

void SceneManager::display() const
{

}