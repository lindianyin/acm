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
    ListNode* oddEvenList(ListNode* head) {
		if(nullptr == head)
			return head;
		ListNode* p1 = head;
		ListNode* p2 = head->next;
		ListNode* pe = p2;
		ListNode* cur = nullptr;
		if(p2) cur = p2->next;
		int n = 0;
		while(cur){
			if(n++ % 2 == 0){
				p1->next = cur;
				p1 = p1->next;
			}else{
				p2->next = cur;
				p2 = p2->next;
			}	
			cur = cur->next;
		}		        
		if(p1) p1->next = pe;
		if(p2) p2->next = NULL;
		return head;
    }
	void Print(ListNode* head){
		ListNode* cur = head;
		while(cur){
			cout << cur->val << ",";
			cur = cur->next;
		}
		cout << endl;
	}
};


int main(int argc,char* argv[]){
	ListNode* one = new ListNode(1,NULL);
	ListNode* two = new ListNode(2,NULL);
	ListNode* three = new ListNode(3,NULL);
	ListNode* four = new ListNode(4,NULL);
	ListNode* five = new ListNode(5,NULL);
	one->next = two;
	two->next = three;
	three->next = four;
	four->next = five;
	Solution s;
	s.Print(one);
	ListNode* ret = s.oddEvenList(one);
	s.Print(ret);
	return 0;
}
