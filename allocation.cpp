#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <limits>
#include "dbg-macro/dbg.h"
using namespace std;
#define MAX 100000
int n,k;
long long T[MAX];
int check(long long P){
	int i = 0;
	for(int j = 0;j<k;j++){
		long long s = 0;
		while(s+T[i] <=P){
			s+=T[i];
			i++;
			if(i == n) return n;
		}
	}
	return i;
}
int solve(){
	long long left = 0;
	long long right = 100000*10000;
	long long mid;
	while(right - left > 1){
		mid = (left +right) / 2;
		int v = check(mid);
		if(v >=n) right = mid;
		else left = mid;
	}
	return right;
}
int main(int argc,char* argv[]){
	cin >> n >> k;
	for(int i = 0;i<n;i++)
		cin >> T[i];
	long long ans = solve();
	cout << ans << endl;
	return 0;
}
