#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <algorithm>
#include <limits>
#include "dbg-macro/dbg.h"
using namespace std;
class Solution {
public:
    const int dx[4] = {1, 0, 0, -1};
    const int dy[4] = {0, 1, -1, 0};
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int currColor = image[sr][sc];
        if (currColor == newColor) return image;
        int n = image.size(), m = image[0].size();
        queue<pair<int, int>> que;
        que.emplace(sr, sc);
        image[sr][sc] = newColor;
        while (!que.empty()) {
            int x = que.front().first, y = que.front().second;
            que.pop();
            for (int i = 0; i < 4; i++) {
                int mx = x + dx[i], my = y + dy[i];
                if (mx >= 0 && mx < n && my >= 0 && my < m && image[mx][my] == currColor) {
                    que.emplace(mx, my);
                    image[mx][my] = newColor;
                }
            }
        }
        return image;
    }
};

int main(int argc,char* argv[]){
	Solution s;
	vector<vector<int>> image = {{1,1,1},{1,1,0},{1,0,1}};
	dbg(s.floodFill(image,1,1,2));
	return 0;
}
