#include <vector>
#include <iostream>
using namespace std;

void quicsort(std::vector<int>& arr,int left,int right){
	if(left>right)
		return;
	int i = left;
	int j = right;
	int pvoit = arr[left];
	while(i<j){
		while(arr[i] < pvoit)
			i++;
		while(arr[j] > pvoit)
			j--;
		if(i<j)
			swap(arr[i],arr[j]);
	}	
	arr[i] = pvoit;
	quicsort(arr,left,i-1);
	quicsort(arr,i+1,right);
}
int main(int argc,char* argv[]){
	vector<int> arr={1,3,4,8,5,2};
	quicsort(arr,0,arr.size()-1);
	for(auto item : arr)
		cout << item << ",";
	cout << endl;
	return 0;
}
