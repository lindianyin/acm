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
	int max_depth(TreeNode* root,int depth){
		if(!root)
			return depth-1;
		return max(max_depth(root->left,depth+1),max_depth(root->right,depth+1));
	}
	int maxDepth(TreeNode* root) {
		if(nullptr == root)
			return 0;
		return max_depth(root,1);	
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
	TreeNode* j = new TreeNode('j');
	
	f->left = b;
	b->left = a;
	b->right=d;
	d->left = c;
	d->right = e;
	f->right = g;
	g->right = i;
	i->left = h;
	h->right = j;
	auto result = s.maxDepth(f);
	dbg(result);
	return 0;
}
