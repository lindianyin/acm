#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <set>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <limits>
#include "dbg-macro/dbg.h"
using namespace std;
class Solution{
public:
	vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
		unordered_map<string,int> tmp;
		for(int i = 0;i<list1.size();i++){
			tmp[list1[i]] = i;
		}
		std::string result;
		int sum_idx = INT32_MAX;
		map<int,vector<string>> m;
		for(int i = 0;i<list2.size();i++){
			if(1 == tmp.count(list2[i])){
				int tmp_sum = i+tmp[list2[i]];
				m[tmp_sum].push_back(list2[i]);
			}	
		}
		if(m.empty()) return {};
		return m.begin()->second;
	}	
};

int main(int argc,char* argv[]){
	Solution s;
	vector<string> list1 = {"Shogun", "Tapioca Express", "Burger King", "KFC"};
	vector<string> list2 = {"Piatti", "The Grill at Torrey Pines", "Hungry Hunter Steakhouse", "Shogun"};
	dbg(s.findRestaurant(list1,list2));
	list1 = {"Shogun", "Tapioca Express", "Burger King", "KFC"};
	list2 = {"KFC", "Shogun", "Burger King"};
	dbg(s.findRestaurant(list1,list2));
	return 0;
}
