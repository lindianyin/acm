#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <set>
#include <algorithm>
#include <limits>
using namespace std;

unsigned long gcd(unsigned long a, unsigned long b){
    unsigned long g;
    if(b == 0)
        g = a;
    else
        g = gcd(b, a%b);
    return g;
}
int main(int argc,char* argv[]){
	unsigned long a,b,c,d,e,f,g;
	cin >> a >> b >> c >> d;
	if(b == 0 || d == 0){
		cout <<"No" << endl;
		return 0;
	}
	g = gcd(a,b);
	if(b%g == 0){
		a /= g;
		b /= g;
	}
	g = gcd(c,d);
	if(d%g == 0){
		c /= g;
		d /= g;
	}	

	e = a*d+b*c;
	f = b*d;
	g = gcd(e,f);
	if(f % g == 0)
		cout << e / g <<" " << f /g << endl;
	else
		cout << e <<" " << f << endl;
	return 0;
}
