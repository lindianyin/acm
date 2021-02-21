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
#define SENTINEL 200000000
struct Card{
	char suit;
	int value;
};
struct Card L[MAX/2+2],R[MAX/2+2];
void merge(Card A[],int n,int left,int mid,int right){
	int i,j,k;
	int n1 = mid - left;
	int n2 = right - mid;
	for(i = 0;i<n1;i++) L[i] = A[left+i];
	for(i = 0;i<n2;i++) R[i] = A[right+i];
	L[n1].value = R[n2].value = SENTINEL;
	i = j = 0;
	for(k = left;k<right;k++){
		if(L[i].value <= R[j].value)
			A[k] = L[i++];
		else
			A[k] = R[j++];
	}
}
void mergeSort(Card A[],int n,int left,int right){
	int mid;
	if(left+1 < right){
		mid = (left + right) / 2;
		mergeSort(A,n,left,mid);
		mergeSort(A,n,mid,right);
		merge(A,n,left,mid,right);
	}
}
int partition(Card A[],int n,int p,int r){
	int i,j;
	Card x;
	x = A[r];
	i = p - 1;
	for(j = p;j<r;j++){
		if(A[j].value <= x.value){
			i++;
			swap(A[i],A[j]);
		}
	}
	swap(A[i+1],A[r]);
	return i+1;
}
void quickSort(Card A[],int n,int p,int r){
	int q;
	if(p < r){
		q = partition(A,n,p,r);
		quickSort(A,n,p,q-1);
		quickSort(A,n,p+1,r);
	}
}
int main(int argc,char* argv[]){
	int n,i,v;
	struct Card A[MAX],B[MAX];
	char S[10];
	int stable = 1;
	cin >> n;
	for(int i = 0;i<n;i++){
		cin >> S >> v;
		A[i].suit = B[i].suit = S[0];
		A[i].value = B[i].value = v;
	}
	mergeSort(A,n,0,n);
	quickSort(B,n,0,n-1);
	for(i = 0;i<n;i++){
		if(A[i].suit != B[i].suit) stable = 0;
	}
	if(stable == 1) cout << "Stable" << endl;
	else cout << "Not stable" << endl;
	for(i = 0;i<n;i++){
		cout <<B[i].suit<<" " << B[i].value << endl;
	}
	return 0;
}
