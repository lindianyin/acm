#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
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
	bool dfs(TreeNode* left,TreeNode* right){
		if(!left && !right)
			return true;
		if(!left || !right)
			return false;
		if(left->val != right->val)
			return false;
		return dfs(left->left,right->right) && dfs(left->right,right->left);
	}	
	bool isSymmetric(TreeNode* root) {
		if(!root)
			return true;
		return dfs(root->left,root->right);
	}
};
int main(int argc,char* argv[]){
	Solution s;
	TreeNode* a = new TreeNode('a');
	TreeNode* b = new TreeNode('b');
	TreeNode* b1 = new TreeNode('b');
	TreeNode* c = new TreeNode('c');
	TreeNode* c1 = new TreeNode('c');
	a->left = b;
	a->right = b1;
	b->left = c;
	b1->left = c1;
	auto result = s.isSymmetric(a);
	dbg(result);
	return 0;
}
