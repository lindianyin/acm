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
	bool isAnagram(string s,string t){
		sort(s.begin(),s.end());
		sort(t.begin(),t.end());
		return s == t;	
	}
	
};

int main(int argc,char* argv[]){
	Solution s;
	dbg(s.isAnagram("anagram","nagaram"));
	return 0;
}
