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
#include "TreeNode.h"
using namespace std;
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
class Solution{
public:
	void maxd(Node* root,int depth){
		if(nullptr == root){
			m = max(m,depth-1);
			return;
		}
		if(root->children.empty()){
			m = max(m,depth);
			return;
		}
		for(auto item : root->children){
			maxd(item,depth+1);
		}	
	}
	int maxDepth(Node* root) {
		maxd(root,1);
		return m;
	}
	int m = 0;
};
int main(int argc,char* argv[]){
	Solution s;
	Node* one = new Node(1);
	Node* two = new Node(2);
	Node* three = new Node(3);
	Node* four = new Node(4);
	Node* five = new Node(5);
	Node* six = new Node(6);
	one->children = {three,two,four};
	three->children={five,six};
	dbg(s.maxDepth(one));
	return 0;
}
