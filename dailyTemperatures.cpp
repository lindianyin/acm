#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <limits>
#include "dbg-macro/dbg.h"
using namespace std;
class Solution{
public:
    vector<int> dailyTemperatures(vector<int>& T) {
		int n = T.size();
		vector<int> ans(n);
		stack<int> s;
		for(int i = 0;i<n;i++){
			while(!s.empty() && T[i] > T[s.top()]){
				int previousIndex = s.top();
				ans[previousIndex] = i - previousIndex;
				s.pop();
			}
			s.push(i);
		}
		return ans;
    }	
};

int main(int argc,char* argv[]){
	Solution s;
	vector<int> T = {73, 74, 75, 71, 69, 72, 76, 73};
	vector<int> vec = s.dailyTemperatures(T);
	dbg(vec);
	return 0;
}
