#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "dbg-macro/dbg.h"
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
		for(int i = 0;i<numbers.size();i++){
			int left = target - numbers[i];
			auto it = lower_bound(numbers.begin(),numbers.end(),left);
			if(it == numbers.end())
				continue;
			int j = it - numbers.begin();
			if(numbers[j] != left || i == j)
				continue;
			return {min(i+1,j+1),max(i+1,j+1)};
		}
		return {};
    }
};
int main(int argc,char* argv[]){
	Solution s;
	vector<int> numbers={3,24,50,79,88,150,345};
	numbers = {0,0,3,4};
	dbg(s.twoSum(numbers,200));
	dbg(s.twoSum(numbers,0));
	return 0;
}
