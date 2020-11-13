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
	if(n % 2 == 1)
		return (lpow(m,n-1,mod) % mod) * (m % mod);
	else
		return (lpow(m,n/2,mod) % mod) * (lpow(m,n/2,mod) % mod);

}


int main(int argc,char* argv[]){
	dbg(lpow(2,10,10));
	dbg((long)pow(2,10) % 10);
	return 0;
}
