#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <limits>
#include "dbg-macro/dbg.h"
using namespace std;
class Solution{
public:
	int selection_sort(vector<int>& A){
		int minj,sw=0;
		for(int i = 0;i<A.size();i++){
			minj = i;
			for(int j = i;j<A.size();j++){
				if(A[j]<A[minj])
					minj = j;
			}
			dbg(A);
			swap(A[i],A[minj]);
			if(i != minj) sw++;
		}
		return sw;
	}	
};

int main(int argc,char* argv[]){
	Solution s;
	vector<int> A = {5,4,8,7,9,3,1};
	int sw = s.selection_sort(A);	
	dbg(A);
	dbg(sw);
	return 0;
}
