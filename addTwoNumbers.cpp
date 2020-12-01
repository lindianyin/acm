#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <set>
#include <algorithm>
#include <limits>
#include "dbg-macro/dbg.h"
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = nullptr, *tail = nullptr;
        int carry = 0;
        while (l1 || l2) {
            int n1 = l1 ? l1->val: 0;
            int n2 = l2 ? l2->val: 0;
            int sum = n1 + n2 + carry;
            if (!head) {
                head = tail = new ListNode(sum % 10);
            } else {
                tail->next = new ListNode(sum % 10);
                tail = tail->next;
            }
            carry = sum / 10;
            if (l1) {
                l1 = l1->next;
            }
            if (l2) {
                l2 = l2->next;
            }
        }
        if (carry > 0) {
            tail->next = new ListNode(carry);
        }
        return head;
    }
    void Print(ListNode* l){
        ListNode* cur = l;
        while(cur){
            cout << cur->val << " ";
            cur = cur->next;
        }
        cout << endl;
    }
};
int main(int argc,char* argv[]){
	Solution s;
	ListNode* one = new ListNode(9);
	ListNode* two = new ListNode(9);
	ListNode* three = new ListNode(9);
	ListNode* four = new ListNode(9);
	one->next = two;
	two->next = three;
	ListNode* result = s.addTwoNumbers(one,four);
	s.Print(result);
	return 0;
}
