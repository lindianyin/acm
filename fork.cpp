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
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/prctl.h>

using namespace std;
__attribute__((constructor)) void before_main() {
	cout << "before main" << endl; 
	int childpid;
	int status;
	if ((childpid = fork()) == 0) {
		prctl(PR_SET_PDEATHSIG,SIGKILL);
		while(true){
			cout << "child" << endl;
			sleep(5);
		}
	}else{
		cout << "parent" << endl;
		wait(&status);
	}
}
int main(int argc,char* argv[]){
	dbg(1);
	return 0;
}
