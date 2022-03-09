#include "pch.h"


#include "Tree.h"

namespace Engine {


Engine::TreeNode::TreeNode()
{

}

Engine::TreeNode::~TreeNode()
{

}

inline void Engine::TreeNode::setName(const std::string& name)
{
	m_name = name;
}

inline std::string Engine::TreeNode::getName() const
{
	return m_name;
}

Engine::TreeNode* Engine::TreeNode::addChild(TreeNode* child)
{
	m_children.push_back(child);
	return child;
}

bool Engine::TreeNode::deleteChild(const std::string& name)
{
	TreeNode* node = getChild(name);
	if (!node) return false;

	// todo

	return true;
}

bool Engine::TreeNode::hasChild(const std::string& name) const
{
	const TreeNode* node = getChild(name);
	return node != nullptr;
}

Engine::TreeNode::TreeNode(const TreeNode& src)
{

}

Engine::TreeNode::TreeNode(const std::string& name, TreeNode* parent /*= nullptr*/):
	m_name(name), m_parent(parent)
{
	
}

const Engine::TreeNode* TreeNode::getChild(const std::string& name) const
{
	const auto it = std::find_if(m_children.begin(), m_children.end(),
		[&](const TreeNode* elem) {return elem->getName() == name; });
	if (it != m_children.end()) {
		return *it;
	}
	return nullptr;
}

Engine::TreeNode* TreeNode::getChild(const std::string& name)
{
	TreeNode* thisNode = const_cast<TreeNode*>(this);

	const TreeNode* node = thisNode->getChild(name);
	return const_cast<TreeNode*>(node);
}

}
