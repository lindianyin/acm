#include <vector>
#include <iostream>
using namespace std;
void reverse_array(std::vector<int>& arr){
	for(size_t i = 0;i<arr.size()/2;i++){
		swap(arr[i],arr[arr.size()-i-1]);
	}
}
int main(int argc,char* argv[]){
	vector<int> arr={1,3,4,8,5,2};
	reverse_array(arr);
	for(auto item : arr)
		cout << item << ",";
	cout << endl;
	return 0;
}
