#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <limits>
#include <set>
using namespace std;
int main(int argc,char* argv[]){
	set<int> s;
	map<int,int> rg;
	int n;
	int m;
	int v;
	cin >> n >> m;
	for(int i = 0;i<n;i++){
		cin >> v;
		s.insert(v);
	}
	int left,right;
	for(int i = 0;i<m;i++){
		cin >> left >> right;	
		auto it = rg.find(left);
		if(it == rg.end())
			rg[left] = right;		
		else
			it->second = min(it->second,right);	
	}





	return 0;
}
