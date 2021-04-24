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
	int findDuplicate(vector<int>& nums){
		unordered_set<int> s;
		for(int item : nums){
			if(s.count(item))
				return item;
			else
				s.insert(item);
		}
		return 0;
	}
	
};

int main(int argc,char* argv[]){
	Solution s;
	vector<int> nums = {1,2,1};
	dbg(s.findDuplicate(nums));
	return 0;
}
