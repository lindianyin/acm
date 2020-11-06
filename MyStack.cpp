#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <limits>
#include "dbg-macro/dbg.h"
using namespace std;
class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {

    }
    
    /** Push element x onto stack. */
    void push(int x) {
		q.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
		int s = q.size();
		for(int i = 0;i<s-1;i++){
			int f = q.front();
			q.pop();
			q.push(f);
		}
		int f = q.front();
		q.pop();
		return f;
    }
    
    /** Get the top element. */
    int top() {
		return q.back();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
		return q.empty();
    }
	queue<int> q;
};


int main(int argc,char* argv[]){
	MyStack* obj = new MyStack();
	obj->push(1);
	obj->push(2);
	int param_2 = obj->pop();
	dbg(param_2);
	int param_3 = obj->top();
	dbg(param_3);
	bool param_4 = obj->empty();
	dbg(param_4);
	return 0;
}
