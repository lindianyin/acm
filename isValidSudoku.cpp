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
    bool isValidSudoku(vector<vector<char>>& board) {
	unordered_map<int,int> rows[9];
	unordered_map<int,int> cols[9];
	unordered_map<int,int> boxs[9];
	for(int i = 0;i<9;i++){
		for(int j = 0;j<9;j++){
			char num = board[i][j];
			if(num != '.'){
				int n = num;
				int box_index = (i/3)*3 + j/3;
				rows[i][n]++;
				cols[j][n]++;
				boxs[box_index][n]++;
				
				if(rows[i][n] > 1 || cols[j][n] > 1 || boxs[box_index][n] > 1)
					return false;
			}
		}
	}
	return true;
    }
	
};
int main(int argc,char* argv[]){
	vector<vector<char>> board=
{
  {8,3,'.','.',7,'.','.','.','.'},
  {6,'.','.',1,9,5,'.','.','.'},
  {'.',9,8,'.','.','.','.',6,'.'},
  {8,'.','.','.',6,'.','.','.',3},
  {4,'.','.',8,'.',3,'.','.',1},
  {7,'.','.','.',2,'.','.','.',6},
  {'.',6,'.','.','.','.',2,8,'.'},
  {'.','.','.',4,1,9,'.','.',5},
  {'.','.','.','.',8,'.','.',7,9}
};
	Solution s;
	dbg(s.isValidSudoku(board));
	return 0;
}
