#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
	void setten(vector<vector<int>>& matrix,int i,int j){
		int rz = matrix.size();
		int cz = matrix[0].size();
		for(int r=0;r<rz;r++)
			matrix[r][j] = 0;
		for(int c=0;c<cz;c++)
			matrix[i][c] = 0;
	}
    void setZeroes(vector<vector<int>>& matrix) {
		int rz = matrix.size();
		int cz = matrix[0].size();
		vector<vector<int>> m = matrix;
		for(int i = 0;i<rz;i++){
			for(int j = 0;j<cz;j++){
				if(m[i][j] == 0){
					setten(matrix,i,j);
				}
			}
		}
			
    }
};
int main(int argc,char* argv[]){
	Solution s;
	vector<vector<int>> matrix = {{1,1,1},{1,0,1},{1,1,1}};
	s.setZeroes(matrix);
	for(auto& row : matrix){
		for(auto& item : row){
			cout << item << ",";
		}
		cout << endl;
	}
	return 0;
}
