#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <limits>
#include "dbg-macro/dbg.h"
using namespace std;
class Solution{
public:
    vector<int> dailyTemperatures(vector<int>& T) {
		vector<int> vec(T.size());
		for(int i = 0;i<T.size();i++){
			int current = T[i];
			for(int j = i+1;j<T.size();j++){
				if(T[j] > current){
					vec[i] = (j-i);
					break;
				}
			}
		}
		return vec;
    }	
};

int main(int argc,char* argv[]){
	Solution s;
	vector<int> T = {73, 74, 75, 71, 69, 72, 76, 73};
	vector<int> vec = s.dailyTemperatures(T);
	dbg(vec);
	return 0;
}
