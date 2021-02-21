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
class Solution {
public:
	void inorder(TreeNode* node,vector<int>& result){
		if(node == nullptr)
			return;
		inorder(node->left,result);
		result.push_back(node->val);
		inorder(node->right,result);
	}
    vector<int> inorderTraversal(TreeNode* root) {
		vector<int> result;
		inorder(root,result);
		return result;
    }
};
int main(int argc,char* argv[]){
	Solution s;
	TreeNode* a = new TreeNode('a');
	TreeNode* b = new TreeNode('b');
	TreeNode* c = new TreeNode('c');
	TreeNode* d = new TreeNode('d');
	TreeNode* e = new TreeNode('e');
	TreeNode* f = new TreeNode('f');
	TreeNode* g = new TreeNode('g');
	TreeNode* h = new TreeNode('h');
	TreeNode* i = new TreeNode('i');
	
	f->left = b;
	b->left = a;
	b->right=d;
	d->left = c;
	d->right = e;
	f->right = g;
	g->right = i;
	i->left = h;
	vector<int> result = s.inorderTraversal(f);
	vector<char> out;
	for(auto item : result)
		out.push_back(item);
	dbg(out);
	return 0;
}
