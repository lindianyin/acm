#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <limits>
#include <stdint.h>
#include "dbg-macro/dbg.h"
using namespace std;
class Solution{
public:
    int minSubArrayLen(int s, vector<int>& nums) {
		int i = 0,j = 0;
		int n = nums.size();
		if(n == 0)
			return 0;
		int sum = 0;
		int m = INT32_MAX;
		while(j<n){
			sum +=nums[j];
			while(sum>=s){
				m = min(m,j-i+1);
				sum -=nums[i];
				i++;	
			}
			j++;
		}	
		return m == INT32_MAX ? 0 : m;
    }	
};

int main(int argc,char* argv[]){
	Solution slt;
	int s = 7;
	vector<int> nums = {2,3,1,2,4,3};
	int m = slt.minSubArrayLen(7,nums);	
	dbg(m);
	return 0;
}
