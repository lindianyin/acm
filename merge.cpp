#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
public:
	vector<vector<int>> merge(vector<vector<int>>& intervals) {
		vector<vector<int>> result;
		sort(intervals.begin(),intervals.end(),[](vector<int>& a,vector<int>& b){ return a[0] < b[0];});	
		for(auto it = intervals.begin();it != intervals.end();it++){
			auto item = *it;
			int l = item[0],r=item[1];
			if(result.empty() || result.back()[1]  < l)
				result.push_back({l,r});
			else
				result.back()[1] = max(result.back()[1],r);
		}
		return result;
    }
};

int main(int argc,char* argv[]){
	vector<vector<int>> intervals = {{1,3},{2,6},{8,10},{15,18}};
	Solution s;
	auto result = s.merge(intervals);
	for(auto item : result){
		cout <<  item[0] << "," << item[1] << endl;
	}
	return 0;
}
