#include <iostream>
#include <string>
using namespace std;

int index_bf(string a,string b){
	int i = 0;
	int j = 0;
	while(i<a.length() && j < b.length()){
		if(a[i] == b[j]) {
			i++;
			j++;
		}else{
			i = i - j + 1;
			j = 0;
		}
	}
	if(j>=b.length()) return i - b.length();
	else
		return -1;
}

int main(int argc,char* argv[]){
	cout << index_bf("01234baa","ba")<<endl;
	return 0;
}
