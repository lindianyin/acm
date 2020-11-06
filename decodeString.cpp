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
    string decodeString(string s) {
		stack<char> st;
		for(int i = 0;i<s.size();i++){
			char c = s[i];
			if(c == ']'){
				string str;
				while(!st.empty() && st.top() != '['){
					str.push_back(st.top());
					st.pop();
				}
				reverse(str.begin(),str.end());
				if(!st.empty() && st.top() == '[')
					st.pop();
				string num;
				while(!st.empty() && isdigit(st.top())){
					num.push_back(st.top());	
					st.pop();
				}
				reverse(num.begin(),num.end());	
				int n = atoi(num.c_str());
				for(int j = 0;j<n;j++){
					for(int k = 0;k<str.size();k++){
						st.push(str[k]);
					}	
				}
			}else{
				st.push(c);
			}
		}
		string result;
		while(!st.empty()){
			result.push_back(st.top());
			st.pop();
		}	
		reverse(result.begin(),result.end());
		return result;
    }	
};

int main(int argc,char* argv[]){
	Solution s;	
	dbg(s.decodeString("3[a]2[bc]"));
	dbg(s.decodeString("3[a2[c]]"));
	dbg(s.decodeString("2[abc]3[cd]ef"));
	return 0;
}
