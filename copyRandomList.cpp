#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <set>
#include <unordered_map>
#include <algorithm>
#include <limits>
#include "dbg-macro/dbg.h"
using namespace std;
class Node{
public:
	int val = 0;
	Node* next = nullptr;
	Node* random = nullptr;
	Node(int val):val(val){}
};
class Solution{
public:
	Node* copyRandomList(Node* head){
		if(head == nullptr) return head;
		unordered_map<Node*,Node*> mp;
		Node* cur = head;
		while(cur){
			mp[cur] = new Node(cur->val);
			cur = cur->next;
		}
		cur = head;
		while(cur){
			Node* node = mp[cur];
			node->next = mp[cur->next];
			node->random = mp[cur->random];
			cur = cur->next;
		}
		return mp[head];
	}	
};

int main(int argc,char* argv[]){
	dbg(1);
	return 0;
}
