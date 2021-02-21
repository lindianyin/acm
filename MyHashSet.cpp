#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <set>
#include <algorithm>
#include <limits>
#include "dbg-macro/dbg.h"
using namespace std;
#define HASH_SIZE 1024
class MyHashSet {
public:
    /** Initialize your data structure here. */
    MyHashSet() {
	hash.resize(HASH_SIZE);
    }
    
    void add(int key) {
	int idx = key % HASH_SIZE;
	vector<int>& item = hash[idx];
	if(item.empty())
		item.push_back(key);
	else{
		bool tag = false;
		for(int i : item){
			if(i == key){
				tag = true;
				break;
			}
		}
		if(!tag)
			item.push_back(key);
	}	
    }
    
    void remove(int key) {
	int idx = key % HASH_SIZE;
	vector<int>& item = hash[idx];
	for(auto it = item.begin();it != item.end();){
		if(*it == key){
			it = item.erase(it);
		}else{
			++it;
		}
	}
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
	int idx = key % HASH_SIZE;
	vector<int>& item = hash[idx];
	bool tag = false;
	for(auto i : item){
		if(i == key){
			tag = true;
			break;
		}
	}	
	return tag;
    }
	vector<vector<int>> hash;
};
int main(int argc,char* argv[]){
	MyHashSet* obj = new MyHashSet;
	obj->add(1);
	obj->add(2);
	obj->remove(1);
	dbg(obj->contains(2));

	return 0;
}
