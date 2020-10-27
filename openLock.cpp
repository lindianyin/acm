#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <unordered_set>
#include <queue>
#include <algorithm>
#include <limits>
#include "dbg-macro/dbg.h"
using namespace std;

class Solution{
public:
	string plusOne(string str,int i){
		str[i] = str[i] == '9' ?  '0' : str[i]+1;
		return str;
	}
	string downOne(string str,int i){
		str[i] = str[i] == '0' ?  '9' : str[i]-1;
		return str;
	}
    int openLock(vector<string>& deadends, string target) {
		set<string> deadset(deadends.begin(),deadends.end());
		set<string> visited;
		visited.insert("0000");
		queue<string> q;
		q.push("0000");
		int step = 0;
		while(!q.empty()){
			int sz = q.size();
			for(int i = 0;i<sz;i++){
			    string cur = q.front();
			    q.pop();
			    if(deadset.count(cur))
			    	continue;
			    if(cur == target)
			    	return step;
			    for(int j = 0;j<4;j++){
			    	string up = plusOne(cur,j);
			    	if(!visited.count(up)){
			    		q.push(up);
			    		visited.insert(up);
			    	}
			    	string down = downOne(cur,j);
			    	if(!visited.count(down)){
			    		q.push(down);
			    		visited.insert(down);
			    	}
			    }	
			}
			step++;
		}
		return -1;
    }	
};
int main(int argc,char* argv[]){
	Solution s;
	vector<string> deadends = {"0201","0101","0102","1212","2002"};
	string target = "0202";
	int step = s.openLock(deadends,target);	
	dbg(step);
	return 0;
}
