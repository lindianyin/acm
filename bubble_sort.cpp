#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <limits>
#include "dbg-macro/dbg.h"
using namespace std;
class Solution{
public:
	int bubble_sort(vector<int>& A){
		bool flag = true;
		int sw = 0;
		for(int i = 0;flag;i++){
			flag = false;
			for(int j=A.size()-1;j>=i+1;j--){
				if(A[j] < A[j-1]){
					swap(A[j],A[j-1]);
					flag = true;	
					sw++;
				}
			}
		}
		return sw;
		
	}	
};

int main(int argc,char* argv[]){
	Solution s;
	vector<int> A = {5,2,4,6,1,3};
	int sw = s.bubble_sort(A);
	dbg(A);
	dbg(sw);
	return 0;
}
