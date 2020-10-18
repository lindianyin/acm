#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <limits>
#include "dbg-macro/dbg.h"
using namespace std;
class Solution{
public:
	void insert_sort(vector<int>& A,int g){
		int i,j,v;
		dbg(g);
		dbg(A);
		for(i=g;i<A.size();i++){
			j=i-g;
			v=A[i];
			while(j>=0 && A[j] > v){
				A[j+g] = A[j];
				j-=g;
			}
			A[j+g] = v;
		}
		dbg(A);

	}	
	void shell_sort(vector<int>& A){
		vector<int> G;
		for(int i = 1;i<A.size();i=3*i+1){
			G.push_back(i);
		}
		for(int i=G.size()-1;i>=0;i--){
			insert_sort(A,G[i]);
		}
	}
};

int main(int argc,char* argv[]){
	Solution s;
	vector<int> A = {4,8,9,1,10,6,2,5,3,7};
	s.shell_sort(A);
	dbg(A);
	return 0;
}
