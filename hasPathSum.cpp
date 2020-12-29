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
	bool hasPathSum(TreeNode* root, int sum) {
		if(!root)
			return false;
		if(!root->left && !root->right)
			return sum == root->val;
		return hasPathSum(root->left,sum-root->val) || hasPathSum(root->right,sum-root->val);
	}
};
int main(int argc,char* argv[]){
	Solution s;
	TreeNode* a = new TreeNode(1);
	TreeNode* b = new TreeNode(2);
	TreeNode* b1 = new TreeNode(3);
	a->left = b;
	a->right = b1;
	auto result = s.hasPathSum(a,5);
	dbg(result);
	return 0;
}
