#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <set>
#include <queue>
#include <algorithm>
#include <limits>
#include "dbg-macro/dbg.h"
using namespace std;

class Solution {
private:

public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
    	int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dist(m, vector<int>(n));
        vector<vector<int>> seen(m, vector<int>(n));
        queue<pair<int, int>> q;
        // 将所有的 0 添加进初始队列中
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    q.emplace(i, j);
                    seen[i][j] = 1;
                }
            }
        }
		int step = 0;
        // 广度优先搜索
        while (!q.empty()) {
			int size = q.size();
			for(int i = 0;i<size;i++){
				pair<int,int> cur = q.front();
				q.pop();
				int x = cur.first,y=cur.second;
				if(matrix[x][y] == 1)
					dist[x][y] = step;
				for(int j = 0;j<4;j++){
					int newx = x + dirs[j][0];	
					int newy = y + dirs[j][1];	
					if( newx < 0 || newx >=m || newy < 0 || newy >=n || seen[newx][newy] == 1)
						continue;
					q.emplace(newx,newy);
					seen[newx][newy] = 1;
				} 
			}
			step++;
        }
        return dist;
    }
};

int main(int argc,char* argv[]){
	vector<vector<int>> matrix = {{0,0,0},{0,1,0},{0,0,0}}; 
	Solution s;
	dbg(s.updateMatrix(matrix));
	matrix = {{0,0,0},{0,1,0},{1,1,1}}; 
	dbg(s.updateMatrix(matrix));
	return 0;
}
