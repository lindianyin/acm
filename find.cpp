#include <iostream>
#include <string>
#include <vector>
#include "dbg-macro/dbg.h"
using namespace std;
class Solution{
public:
	
};

int main(int argc,char* argv[]){
	std::string a="prop1122";
	int idx = a.find("prop");
	dbg(idx);
	int idx1 = a.find("sr");
	dbg(idx1);	
	return 0;
}
