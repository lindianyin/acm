#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution{
public:
	int find(vector<int>& nums,int target,int left,int right){
		if(left == right){
			if(target<=nums[left])
				return left;
			else
				return right+1;
		}
		int pivot = (left + right) / 2;
		if(nums[pivot] == target)
			return pivot;
		else if (nums[pivot] > target)
			return find(nums,target,left,pivot-1);
		else
			return find(nums,target,pivot+1,right);
	}
	int find1(vector<int>& nums,int target){
		int left = 0;
		int right = nums.size() - 1;
		while(left <= right){
			int pivot = (right - left) / 2 + left;
			if(nums[pivot] == target)
				return pivot;
			else if (nums[pivot] > target)
				right = pivot -1;
			else
				left = pivot + 1;
		}
		return left;
	}
    int searchInsert(vector<int>& nums, int target) {
		//return find(nums,target,0,nums.size()-1);
		return find1(nums,target);
    }
};

int main(int argc,char* argv[]){
	vector<int> nums = {1,3,5,6};
	Solution s;
	cout << s.find1(nums,5)<<endl;	
	//cout << s.find1(nums,2)<<endl;	
	cout << s.find1(nums,7)<<endl;	
	//cout << s.find1(nums,0)<<endl;	
	//cout << s.searchInsert(nums,2)<<endl;
	nums={1};
	cout << s.searchInsert(nums,1)<<endl;
	return 0;
}
