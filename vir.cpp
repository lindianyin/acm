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
	virtual void foo(){
		cout << "foo"<<endl;	
		bar();
		
	}	
	virtual void bar(){
		cout << "bar"<<endl;	
	}
};
class SubSolu : public Solution{
public:
	virtual void bar(){
		cout << "subbar" << endl;
	}
};
//一卒书城
int main(int argc,char* argv[]){
	SubSolu sub;
	Solution* ps = &sub;
	ps->foo();
	return 0;
}
