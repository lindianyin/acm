#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;
int main(int argc,char* argv[]){
	int n;
	int arr[1000];
	int a;
	cin >> n;
	for(int i = 0;i<n;i++){
		cin >> arr[i];
	}
	cin >> a;
	int idx = -1;	
	for(int i = 0;i<n;i++){
		if(arr[i] == a){
			idx = i+1;
			break;
		}
	}
	cout << idx<<endl;
	return 0;
}
