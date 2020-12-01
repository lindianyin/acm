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
    bool isPalindrome(ListNode* head) {
		stack<int> s;
		ListNode* cur = head;
		while(cur){
			s.push(cur->val);
			cur = cur->next;
		}		
		cur = head;
		while(cur){
			if(!s.empty()){
				if(cur->val == s.top()){
					s.pop();
				}else{
					return false;
				}
			}		
			cur = cur->next;
		}
		return true;
    }
};


int main(int argc,char* argv[]){
	ListNode* one = new ListNode(1,NULL);
	ListNode* two = new ListNode(2,NULL);
	ListNode* three = new ListNode(2,NULL);
	ListNode* four = new ListNode(1,NULL);
	one->next = two;
	two->next = three;
	three->next = four;
	Solution s;
	bool ret =  s.isPalindrome(one);
	dbg(ret);
	return 0;
}
