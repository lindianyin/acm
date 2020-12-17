#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <set>
#include <unordered_set>
#include <algorithm>
#include <limits>
#include "dbg-macro/dbg.h"
using namespace std;
class Solution{
public:
    bool containsDuplicate(vector<int>& nums) {
	unordered_set<int> s;
	for(auto item : nums){
		if(s.count(item) == 0)
			s.insert(item);
		else
			return true;
	}
	return false;
    }	
};

int main(int argc,char* argv[]){
	Solution s;
	vector<int> nums = {1,1,2,3};
	dbg(s.containsDuplicate(nums));
	return 0;
}
