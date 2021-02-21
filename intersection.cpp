#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <set>
#include <unordered_set>
#include <algorithm>
#include <limits>
#include "dbg-macro/dbg.h"
using namespace std;
class Solution{
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
	set<int> result;
	unordered_set<int> s2;
	for(auto item : nums2){
		s2.insert(item);
	}
	for(auto item : nums1){
		if(s2.count(item) == 1)
			result.insert(item);	
	}	
	vector<int> temp(result.begin(),result.end());
	return temp;
    }
};

int main(int argc,char* argv[]){
	Solution s;
	vector<int> nums1 = {1,2,3,4,5};
	vector<int> nums2 = {4,5,6,7};
	vector<int> result = s.intersection(nums1,nums2);
	dbg(result);
	return 0;
}
