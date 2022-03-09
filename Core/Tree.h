#pragma once

#include <string>
#include <vector>
#include <memory>

namespace Engine {
	class TreeNode {
	public:
		TreeNode();
		TreeNode(const std::string& name, TreeNode* parent = nullptr);
		TreeNode(const TreeNode& src);
		virtual ~TreeNode();

	public:
		void setName(const std::string& name);
		std::string getName() const;

		const TreeNode* getChild(const std::string& name) const;
		TreeNode* getChild(const std::string& name);

		TreeNode* addChild(TreeNode* child);

		bool deleteChild(const std::string& name);

		bool hasChild(const std::string& name) const;

		virtual void apply() {};

	protected:
		TreeNode* m_parent = nullptr;

		std::string m_name;

		std::string m_identity;

		std::vector<TreeNode*> m_children;
	};
}

