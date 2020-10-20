#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <limits>
#include "dbg-macro/dbg.h"
using namespace std;
class Solution{
public:
    void moveZeroes(vector<int>& nums) {
    	int i = 0,j;
		for(j = 0;j<nums.size();j++){
			if(nums[j] != 0)
				nums[i++] = nums[j];
		}
		for(;i<nums.size();i++)
			nums[i] = 0;
    }	
};

int main(int argc,char* argv[]){
	Solution s;
	vector<int> nums = {0,1,0,3,12};
	nums = {1};
	s.moveZeroes(nums);
	dbg(nums);
	return 0;
}
