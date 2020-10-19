#include <iostream>
#include <string>
#include <vector>
#include "dbg-macro/dbg.h"
using namespace std;
class Solution{
public:
	int removeElement(vector<int>& nums,int val){
		int j = 0;
		for(int i = 0;i<nums.size();i++){
			if(nums[i] != val){
				nums[j++] = nums[i];
			}	
		}
		return j;
	}	
};

int main(int argc,char* argv[]){
	Solution s;
	vector<int> A = {1,2,2,3};	
	s.removeElement(A,2);
	dbg(A);
	return 0;
}
