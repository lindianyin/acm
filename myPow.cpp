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
	double quickMul(double x,long long N){
		if(N == 0)
			return 1.0;
		double y = quickMul(x,N/2);
		return N % 2 == 0 ? y * y : y*y*x;
	}
	double myPow(double x,int n){
		long long N = n;
		return N>=0 ? quickMul(x,N) : (1.0 / quickMul(x,-N));
	}
	
};

int main(int argc,char* argv[]){
	Solution s;
	dbg(s.myPow(2.0,1000));
	return 0;
}
