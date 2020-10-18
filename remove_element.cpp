#include <iostream>
#include <string>
#include <vector>
#include "dbg-macro/dbg.h"
using namespace std;
class Solution{
public:
	void remove_element(vector<int>& A,int e){
		int j = 0;
		for(int i = 0;i<A.size();i++){
			if(A[i] != e){
				A[j++] = A[i];
			}	
		}
		dbg(j);
		A.resize(j);
	}	
};

int main(int argc,char* argv[]){
	Solution s;
	vector<int> A = {1,2,2,3};	
	s.remove_element(A,2);
	dbg(A);
	return 0;
}
