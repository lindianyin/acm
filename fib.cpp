#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

int main(int argc,char* argv[]){
	int n;
	cin >> n;
	long long a[n+3];
	a[1] = 1; a[2] = 1;
	for(int i = 3;i<=n;i++){
		a[i] = (a[i-1] + a[i-2]) % 10007;
	}
	cout << a[n]<<endl;
	return 0;
}
