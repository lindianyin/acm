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
using namespace std;
class Solution{
public:
    int numJewelsInStones(string jewels, string stones) {
	int cnt = 0;
	unordered_set<char> j;
	for(auto item : jewels)
		j.insert(item);
	for(auto item : stones){
		if(j.count(item) == 1)
			cnt++;
	}
	return cnt;
    }
	
};

int main(int argc,char* argv[]){
	Solution s;
	dbg(s.numJewelsInStones("aA","aAAbbbb"));
	dbg(s.numJewelsInStones("z","ZZ"));
	return 0;
}
