#include <iostream>
#include <string>
#include <vector>
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
class Solution{
public:
	vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
		if(nullptr == root)
			return {};
		vector<TreeNode*> result;
		unordered_map<string,int> cnt;
		serialize(root,result,cnt);
		return result;	
	}
	string serialize(TreeNode* root,vector<TreeNode*>& result,unordered_map<string,int>& cnt){
		if(nullptr == root)
			return "#";
		string key = to_string(root->val) + "," + serialize(root->left,result,cnt) + "," + serialize(root->right,result,cnt);
		dbg(key);
		if(2 == ++cnt[key])
			result.push_back(root);
		return key;
	}	

};
std::ostream& operator<<(std::ostream& out, TreeNode* v) {
	if(nullptr == v)
		out << "null";
	else
		out << v->val;
  	return out;
}

int main(int argc,char* argv[]){
/*
        1
       / \
      2   3
     /   / \
    4   2   4
       /
      4
	TreeNode* root = new TreeNode(1);	
	root->left = new TreeNode(2);
	root->left->left = new TreeNode(4);
	root->right = new TreeNode(3);
	root->right->left = new TreeNode(2);
	root->right->left->left = new TreeNode(4);
	root->right->right = new TreeNode(4);
*/
/*
        1
       / \
      2   3
     /   / \
    4   5   6
       /
      7
*/
	TreeNode* root = new TreeNode(1);	
	root->left = new TreeNode(2);
	root->left->left = new TreeNode(4);
	root->right = new TreeNode(3);
	root->right->left = new TreeNode(5);
	root->right->left->left = new TreeNode(7);
	root->right->right = new TreeNode(6);
	
	Solution s;
	dbg(s.findDuplicateSubtrees(root));
	return 0;
}
