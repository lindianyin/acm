#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <limits>
#include "dbg-macro/dbg.h"
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
	void inorder(TreeNode* root,vector<int>& path){
		if(root == NULL)
			return;
		inorder(root->left,path);
		path.push_back(root->val);
		inorder(root->right,path);
	}
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> path;
		inorder(root,path);
		return path;
	}
};

int main(int argc,char* argv[]){
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->left = new TreeNode(4);
	root->left->right = new TreeNode(5);
	root->right->left = new TreeNode(6);
	root->right->right = new TreeNode(7);	
	Solution s;
	vector<int> path;
	dbg(s.inorderTraversal(root));
	return 0;
}
