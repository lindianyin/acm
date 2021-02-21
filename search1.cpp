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
int search(vector<int>& nums, int target) {
    int lo = 0, hi = nums.size() - 1, mid = 0;
    while (lo <= hi) {
        mid = lo + (hi - lo) / 2;
        if (nums[mid] == target) {
            return mid;
        }
        // 先根据 nums[mid] 与 nums[lo] 的关系判断 mid 是在左段还是右段 
        if (nums[mid] >= nums[lo]) {
            // 再判断 target 是在 mid 的左边还是右边，从而调整左右边界 lo 和 hi
            if (target >= nums[lo] && target < nums[mid]) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        } else {
            if (target > nums[mid] && target <= nums[hi]) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
    }
    return -1;
}
};
int main(int argc,char* argv[]){
	Solution s;
	vector<int> nums = {4,5,6,7,0,1,2};
	dbg(s.search(nums,5));	
	return 0;
}
