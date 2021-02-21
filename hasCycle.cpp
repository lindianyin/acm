#include <iostream>
#include <string>
#include <vector>
#include <stack>
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
    ListNode(int x) : val(x), next(NULL) {}
}; 
class Solution {
public:
    bool hasCycle(ListNode *head) {
		if(NULL == head)
			return false;
        ListNode* slow = head;
		ListNode* fast = slow->next;
		while(slow != fast){
			if(fast == NULL || fast->next == NULL)
				return false;
			slow = slow->next;
			fast = fast->next->next;
		}
		return true;
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
	dbg(s.hasCycle(head));
	return 0;
}
