#include <vector>
#include <iostream>
using namespace std;
void Print(int* arr,int len){
	for(int i=0;i<len;i++){
		cout << arr[i] << ",";
	}
	cout << endl;
}
int RemoveSameVal(int* arr,int len,int val){
	int i = 0;
	int j = 0;
	int cnt = 0;
	for(int k = 0;k<len;k++){
		if(arr[k] != val){
			swap(arr[i],arr[j]);
			Print(arr,6);
			cout << i << "," << j << "," << k << endl;
			i++;
			j++;
		}else{
			cout << i << "," << j << "," << k << endl;
			j++;
			cnt++;
		}
	}	
	return len - cnt;
}
int main(int argc,char* argv[]){
	int arr[] = {1,3,3,4,3,6};
	RemoveSameVal(arr,6,3);
	return 0;
}
