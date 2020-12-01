#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <set>
#include <algorithm>
#include <limits>
using namespace std;

int main(int argc,char* argv[]){
	int n;
	vector<int> vec;
	cin >> n;
	for(int i = 0;i<n;i++){
		int a,b;
		cin >> a >> b;
		vec.push_back(a);
		vec.push_back(b);
	}
	for(int i = 0;i<n;i++){
		cout << vec[i] << " " << vec[i+n] <<" ";
	}
	cout << endl;
	return 0;
}
