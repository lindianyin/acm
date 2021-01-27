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
	int search(vector<int>& nums,int target){
		int left = 0;
		int right = nums.size();
		while(left < right){
			int mid = (left+right) / 2;
			if(nums[mid] == target)
				return mid;
			else if(nums[mid] > target){
				right = mid;
			}else{
				left = mid+1;
			}
		}
		return -1;
	}	
};
int main(int argc,char* argv[]){
	vector<int> nums = {-1,0,3,5,9,12};
	int target = 9;
	Solution s;
	dbg(s.search(nums,target));	
	return 0;
}
