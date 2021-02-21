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
bool isBadVersion(int version){
	return version >= 10;
}
class Solution{
public:
	int firstBadVersion(int n) { 
		int left = 1,right = n;
		while(left < right){
			int mid = left + (right - left) / 2;
			if(isBadVersion(mid)) right = mid;
			else left = mid +1;
		}
		return left;
    	}
	
};
int main(int argc,char* argv[]){
	Solution s;
	dbg(s.firstBadVersion(10));
	return 0;
}
