#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <limits>
#include <cmath>
#include <set>
//#include "dbg-macro/dbg.h"
using namespace std;
class Solution{
public:
	bool is_prime(int n){
		if(n == 1)
			return false;
		for(int j=2;j*j<=n;j++){
				if(n % j == 0){
					return false;
				}
		}
		return true;
	}	
	int shushu(int left,int right){
		int cnt = 0;
		for(int i = left;i<=right;i++){
			if(is_prime(i))
				cnt++;	
		}	
		return cnt;
	}	
};

int main(int argc,char* argv[]){
	Solution s;
	int left,right;
	cin >> left >> right;
	int cnt = s.shushu(left,right);
	cout << cnt << endl;
	return 0;
}
