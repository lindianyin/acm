#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <limits>
#include "dbg-macro/dbg.h"
using namespace std;
class Solution{
public:
	void insert_sort(vector<int>& A){
		int i,j,v;
		dbg(A);
		for(i=1;i<A.size();i++){
			j=i-1;
			v=A[i];
			while(j>=0 && A[j] > v){
				A[j+1] = A[j];
				j--;
			}
			A[j+1] = v;
			dbg(A);
		}

	}	
};

int main(int argc,char* argv[]){
	Solution s;
	vector<int> A = {5,2,4,6,1,3};
	s.insert_sort(A);
	dbg(A);
	return 0;
}
