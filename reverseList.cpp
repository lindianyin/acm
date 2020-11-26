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
	ListNode* reverseList(ListNode* head) {
		ListNode* prev = NULL;
		ListNode* cur = head;
		while(cur){
			ListNode* tmp = cur->next;
			cur->next = prev;
			prev = cur;
			cur = tmp;
		}
		return prev;
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
	ListNode* r = s.reverseList(one);
	s.Print(r);
	return 0;
}
