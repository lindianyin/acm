#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <unordered_set>
#include <queue>
#include <algorithm>
#include <limits>
#include <cmath>
#include "dbg-macro/dbg.h"
using namespace std;
class Solution {
public:
	 int numSquares(int n) {
    	set<int> square_nums;
    	for (int i = 1; i * i <= n; ++i) {
      		square_nums.insert(i * i);
    	}
    	set<int> queue;
    	queue.insert(n);

    	int level = 0;
    	while (queue.size() > 0) {
      		level += 1;
      		set<int> next_queue;
      		
			for (int remainder : queue) {
        		for (int square : square_nums) {
          			if (remainder == square) {
            			return level;
          			} else if (remainder < square) {
            			break;
          			} else {
            			next_queue.insert(remainder - square);
          			}
        		}
      		}
    		queue = next_queue;
    	}
    	return level;
  }
};
int main(int argc,char* argv[]){
	Solution s;
	int n = 13;
	int cnt = s.numSquares(n);	
	dbg(cnt);
	return 0;
}
