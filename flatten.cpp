#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <set>
#include <algorithm>
#include <limits>
#include "dbg-macro/dbg.h"
using namespace std;
class Node {
public:
	int val = 0;
	Node* prev = nullptr;
	Node* next = nullptr;
	Node* child = nullptr;
};
class Solution {
public:
	Node* flattenDFS(Node* prev,Node* cur){
		if(cur == nullptr) return prev;
		cur->prev = prev;
		prev->next = cur;
		Node* tempNext = cur->next;
		Node* tail = flattenDFS(cur,cur->child);
		cur->child = nullptr;
		return flattenDFS(tail,tempNext);
	}
	Node* flatten(Node* head) {
		if(head == nullptr) return head;
		Node* pseudoHead = new Node();	
		pseudoHead->next = head;
		head->prev = pseudoHead;
		flattenDFS(pseudoHead,head);
		pseudoHead->next->prev = nullptr;
		return pseudoHead->next;
	}
};
int main(int argc,char* argv[]){
	Node* one = new Node();
	return 0;
}
