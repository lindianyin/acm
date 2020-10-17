#include <vector>
#include <iostream>
using namespace std;
int m = 0;
void move(int n,char a,char c){
	m++;
	cout << n << "," << a << "," << c << endl;
}

void hanoi(int n ,char a,char b,char c){
	if(n == 1)	
		return move(1,a,c);
	else{
		hanoi(n-1,a,c,b);
		move(n,a,c);
		hanoi(n-1,b,a,c);
	}
}


int main(int argc,char* argv[]){
	hanoi(3,'a','b','c');
	return 0;
}
