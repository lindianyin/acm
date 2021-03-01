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
//买卖股票的最佳时机 II
class Solution{
public:
	int maxProfit(vector<int>& prices) {
			int n = prices.size();
			int dp[n][2];
			dp[0][0] = 0, dp[0][1] = -prices[0];
			for (int i = 1; i < n; ++i) {
					dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
					dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
			}
			return dp[n - 1][0];
	}
};
int main(int argc,char* argv[]){
	Solution s;
	vector<int> prices = { 7,1,5,3,6,4 };	
	dbg(s.maxProfit(prices));
	return 0;
}
