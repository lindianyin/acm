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
	
};
class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {

    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (mp.count(val)) {
            return false;
        }

        nums.push_back(val);
        mp[val] = nums.size() - 1;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (!mp.count(val)) {
            return false;
        }

        auto iter = mp.find(val);
        auto num = iter->first;
        auto index = iter->second;
        auto back = nums.back();
        nums[index] = back; // Use the last one to overwrite the one to be deleted
        mp[back] = index; // update the map: from [num -> index] to [back -> index]
        mp.erase(num);  // delete [num -> index] mapping
        nums.pop_back(); // pop_back the last element, since already move to index

        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return nums[random() % nums.size()];
    }

private:
    unordered_map<int, int> mp;
    vector<int> nums;
};

int main(int argc,char* argv[]){
	Solution s;
 	RandomizedSet* obj = new RandomizedSet();
 	bool param_1 = obj->insert(1);
 	bool param_2 = obj->insert(2);
 	bool param_3 = obj->remove(2);
 	int param_4 = obj->getRandom();
	dbg(param_4);
	return 0;
}
