#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <set>
#include <unordered_set>
#include <algorithm>
#include <limits>
#include "dbg-macro/dbg.h"
using namespace std;
class Solution{
public:
	int cal(int n){
		int tmp = 0;
		while(n>0){
			tmp += (n % 10) * (n % 10);	
			n /= 10; 
		}
		return tmp;
	}
	bool isHappy(int n) {
		unordered_set<int> tmp;
		while(true){
			if(tmp.count(n) == 1)
				break;
			int v = cal(n);
			tmp.insert(n);
			if(v == 1){
				return true;
			}else{
				n = v;
			}
		}	
		return false;
	}	
};

int main(int argc,char* argv[]){
	Solution s;
	dbg(s.isHappy(19));
	return 0;
}
