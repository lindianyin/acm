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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0, head);
        stack<ListNode*> stk;
        ListNode* cur = dummy;
        while (cur) {
            stk.push(cur);
            cur = cur->next;
        }
        for (int i = 0; i < n; ++i) {
            stk.pop();
        }
        ListNode* prev = stk.top();
        prev->next = prev->next->next;
        ListNode* ans = dummy->next;
        delete dummy;
        return ans;
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
	s.removeNthFromEnd(one,2);
	s.Print(one);
	return 0;
}
