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
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
	unordered_map<string,vector<string>> map;
	for(auto item : strs){
		std::string key = item;
		sort(key.begin(),key.end());
		map[key].push_back(item);
	}
	vector<vector<string>> result;
	for(auto item : map){
		vector<string> r;
		for(auto c : item.second)
			r.push_back(c);
		result.push_back(r);
	}
	return result;
    }
};

int main(int argc,char* argv[]){
	Solution s;
	vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
	dbg(s.groupAnagrams(strs));
	return 0;
}
