#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <limits>
#include "dbg-macro/dbg.h"
#include <limits.h>
using namespace std;

bool is_cycle_num(int num,int nv){
	std::string n = std::to_string(num);
	int sum = 0;
	for(int i = 0;i<n.size();i++){
		sum += n[i] - '0';
	}	
	if(sum != nv)
		return false;
	std::string tmp = n;
	std::reverse(tmp.begin(),tmp.end());
	return n == tmp;
}
int main(int argc,char* argv[]){
	int n;
	cin >> n;
	for(int i = 10000;i<=999999;i++){
		if(is_cycle_num(i,n))
			cout << i << endl;
	}	
	
	return 0;
}
