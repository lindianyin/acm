#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <set>
#include <algorithm>
#include <limits>
#include "dbg-macro/dbg.h"
using namespace std;
class ListNode{
public:
	int val;
	ListNode* next;
	ListNode(int val,ListNode* next):val(val),next(next){}
};
class Solution {
public:
	ListNode* removeElements(ListNode* head, int val) {
    	ListNode* sentinel = new ListNode(0,head);
    	sentinel->next = head;

    	ListNode *prev = sentinel, *curr = head, *toDelete = nullptr;
    	while (curr != nullptr) {
    	  if (curr->val == val) {
    	    prev->next = curr->next;
    	    toDelete = curr;
    	  } else prev = curr;

    	  curr = curr->next;

    	  if (toDelete != nullptr) {
    	    delete toDelete;
    	    toDelete = nullptr;
    	  }
    	}

    	ListNode *ret = sentinel->next;
    	delete sentinel;
    	return ret;
    }
	void Print(ListNode* head){
		ListNode* cur = head;
		while(cur){
			cout << cur->val<<",";
			cur = cur->next;
		}
		cout << endl;
	}
};

int main(int argc,char* argv[]){
	ListNode* one = new ListNode(1,NULL);
	ListNode* two = new ListNode(2,NULL);
	ListNode* three = new ListNode(3,NULL);
	one->next = two;
	two->next = three;
	Solution s;
	s.Print(one);
	ListNode* r = s.removeElements(one,2);
	s.Print(r);
	return 0;
}
