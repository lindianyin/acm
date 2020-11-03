#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <limits>
#include "dbg-macro/dbg.h"
using namespace std;
class Solution{
public:
	void DFS(vector<int>& nums,int i,int sum,int S) {
		if(i == nums.size()){
			if(sum == S)
				count++;
		}else{
			DFS(nums,i+1,sum+nums[i],S);
			DFS(nums,i+1,sum-nums[i],S);
		}
    }
    int findTargetSumWays(vector<int>& nums, int S) {
		DFS(nums,0,0,S);
		return count;
    }	
	int count = 0;
};

int main(int argc,char* argv[]){
	Solution s;
	vector<int> nums = {1,1,1,1,1};
	int S=3;
	int cnt = s.findTargetSumWays(nums,3);
	dbg(cnt);
	return 0;
}
