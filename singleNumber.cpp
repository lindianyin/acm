#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <limits>
#include "dbg-macro/dbg.h"
using namespace std;
class Solution{
public:
    int singleNumber(vector<int>& nums) {
	int m = 0;
	for(auto item : nums){
		m ^= item;
	}
	return m;
    }
};

int main(int argc,char* argv[]){
	Solution s;
	vector<int> nums = {1,1,2};
	dbg(s.singleNumber(nums));
	return 0;
}
