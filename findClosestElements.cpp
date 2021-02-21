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
#include "TreeNode.h"
using namespace std;
class Solution{
public:
	vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int l = 0, r = arr.size() - k;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (x - arr[mid] > arr[mid + k] - x) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        //以l作为起始索引，长度为k
        vector<int> res;
        for (int i = 0; i < k; i++) {
            res.push_back(arr[i + l]);
        }
        return res;

    }
};

int main(int argc,char* argv[]){
	vector<int> arr = {1,2,3,4,5};
	int k = 4,x = -1;
	Solution s;
	dbg(s.findClosestElements(arr,k,x));
	return 0;
}
