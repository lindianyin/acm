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
	vector<int> plusOne(vector<int>& digits) {
		reverse(digits.begin(),digits.end());
		int carry = 0;
		for(int i = 0;i<digits.size();i++){
			int v = digits[i];
			if(i == 0){
				digits[i] = (v + 1) % 10;	
				carry = (v + 1) / 10;
			}else{
				digits[i] = (v + carry) % 10;	
				carry = (v + carry) / 10;
			}
		}
		if(carry > 0)
			digits.push_back(1);
		reverse(digits.begin(),digits.end());
		return digits;
	}
	
};

int main(int argc,char* argv[]){
	Solution s;
	vector<int> digits = {9,9,9,9};
	dbg(s.plusOne(digits));
	return 0;
}
