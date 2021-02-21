#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <limits>
#include "dbg-macro/dbg.h"
using namespace std;
#define MAX 500000
#define SENTINEL 2000000000
int L[MAX/2+2],R[MAX/2+2];
//int cnt;
int merge(int A[],int n,int left,int mid,int right){
	int n1 = mid - left;
	int n2 = right - mid;
	for(int i = 0;i<n1;i++)
		L[i] = A[left+i];
	for(int i = 0;i<n2;i++)
		R[i] = A[mid+i];
	L[n1] = R[n2] = SENTINEL;
	int i = 0,j = 0;
	int cntt = 0;
	for(int k = left;k<right;k++){
		//cnt++;
		if(L[i] <= R[j]){
			A[k] = L[i++];
		}else{
			A[k] = R[j++];
			cntt += n1 -i;
		}
	}
	return cntt;
}
int mergeSort(int A[],int n,int left,int right){
	if(left+1 < right){
		int mid = (left + right) / 2;
		int cnt1 = mergeSort(A,n,left,mid);
		int cnt2 = mergeSort(A,n,mid,right);
		int cnt3 = merge(A,n,left,mid,right);
		return cnt1+cnt2+cnt3;
	}else{
		return 0;
	}
}
int main(int argc,char* argv[]){
	int A[MAX],n,i;
	//cnt = 0;
	cin >> n;
	for(int i = 0;i<n;i++)
		cin >> A[i];
	int cntt = mergeSort(A,n,0,n);
	//for(int i = 0;i<n;i++){
	//	if(i) cout << " ";
	//	cout << A[i];
	//}
	//cout << endl;
	//cout << cnt << endl;
	cout << cntt << endl;
	return 0;
}
