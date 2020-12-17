#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <set>
#include <algorithm>
#include <limits>
#include "dbg-macro/dbg.h"
using namespace std;
class MyHashMap {
private:
    vector<int>bucket;
    const int len=1e6;
public:
    /** Initialize your data structure here. */
    MyHashMap() {
        bucket=vector<int>(len,-1);
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        bucket[key%len]=value;
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        return bucket[key%len];
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        bucket[key%len]=-1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
int main(int argc,char* argv[]){
	dbg(1);
	MyHashMap* obj = new MyHashMap();
	obj->put(1,11);
	obj->put(1,12);
	dbg(obj->get(1));	
	obj->remove(1);
	dbg(obj->get(1));	
	
	return 0;
}
