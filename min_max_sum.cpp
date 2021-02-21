#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <limits>
#include "dbg-macro/dbg.h"
#include <limits.h>
using namespace std;

int main(int argc,char* argv[]){
	int n;
	cin >> n;
	int min = INT_MAX;
	int max = INT_MIN;
	long long sum = 0;
	for(int i = 0;i<n;i++){
		int v;
		cin >> v;
		if(v<min)
			min = v;
		if(v>max)
			max = v;
		sum += v;
	}
	cout << max << endl;
	cout << min << endl;
	cout << sum << endl;
	return 0;
}
