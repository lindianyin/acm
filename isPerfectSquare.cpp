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
	bool isPerfectSquare(int num){
		int l  = 1,r = num;
		while(l<=r){
			long long m = l + (r-l) / 2;
			long long M = m*m;
			if(M == num) return true;
			else if(M < num)
				l = m + 1;
			else
				r = m - 1;		
		}
		return false;
	}	
};

int main(int argc,char* argv[]){
	Solution s;
	dbg(s.isPerfectSquare(16));
	dbg(s.isPerfectSquare(17));
	return 0;
}
