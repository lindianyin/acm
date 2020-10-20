#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <limits>
#include "dbg-macro/dbg.h"
using namespace std;
class Solution{
public:
	string reverseWords(string s){
		int i = 0,j=0;
		int k;
		while(j<s.size()){
			if(s[j] != ' ' && j != s.size()-1) 
				j++;
			else{
				if(j == s.size() -1)
					k = j;
				else
					k = j -1;
				//dbg(k);
				while(i<k){
					swap(s[i],s[k]);
					i++;
					k--;
				}
				j++;
				i = j;
			}
		}
		return s;
	}	
};

int main(int argc,char* argv[]){
	Solution s;
	dbg(s.reverseWords("hello world"));
	dbg(s.reverseWords("h"));
	dbg(s.reverseWords(""));
	return 0;
}
