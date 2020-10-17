#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;
class Solution {
public:
	int find(vector<int>& parent,int x){
		while(parent[x] != x)
			x = parent[x];
		return x;
	}
	void unionn(vector<int>& parent,int p,int q){
		int rp = find(parent,p);
		int rq = find(parent,q);
		if(rp != rq){
			parent[rp] = rq;
			count--;
		}
	}
    int findCircleNum(vector<vector<int>>& M) {
		count = M.size();
		vector<int> parent(M.size(),0);
		for(int i= 0;i<M.size();i++){
			parent[i] = i;
		}	
		for(int i = 0;i<M.size();i++){
			for(int j=0;j<M.size();j++){
				if(M[i][j] == 1 && i != j){
					unionn(parent,i,j);
				}
			}
		}
		return count;
    }
	int count = 0;
};

int main(int argc,char* argv[]){
	Solution s;
	vector<vector<int>> M = {{1,1,0},{1,1,0},{0,0,1}};
	M = {{1,1,0},{1,1,1},{0,1,1}};
	M = {{1,0,0,1},{0,1,1,0},{0,1,1,1},{1,0,1,1}};
	int num = s.findCircleNum(M);
	cout << num << endl;




	return 0;
}
