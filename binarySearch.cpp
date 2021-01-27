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
	int binarySearch(vector<int>& nums,int target){
		if(nums.size() == 0)
			return -1;
		int left = 0,right = nums.size();
		while(left<right){
			int mid = left + (right - left)/2;
			if(nums[mid] == target) return mid;
			else if(nums[mid] < target) left = mid +1;
			else right = mid;
		}
		if(left != nums.size() && nums[left] == target) return left;
		return -1;
	}
	
};
int main(int argc,char* argv[]){
	Solution s;
	dbg(1);
	return 0;
}
