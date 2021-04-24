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
	double findMedianSortedArrays(vector<int>& num1,vector<int>& num2){
		vector<int> result;
		int l = 0,r = 0;
		while(l<num1.size() && r < num2.size()){
			if(num1[l] < num2[r]){
				result.push_back(num1[l]);
				l++;
			}else{
				result.push_back(num2[r]);
				r++;
			}
		}	
		while(l < num1.size()){
			result.push_back(num1[l++]);	
		}
		while(r < num2.size()){
			result.push_back(num2[r++]);	
		}

		if(result.size() % 2 == 0){
			return (result[result.size() / 2] + result[result.size() / 2 - 1]) / 2.0;
		}else{
			return result[result.size() / 2];
		}
		
	}	

};

int main(int argc,char* argv[]){
	Solution s;
	vector<int> num1 = {1,2};
	vector<int> num2 = {3,4};
	dbg(s.findMedianSortedArrays(num1,num2));
	return 0;
}
