#include <iostream>
#include <string>
#include <vector>
#include "dbg-macro/dbg.h"
using namespace std;
class Solution{
public:
	void reverseString(vector<char>& s){
		if(s.empty())
			return;
		size_t i = 0,j=s.size()-1;
		while(i<j){
			swap(s[i],s[j]);
			i++;
			j--;
		}
	}	
};

int main(int argc,char* argv[]){
	Solution slt;
	vector<char> s={'h','e','l','l','o','w'};
	slt.reverseString(s);
	dbg(s);
	return 0;
}
