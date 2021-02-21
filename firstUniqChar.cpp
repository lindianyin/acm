#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <limits>
#include "dbg-macro/dbg.h"
using namespace std;
class Solution{
public:
	int firstUniqChar(string s) {
		unordered_map<char,int> m;
		for(auto item : s){
			m[item]++;
		}
		for(int i = 0;i<s.size();i++){
			if(m[s[i]] == 1){
				return i;	
			}
		}
		return -1;
	}
	
};

int main(int argc,char* argv[]){
	Solution s;
	dbg(s.firstUniqChar("leetcode"));
	dbg(s.firstUniqChar("loveleetcode"));
	return 0;
}
