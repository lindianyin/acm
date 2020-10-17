#include <iostream>
#include <string>
using namespace std;

int maxx(int* arr,int n){
	if(n<=1) 
		return arr[0];
	else{
		return max(arr[n-1],maxx(arr,n-1));
	}
}
int avg(int* arr,int n){
	if(n<=1)
		return arr[0];
	else
		return (avg(arr,n-1)*(n-1) + arr[n-1])/n;
}
int main(int argc,char* argv[]){
	int arr[] = {1,9,5};
	cout << maxx(arr,3)<<endl;
	cout << avg(arr,3)<<endl;
	return 0;
}
