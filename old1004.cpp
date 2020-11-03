#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <limits>
#include <cmath>
using namespace std;
int main(int argc,char* argv[]){
	int r;
	cin >> r;
	cout.flags(ios::fixed);
	cout.precision(7);
	//cout << atan(1.0)*4*r*r<<endl;
	cout << M_PI*r*r  << endl;
	return 0;
}
