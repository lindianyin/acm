#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <map>
#include <queue>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <limits>
#ifdef DBG
#include "dbg-macro/dbg.h"
#endif
#include "TreeNode.h"
using namespace std;
class Solution{
public:
	int x = 1;	
};
std::ostream& operator<<(std::ostream& out, const Solution& v) {
  out << v.x <<" ";
  return out;
}
int main(int argc,char* argv[]){
	vector<Solution> arr[4];	
	vector<Solution> ss = {{1},{2},{3}};
	arr[1] = ss;	
	arr[0] = ss;	
	dbg(arr);
	return 0;
}
