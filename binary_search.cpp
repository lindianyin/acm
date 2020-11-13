#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <limits>
#include "dbg-macro/dbg.h"
using namespace std;

bool binary_search(int* A,int n,int key){
	int left = 0,right = n;
	int mid;
	while(left < right){
		mid = (left + right) / 2;
		if( key  == A[mid]) return true;
		if( key > A[mid]) left = mid +1;
		else if( key < A[mid]) right = mid;
	}
	return false;
}
int main(int argc,char* argv[]){
	int n,A[10000+1],q,key,sum = 0;
	cin >> n;
	for(int i = 0;i<n;i++){
		cin >> A[i];
	}	
	cin >> q;
	for(int i = 0;i<q;i++){
		cin >> key;
		if(binary_search(A,n,key))
			sum++;
	}
	cout << sum << endl;
	return 0;
}
