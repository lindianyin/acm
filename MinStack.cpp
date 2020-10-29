#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <limits>
#include "dbg-macro/dbg.h"
using namespace std;
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
   		min_stack.push(numeric_limits<int>::max());	     
    }
    
    void push(int x) {
		x_stack.push(x);        
		min_stack.push(min(min_stack.top(),x));
    }
    
    void pop() {
    	x_stack.pop(); 
		min_stack.pop();	
    }
    
    int top() {
       return x_stack.top(); 
    }
    
    int getMin() {
       return min_stack.top(); 
    }
	stack<int> x_stack;
	stack<int> min_stack;	
};

int main(int argc,char* argv[]){
	MinStack minStack;
	minStack.push(-2);
	minStack.push(0);
	minStack.push(-3);
	dbg(minStack.getMin());   //--> ·µ»Ø -3.
	minStack.pop();
	dbg(minStack.top());      //--> ·µ»Ø 0.
	dbg(minStack.getMin());   //--> ·µ»Ø -2.
	return 0;
}
