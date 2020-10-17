#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <limits>
#include "dbg-macro/dbg.h"
using namespace std;
class Solution{
public:
	int max_profit(vector<int>& A){
		int minv=A[0];
		int maxv=numeric_limits<int>::min();
		for(size_t i = 1;i<A.size();i++){
			maxv = max(maxv,A[i]-minv);
			minv = min(A[i],minv);
		}
		return maxv;
	}	
};

int main(int argc,char* argv[]){
	Solution s;
	vector<int> A = {6,5,3,1,3,4,3};
	dbg(s.max_profit(A));
	return 0;
}
