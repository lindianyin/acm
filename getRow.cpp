#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <limits>
#include "dbg-macro/dbg.h"
using namespace std;
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
		if(numRows == 0) return {};
		if(numRows == 1) return {{1}};
    	vector<vector<int>> result = {{1},{1,1}}; 
		for(int i = 2;i<numRows;i++){
			vector<int> vec;
			for(int j = 0;j<i+1;j++){
				if(j == 0 || j == i){
					vec.push_back(1);
				}else{
					int c = result[i-1][j] + result[i-1][j-1];
					vec.push_back(c);
				}
			}	
			result.push_back(vec);
		}
		return result;
    }
    vector<int> getRow(int rowIndex) {
		return generate(rowIndex+1)[rowIndex];
    }
};
int main(int argc,char* argv[]){
	Solution s;
	vector<int> vec = s.getRow(3);
	dbg(vec);
	return 0;
}
