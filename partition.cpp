#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <map>
#include <queue>
#include <set>
#include <algorithm>
#include <limits>
#ifdef DBG
#include "dbg-macro/dbg.h"
#endif
using namespace std;
#define MAX 100000
int A[MAX],n;

int partition(int p,int r){
	int x = A[r],i=p-1;
	for(int j = p;j<r;j++){
		if(A[j] <= x){
			i++;
			swap(A[i],A[j]);
		}
	}
	swap(A[i+1],A[r]);
	return i+1;
}
int main(int argc,char* argv[]){
	cin >> n;
	for(int i = 0;i<n;i++){
		cin >> A[i];
	}
	int q = partition(0,n-1);
	for(int i = 0;i<n;i++){
		if(i>0)
			cout <<" ";
		if(i == q)
			cout <<"[";
		cout << A[i];
		if(i == q)
			cout <<"]";
	}
	cout << endl;
	return 0;
}
