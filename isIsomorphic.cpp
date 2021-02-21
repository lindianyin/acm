#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <set>
#include <unordered_map>
#include <algorithm>
#include <limits>
#include "dbg-macro/dbg.h"
using namespace std;
class Solution{
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> smap;
        unordered_map<char,char> tmap;
        for(int i = 0; s[i] != '\0'; ++ i){
            char ss = s[i];
            char tt = t[i];
            if(smap.count(ss)){
                if(smap[ss] != tt)    return false;
            }
            else if(tmap.count(tt)){
                if(tmap[tt] != ss)  return false;
            }
            else{
                smap[ss] = tt;
                tmap[tt] = ss;
            }
        }
        return true;
    }
};

int main(int argc,char* argv[]){
	Solution s;
	dbg(s.isIsomorphic("egg","add"));
	dbg(s.isIsomorphic("aba","baa"));
	dbg(s.isIsomorphic("ab","aa"));
	return 0;
}
