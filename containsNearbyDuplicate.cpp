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
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
	unordered_set<int> set;
	for(int i = 0;i<nums.size();i++){
		if(set.count(nums[i]) == 1) return true;
		set.insert(nums[i]);
		if(set.size() > k)
			set.erase(nums[i-k]);
	}
	return false;
    }
};

int main(int argc,char* argv[]){
	Solution s;
	vector<int> nums = {1,2,3,1};
	int k = 3;
	dbg(s.containsNearbyDuplicate(nums,k));
	return 0;
}
