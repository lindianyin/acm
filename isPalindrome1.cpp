#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <map>
#include <queue>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <limits>
#ifdef DBG
#include "dbg-macro/dbg.h"
#endif
#include "TreeNode.h"
using namespace std;
class Solution{
public:
	bool isPalindrome(string s){
		string str;
		for(auto item : s){
			if(isalpha(item) || isdigit(item))
				str.push_back(tolower(item));	
		}
		string str1 = str;
		reverse(str1.begin(),str1.end());
		return str1 == str;
	}
	
};

int main(int argc,char* argv[]){
	Solution s;
	dbg(s.isPalindrome("A man, a plan, a canal: Panama"));
	return 0;
}
