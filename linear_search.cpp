#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <limits>
#include "dbg-macro/dbg.h"
using namespace std;

bool search(int* A,int n,int key){
	int i = 0;
	A[n] = key;
	while(A[i] != key)
		i++;
	return i != n;
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
		if(search(A,n,key))
			sum++;
	}
	cout << sum << endl;
	return 0;
}
