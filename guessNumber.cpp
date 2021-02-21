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
int guess(int num){
	int pick = 132353452;
	if(pick < num) return -1;
	else if(pick > num) return 1;
	else return 0; 
}
class Solution{
public:
	int guessNumber(int n) {
		long long left = INT32_MIN;
		long long right = INT32_MAX;
		while(left <=right){
			long long mid = left + (right-left) / 2;
			int val = guess(mid);
			if(val == 0) return mid;
			else if(val == 1) left = mid + 1;
			else right = mid -1;
				
		}	
		return -1;
    	}
};

int main(int argc,char* argv[]){
	Solution s;
	dbg(s.guessNumber(0));
	return 0;
}
