#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution{
public:
	int pivotIndex(vector<int>& nums){
		int sum = 0;
		for(auto item : nums)
			sum += item;
		int left_sum = 0;
		for(int i=0;i<nums.size();i++){
			if(left_sum == sum -left_sum - nums[i])
				return i;
			else
				left_sum += nums[i];
		}
		return -1;
	}

};

int main(int argc,char* argv[]){
	vector<int> nums = {1,7,3,6,5,6};
	Solution s;
	cout << s.pivotIndex(nums)<<endl;	
	nums = {1,2,3};
	cout << s.pivotIndex(nums)<<endl;	
	nums = {-1,-1,-1,-1,-1,0};
	cout << s.pivotIndex(nums)<<endl;	
	return 0;
}
