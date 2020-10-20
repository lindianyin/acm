#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <limits>
#include "dbg-macro/dbg.h"
using namespace std;
class Solution{
public:
    int removeDuplicates(vector<int>& nums) {
		if(nums.size() == 1)
			return 1;
		if(nums.size() == 0)
			return 0;
		int i = 0,j=1;
		for(;j<nums.size();j++){
			if(nums[j] == nums[i]){
				continue;
			}else{
				nums[++i] = nums[j];
			}
		}
		return i+1;
    }	
};

int main(int argc,char* argv[]){
	Solution s;
	vector<int> nums = {1,2,2,3};
	int len = s.removeDuplicates(nums);	
	dbg(nums);
	dbg(len);	
	return 0;
}
