#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <limits>
//#include "dbg-macro/dbg.h"
using namespace std;
class Solution{
public:
	bool is_runnian(int year){
		if((year % 4) == 0 && (year % 100) != 0)
			return true;
		if(year % 400 == 0)
			return true;
		return false;
	}	
};

int main(int argc,char* argv[]){
	Solution s;
	int year;
	cin >> year;
	bool ret = s.is_runnian(year);
	if(ret)
		cout << "yes" << endl;
	else
		cout << "no" << endl;
	return 0;
}
