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
#include <queue>
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
	void pre_order(Node* root,vector<int>& res){
		if(!root) return;
		res.push_back(root->val);
		for(size_t i = 0;i<root->children.size();i++){
			pre_order(root->children[i],res);	
		}
	}
	void post_order(Node* root,vector<int>& res){
		if(!root) return;
		for(size_t i = 0;i<root->children.size();i++){
			post_order(root->children[i],res);	
		}
		res.push_back(root->val);
	}
	vector<int> preorder(Node* root){	
		vector<int> res;
		pre_order(root,res);
		return res;	
	}	
	vector<int> postorder(Node* root){	
		vector<int> res;
		post_order(root,res);
		return res;	
	}	
	
    	vector<vector<int>> levelOrder(Node* root) {
		vector<vector<int>> res;
		if(!root) return res;
		queue<Node*> q{{root}};
		while(!q.empty()){
			size_t size = q.size();
			vector<int> level;
			while(size--){
				auto cur = q.front();
				q.pop();
				level.push_back(cur->val);
				for(auto child : cur->children){
					q.push(child);
				}	
			}
			res.push_back(level);
		}
		return res;
	}
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
	three->children = {five,six};
	dbg(s.preorder(one));
	dbg(s.postorder(one));
	dbg(s.levelOrder(one));
	return 0;
}
