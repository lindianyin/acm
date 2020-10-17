#include <iostream>
#include <string>
#include <deque>
using namespace std;
class Solution {
public:
    string reverseWords(string s) {
        int left = 0, right = s.size() - 1;
        // 去掉字符串开头的空白字符
        while (left <= right && s[left] == ' ') ++left;

        // 去掉字符串末尾的空白字符
        while (left <= right && s[right] == ' ') --right;

        deque<string> d;
        string word;

        while (left <= right) {
            char c = s[left];
            if (word.size() && c == ' ') {
                // 将单词 push 到队列的头部
                d.push_front(move(word));
                word = "";
            }
            else if (c != ' ') {
                word += c;
            }
            ++left;
        }
        d.push_front(move(word));
        
        string ans;
        while (!d.empty()) {
            ans += d.front();
            d.pop_front();
            if (!d.empty()) ans += ' ';
        }
        return ans;
    }
};
int main(int argc,char* argv[]){
	Solution slt;
	std::string s = "the sky is blue";
	s = "  hello world!  ";
	s = "a good   example";
	//s = "  Bob    Loves  Alice   ";
	//s = "Alice does not even like bob";
	//s = " hello ";
	cout <<slt.reverseWords(s)<<"$"<<endl;
	return 0;
}
