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
	int val = 0;
	ListNode *next = nullptr;
	ListNode() : val(0), next(nullptr) {}
 	ListNode(int x) : val(x), next(nullptr) {}
 	ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return NULL;
        ListNode *p = head;
        // 统计长度
        int len = 1;
        for(; p->next; p=p->next) len++;
        // 首尾相连
        p->next = head;
        // 找到断点
        k %= len;
        for(p = head; --len != k; p = p->next);
        // 更改首尾
        head = p->next;
        p->next = NULL;
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
	Solution s;
	ListNode* one = new ListNode(1);	
	ListNode* two = new ListNode(2);	
	ListNode* three = new ListNode(3);	
	one->next = two;
	two->next = three;
	ListNode* result = nullptr;
	//result = s.rotateRight(one,0);	
	//s.Print(result);
	//result = s.rotateRight(one,1);	
	//s.Print(result);
	result = s.rotateRight(one,4);	
	s.Print(result);
	return 0;
}
