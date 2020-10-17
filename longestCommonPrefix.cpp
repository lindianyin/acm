#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
		if(strs.empty())
			return "";
		std::string& str = strs[0];
		int max = 0;
		for(int i =0;i<str.size();i++){
			char c = str[i];
			int j = 1;
			for(;j<strs.size();j++){
				std::string& r = strs[j];
				if(max >= r.size() || c != r[max])
					break;
			}	
			if(j == strs.size())
				max++;
			else
				break;
		}	
		return std::string(str,0,max);
    }
};
int main(int argc,char* argv[]){
	Solution s;
	//vector<string> strs = {"flowers","flow","flight"};
	//vector<string> strs = {"dog","racecar","car"};
	//vector<string> strs = {"dog"};
	vector<string> strs = {};
	//vector<string> strs = {"dog"};
	cout << s.longestCommonPrefix(strs)<<endl;
	return 0;
}
