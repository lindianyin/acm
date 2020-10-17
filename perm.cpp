#include <vector>
#include <iostream>
#include <string>
using namespace std;
void perm(string& s,int k,int m){
	if(k == m)
		cout << s << endl;
	else{
		for(int i=k;i<=m;i++){
			swap(s[k],s[i]);
			perm(s,k+1,m);
			swap(s[k],s[i]);
		}

	}
		
}
int main(int argc,char* argv[]){
	string s = "abc";
	//perm(s,0,s.size()-1);
	s += 'd';
	cout << s << endl;	
	return 0;
}
