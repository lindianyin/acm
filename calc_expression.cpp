#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <limits>
#include "dbg-macro/dbg.h"
using namespace std;
class Solution{
public:
	void push(int v){
		stack[++top] = v;
	}
	int pop(){
		return stack[top--];
	}
	int calc_expression(std::string& exp){
		int i = 0;
		while(i<exp.size()){
			dbg(stack);
			dbg(top);
			char op = exp[i];
			if(op == '+'){
				push(pop()+pop());
				i++;
			}else if(op == '-'){
				int b = pop();
				int a = pop();
				push(a-b);
				i++;
			}else if(op == '*'){
				push(pop()*pop());
				i++;
			}else if(op == '/'){
				int b = pop();
				int a = pop();
				push(a/b);
				i++;
			}else if(op == ' '){
				i++;
			}else{
				int v = 0;
				int n = sscanf(exp.c_str()+i,"%d",&v);
				push(v);
				dbg(i);
				dbg(v);
				dbg(n);
				i += n;
				dbg(stack);
				dbg(top);
				continue;
			}
			dbg(stack);
			dbg(top);
		}
		return pop();
	}	
	int stack[10] = {0};//该初始化方式，有些特别，可以记录一下，再查一下文档
	int top = 0;
};

int main(int argc,char* argv[]){
	Solution s;
	std::string exp = "1 2 + 3 4 - *";
	int v = s.calc_expression(exp);
	dbg(v);	
	return 0;
}
