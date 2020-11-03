#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <limits>
#include <set>
using namespace std;
int main(int argc,char* argv[]){
	int n;
	int v;
	set<int> s;
	cin >> n;
	for(int i = 0;i<n;i++){
		cin >> v;
		s.insert(v);
	}
	cout << s.size()<<endl;
	for(auto item : s){
		cout << item << " ";
	}
	cout << endl;
	return 0;
}
