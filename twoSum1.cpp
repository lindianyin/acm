#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <set>
#include <unordered_map>
#include <algorithm>
#include <limits>
#include "dbg-macro/dbg.h"
using namespace std;
class Solution{
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int,int> tmp;
		for(int i = 0;i<nums.size();i++){
			tmp[nums[i]] = i;	
		}
		for(int i = 0;i<nums.size();i++){
			int v = nums[i];
			int left = target - v;
			auto it = tmp.find(left);	
			if(it != tmp.end() && it->second != i){
				return {i,it->second};	
			}
		}
		return {};
	}	
};

int main(int argc,char* argv[]){
	Solution s;
	vector<int> nums = {2,7,11,15};
	int target = 9;
	dbg(s.twoSum(nums,9));
	return 0;
}
