#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <limits>
#include "dbg-macro/dbg.h"
using namespace std;

class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {

    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
		while(!right.empty()){
			left.push(right.top());
			right.pop();
		}
		left.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
		while(!left.empty()){
			right.push(left.top());
			left.pop();
		}
		int top = right.top();
		right.pop();
		return top;
    }
    
    /** Get the front element. */
    int peek() {
		while(!left.empty()){
			right.push(left.top());
			left.pop();
		}
		return right.top();	
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
		return left.empty() && right.empty();
    }
	stack<int> left;
	stack<int> right;
};

int main(int argc,char* argv[]){
	MyQueue myQueue;
	myQueue.push(1); // queue is: [1]
	myQueue.push(2); // queue is: [1, 2] (leftmost is front of the queue)
	dbg(myQueue.peek()); // return 1
	dbg(myQueue.pop()); // return 1, queue is [2]
	dbg(myQueue.empty()); // return false
	return 0;
}
