#include <iostream>
#include <string>
#include <vector>
#include "dbg-macro/dbg.h"
using namespace std;
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
		int i = 0;
		int j = 0;
		int m = 0;
		for(int k=0;k<nums.size();k++){
			if(nums[k] == 1){
				j++;
			}else{
				m = max(j-i,m);
				i = 0;
				j = 0;
			}
		}
		m = max(j-i,m);
		return m;
    }
};
int main(int argc,char* argv[]){
	Solution s;
	vector<int> A = {1,1,1,0,1,1,1};	
	A = {1,0,1,1,0,1};
	A = {1};
	int cnt = s.findMaxConsecutiveOnes(A);
	dbg(cnt);
	return 0;
}
