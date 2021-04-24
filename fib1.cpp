#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <map>
#include <queue>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <limits>
#ifdef DBG
#include "dbg-macro/dbg.h"
#endif
#include "TreeNode.h"
using namespace std;
class Solution{
public:
	Solution(){
		for(int i = 0;i<50;i++) dp[i] = -1;
	}
	int fib(int n){
		if(n == 0 || n == 1) return dp[n] = 1;	
		if(dp[n] != -1) return dp[n];
		return dp[n] = fib(n-1) + fib(n-2);
	}	
	int dp[50];
};

int main(int argc,char* argv[]){
	int n;
	cin >> n;
	Solution s;
	dbg(s.fib(n));
	return 0;
}
