#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <limits>
#include "dbg-macro/dbg.h"
#include "TreeNode.h"
using namespace std;
class Solution{
public:
	char nextGreatestLetter(vector<char>& letters,char target){
		int l = 0,r = letters.size();
		while(l < r){
			int m = l + (r-l) / 2;
			char c = letters[m];
			if(c <= target){
				l = m + 1;
			}else{
				r = m;	
			}
		}
		return l == letters.size() ? letters[0] : letters[l];
	}
	
};

int main(int argc,char* argv[]){
	Solution s;
	vector<char> letters = {'a','b','c','c','d','e','f'};
	dbg(s.nextGreatestLetter(letters,'f'));
	return 0;
}
