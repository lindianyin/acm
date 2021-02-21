#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <limits>
#include "dbg-macro/dbg.h"
using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
}; 
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
		ListNode* slow = head,*fast = head;
		while(fast != nullptr){
			slow = slow->next;
			if(fast->next == nullptr)
				return nullptr;
			fast = fast->next->next;
			if(fast == slow){
				ListNode* ptr = head;
				while(ptr != slow){
					ptr = ptr->next;
					slow = slow->next;
				}
				return ptr;
			}

		}
		return nullptr;
    }
};
int main(int argc,char* argv[]){
	Solution s;
	ListNode* head = new ListNode(0);
	ListNode* one = new ListNode(1);
	ListNode* two = new ListNode(1);
	ListNode* three = new ListNode(1);
	head->next = one;
	one->next = two;
	two->next = one;
	dbg(s.detectCycle(head)->val);
	return 0;
}
