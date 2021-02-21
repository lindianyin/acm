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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		if(headA == nullptr || headB == nullptr)
			return nullptr;
        ListNode* curB = headB;
        while(curB->next){
            curB = curB->next;
        }
        curB->next = headB;
		ListNode* node = detectCycle(headA);
		curB->next = nullptr;
		return node;	
    }
};
int main(int argc,char* argv[]){
	Solution s;
	ListNode* headA = new ListNode(0);
	ListNode* headB = new ListNode(0);
	ListNode* one = new ListNode(1);
	ListNode* two = new ListNode(2);
	ListNode* three = new ListNode(3);
	ListNode* four = new ListNode(4);
	headA->next = one;
	one->next = three;
	three->next = four;
	headB->next = two;
	two->next = three;
	three->next = four;
	ListNode* node = s.getIntersectionNode(headA,headB);
	if(node)
		dbg(node->val);
	return 0;
}
