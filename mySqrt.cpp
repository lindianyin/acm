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
	int mySqrt(int x){
		int left = 0;
		int right = x;
		int ans = -1;
		while(left <=right){
			int mid = left + (right - left) / 2;
			long long p = (long long)mid * mid;
			if(p <= x){
				ans = mid;
				left = mid +1;
			}else{
				 right = mid - 1; 
			}
		}
		return ans;
	}
};

int main(int argc,char* argv[]){
	Solution s;
	dbg(s.mySqrt(0));
	return 0;
}
