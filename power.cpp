#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <limits>
#include <cmath>
#ifdef DBG
#include "dbg-macro/dbg.h"
#endif
using namespace std;
#define c 100000007
long divide(long a,long b){
	if(b == 0)
		return 1;
	else if (b % 2 == 0)
		return divide((a%c)*(a%c),b/2)%c;
	else
		return (a%c) * divide((a%c)*(a%c),(b-1) /2) % c;
}


int main(int argc,char* argv[]){
	int n,m;
	cin >> n >> m;
	cout << divide(n,m)<<endl;
	return 0;
}
