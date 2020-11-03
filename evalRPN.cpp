#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <limits>
#include "dbg-macro/dbg.h"
using namespace std;
class Solution{
public:
    int evalRPN(vector<string>& tokens) {
		stack<int> s;
		int n = tokens.size();
		for(int i = 0;i<n;i++){
			string& token = tokens[i];
			if(token == "+"){
				int b = s.top();
				s.pop();
				int a = s.top();
				s.pop();
				s.push(a+b);
			}else if(token == "-"){
				int b = s.top();
				s.pop();
				int a = s.top();
				s.pop();
				s.push(a-b);	
			}else if(token == "*"){
				int b = s.top();
				s.pop();
				int a = s.top();
				s.pop();
				s.push(a*b);	
			}else if(token == "/"){
				int b = s.top();
				s.pop();
				int a = s.top();
				s.pop();
				s.push(a/b);	
			}else{
				s.push(atoi(token.c_str()));
			}
		}
		return s.top();
    }
};

int main(int argc,char* argv[]){
	Solution s;
	vector<string> tokens =  {"2", "1", "+", "3", "*"};
	int val = s.evalRPN(tokens);
	dbg(val);
	return 0;
}
