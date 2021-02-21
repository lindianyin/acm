#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <set>
#include <algorithm>
#include <limits>
#include "dbg-macro/dbg.h"
using namespace std;
class Solution{
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
		set<int> visited;
		stack<int> s;
		s.push(0);
		visited.insert(0);
		while(!s.empty()){
			int cur = s.top();
			s.pop();
			vector<int> v = rooms[cur];
			for(int i = 0;i<v.size();i++){
				if(visited.count(v[i]) == 0){
					s.push(v[i]);
					visited.insert(v[i]);
				}
			}
		}	
		//dbg(visited.size());
		return visited.size() == rooms.size();
    }	
};

int main(int argc,char* argv[]){
	Solution s;
	vector<vector<int>> rooms = {{1},{2},{3},{}};
	dbg(s.canVisitAllRooms(rooms));
	rooms = {{1,3},{3,0,1},{2},{0}};
	dbg(s.canVisitAllRooms(rooms));
	return 0;
}
