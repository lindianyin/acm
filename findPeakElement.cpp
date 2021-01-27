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
#include "TreeNode.h"
using namespace std;
class Solution{
public:
    int findPeakElement(vector<int>& nums) {
	if(nums.size() == 1)
		return 0;
	nums.insert(nums.begin(),INT32_MIN);
	nums.insert(nums.end(),INT32_MIN);
	for(int i = 1;i<nums.size() -1;i++){
		if(nums[i] > nums[i-1] && nums[i] > nums[i+1])
			return i-1;
	}
	return -1;
    }
};

int main(int argc,char* argv[]){
	vector<int> nums = {1,2,1,3,5,6,4};
	Solution s;
	dbg(s.findPeakElement(nums));
	return 0;
}
