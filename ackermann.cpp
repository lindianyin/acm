#include <iostream>
#include <string>
using namespace std;

int ack(int m,int n){
	if(0 == m){
		return n+1;
	}else if (m != 0 && n == 0){
		return ack(m-1,1);
	}else if(m != 0 && n != 0){
		return ack(m-1,ack(m,n-1));
	}
}


int main(int argc,char* argv[]){
	int res = ack(4,1);
	cout << res << endl;
	return 0;
}
