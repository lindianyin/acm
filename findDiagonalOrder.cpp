#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	vector<int> findDiagonalOrder(vector<vector<int>>& matrix){
		if(matrix.empty())
			return vector<int>();
		vector<int> result;
		int n = matrix.size();
		int m = matrix[0].size();
		int line = 0;
		vector<int> tmp;
		for(int k = 0;k<m;k++){
			if(k == m-1){
				for(int p = 0;p<n;p++){
					int i = p,j=k;
					while(i>=0 && j>=0 && i < n && j < m){
						tmp.push_back(matrix[i][j]);
						//cout << matrix[i][j];
						i++;j--;
					}
					if(line++ % 2 == 0){
						reverse(tmp.begin(),tmp.end());	
					}
					result.insert(result.end(),tmp.begin(),tmp.end());
					tmp.clear();
				}
			}else{
				int i = 0,j=k;
				while(i>=0 && j>=0 && i < n && j < m){
					tmp.push_back(matrix[i][j]);
					//cout << matrix[i][j];
					i++;j--;
				}
				if(line++ % 2 == 0){
					reverse(tmp.begin(),tmp.end());	
				}
				result.insert(result.end(),tmp.begin(),tmp.end());
				tmp.clear();
			}
		}
		//cout << endl;
		return result;
	}
};
int main(int argc,char* argv[]){
	Solution s;
	vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
	auto ret = s.findDiagonalOrder(matrix);
	for(auto& item : ret){
		cout << item << ",";
	}
	cout << endl;
	return 0;
}
