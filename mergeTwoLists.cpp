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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    	ListNode* l3 = new ListNode();    
		ListNode* result = l3;
		while(l1 && l2){
			if(l1->val <= l2->val){
				l3->next = l1;
				l3 = l1;
				l1 = l1->next;
			}else{
				l3->next = l2;
				l3 = l2;
				l2 = l2->next;
			}
		}
		if(l1)
			l3->next = l1;
		if(l2)
			l3->next = l2;
		return result->next;
    }
	void Print(ListNode* l){
		ListNode* cur = l;
		while(cur){
			cout << cur->val << ",";
			cur = cur->next;
		}
		cout << endl;
	}
};
int main(int argc,char* argv[]){
	Solution s;
	ListNode* one = new ListNode(1);
	ListNode* two = new ListNode(2);
	ListNode* three = new ListNode(3);
	ListNode* four = new ListNode(4);
	ListNode* five = new ListNode(5);
	one->next = three;
	three->next = five;
	two->next = four;
	ListNode* result = s.mergeTwoLists(one,two);
	s.Print(result);
	return 0;
}
