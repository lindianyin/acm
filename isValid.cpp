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
    bool isValid(string s) {
		stack<char> sk;
		for(int i = 0;i<s.size();i++){
			char c = s[i];
			if(c == '[' || c == '(' || c == '{'){
				sk.push(c);
			}else{
				if(sk.empty())
					return false;
				char t = sk.top();
				if(c == ']' && t == '[' 
					|| c == ')' && t == '('
						|| c == '}' && t == '{'){
					sk.pop();
				}else{
					return false;
				}
			}
		}	
		return sk.empty();
    }	
};

int main(int argc,char* argv[]){
	Solution s;
	dbg(s.isValid("[(]"));
	dbg(s.isValid("[()]"));
	dbg(s.isValid("[(])"));
	dbg(s.isValid("[(])"));
	dbg(s.isValid("()[]{}"));
	dbg(s.isValid("(])"));
	dbg(s.isValid("]"));
	return 0;
}
