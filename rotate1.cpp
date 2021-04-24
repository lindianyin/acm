#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <map>
#include <queue>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <limits>
#ifdef DBG
#include "dbg-macro/dbg.h"
#endif
#include "TreeNode.h"
using namespace std;
class Solution{
public:
	//nums = [1,2,3,4,5,6,7], k = 3
	//[5,6,7,1,2,3,4]
	void rotate(vector<int>& nums,int k){
		if(k == 0 || nums.empty()) return;
		k = k % nums.size();
		vector<int> res;
		for(int i=nums.size()-k;i<nums.size();i++)
			res.push_back(nums[i]);
		for(int i=0;i<nums.size()-k;i++)
			res.push_back(nums[i]);	
		nums = res;
	}
	
};

int main(int argc,char* argv[]){
	Solution s;
	vector<int> nums = {-1,-100,3,99};
	int k = 2;
	s.rotate(nums,k);
	dbg(nums);
	return 0;
}
