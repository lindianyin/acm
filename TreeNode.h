#ifndef __TREE_NODE_H__
#define __TREE_NODE_H__
struct TreeNode {
	int val;
	TreeNode* left = nullptr;
	TreeNode* right = nullptr;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
#endif
