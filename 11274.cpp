#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <limits>
using namespace std;

int main(int argc,char* argv[]){
	int target,N,x;
	cin >> target >> N;
	vector<int> vec;
	map<int,int> m;
	for(int i = 0;i<N;i++){
		cin >> x;
		auto it = m.find(x);
		if(it == m.end())
			m[x] = i;
		vec.push_back(x);
	}
	for(int i = 0;i<vec.size();i++){
		int x = vec[i];
		auto it = m.find(target - x);		
		if(it != m.end() && i != it->second){
			cout << i+1 << " " << it->second+1 << endl;
			return 0;
		}
	}
	cout << 0 << " " << 0 << endl;
	return 0;
}
