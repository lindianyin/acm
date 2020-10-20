#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <limits>
#include "dbg-macro/dbg.h"
using namespace std;
class Solution{
public:
    int findMin(vector<int>& nums) {
		for(int i = 1;i<nums.size();i++){
			if(nums[i] < nums[i-1])
				return nums[i];
		}
		return nums[0];
    }	
};

int main(int argc,char* argv[]){
	Solution s;
	vector<int> nums = {3,4,5,1,2};
	int min = s.findMin(nums);	
	dbg(min);
	return 0;
}
