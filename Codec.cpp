#include <iostream>
#include <string>
#include <cstring>
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
using namespace std;
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
       ostringstream ss;
       serialize(root, ss);
       return ss.str();
    }

    TreeNode* deserialize(string data) {
       istringstream ss(data);
       return deserialize(ss);
    }

private:
    void serialize(TreeNode* root, ostringstream& ss) {
        if (!root) {
            ss << "# ";
            return;
        }

        ss << to_string(root->val) << " ";
        serialize(root->left, ss);
        serialize(root->right, ss);
    }

    TreeNode* deserialize(istringstream& ss) {
        TreeNode* root;
        string str;
        ss >> str;
	dbg(str);
        if (str == "#") {
            root = nullptr;
        } else {
            root = new TreeNode(stoi(str));
            auto left = deserialize(ss);
            auto right = deserialize(ss);
            root->left = left;
            root->right = right;
        }

        return root;
    }
};
int main(int argc,char* argv[]){
	Codec c;
	TreeNode* one = new TreeNode(1);
	TreeNode* two = new TreeNode(2);
	TreeNode* three = new TreeNode(3);
	TreeNode* four = new TreeNode(4);
	TreeNode* five = new TreeNode(5);
	one->left = two;
	one->right = three;
	three->left = four;
	three->right = five;
	string str = c.serialize(one);
	dbg(str);
	TreeNode* root = c.deserialize(str);
	return 0;
}
