#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <limits>
#include "dbg-macro/dbg.h"
using namespace std;
class Solution {
private:
    // 自定义比较函数（小根堆）
    struct cmp {
        bool operator ()(const pair<int, int>& m, const pair<int, int>& n)
        {
            return m.second > n.second; // 小的优先级高
        }
    };

public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        unordered_map<int, int> cnt_dic;// map<nums[i],对应出现的次数>
        // 定义一个小顶堆,"priority_queue<Type, Container, Functional>"
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> max_heap;
        vector<int> res;            // 保存结果
        for (auto &i : nums)        // 统计出现频率
            cnt_dic[i]++;
        // 用固定大小为k的小顶堆，扫描所有频率的数值
        // 在堆的不断调整中，小的元素不断被弹出，剩下的就是最大的k个 
        for (auto &iter : cnt_dic)
        {
            max_heap.push(iter);
            if (max_heap.size() > k)// 固定堆的大小为k
                max_heap.pop();
        }
        // 将堆中元素弹出到结果数组中
        for (int i = 0; i < k; i++)
        {
            res.push_back(max_heap.top().first);
            max_heap.pop();
        }
        return res;
    }
};
int main(int argc,char* argv[]){
	Solution s;
	vector<int> nums = {1,1,1,2,2,3};
	int k = 2;
	dbg(s.topKFrequent(nums,k));
	return 0;
}
