#include <iostream>
#include <string>
using namespace std;
class Solution{
public:
	string reverseString(string s){
		size_t i = 0,j=s.size()-1;
		while(i<j){
			swap(s[i],s[j]);
			i++;
			j--;
		}
		return s;
	}	
};

int main(int argc,char* argv[]){
	Solution s;
	cout << s.reverseString("hello")<<endl;
	return 0;
}
