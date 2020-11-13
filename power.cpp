#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <limits>
#include <cmath>
#include "dbg-macro/dbg.h"
using namespace std;

long lpow(long m,long n,long mod){
	if(n == 1)
		return m;
	int res = lpow(m*m%mod,n/2,mod);
	if(n % 2 == 1)
		res = res * m % mod;
	return res;
}


int main(int argc,char* argv[]){
	dbg(lpow(2,10,10));
	return 0;
}
