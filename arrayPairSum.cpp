#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "dbg-macro/dbg.h"
using namespace std;
class Solution{
public:
    int arrayPairSum(vector<int>& nums) {
		sort(nums.begin(),nums.end());
		int sum = 0;
		for(int i = 0;i<nums.size();i+=2){
			sum +=nums[i];
		}		
		return sum;
    }
	
};

int main(int argc,char* argv[]){
	Solution s;
	vector<int> nums={1,3,2,4};
	dbg(s.arrayPairSum(nums));
	return 0;
}
