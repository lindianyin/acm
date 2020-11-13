#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <limits>
#include "dbg-macro/dbg.h"
using namespace std;
int n,q,M,A[50];
int solve(int i,int m){
	if(m == 0) return 1;
	if(i>=n) return 0;
	int res = solve(i+1,m) || solve(i+1,m-A[i]);
	return res;
}
int main(int argc,char* argv[]){
	cin >> n;
	for(int i = 0;i<n;i++){
		cin >> A[i];
	}
	cin >> q;
	for(int i = 0;i<q;i++){
		cin >> M;
		if(solve(0,M)) cout << "yes" << endl;
		else cout << "no" << endl;	
	}
	return 0;
}
