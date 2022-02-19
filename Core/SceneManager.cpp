#include "pch.h"

#include "Camera.h"
#include "Lighting.h"

#include "SceneManager.h"

using namespace Engine;

SceneNode::SceneNode()
{

}

SceneNode::~SceneNode()
{

}

void SceneNode::bindObject(Object* object)
{

}

Object* SceneNode::createObject()
{

}

void SceneNode::addSceneNode(SceneNode* node)
{

}

void SceneNode::deleteSceneNode(SceneNode* node)
{

}

void SceneNode::display() const
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

}

Camera* SceneManager::getOrCreateMainCamera()
{

}

void SceneManager::attachCamera(Camera* camera)
{

}

SceneNode* SceneManager::getOrCreateSceneNode()
{

}

void SceneManager::bindSceneNode(SceneNode* node)
{

}

void SceneManager::bindSceneNode(const std::vector<SceneNode*>& nodes)
{

}

void SceneManager::display() const
{

}