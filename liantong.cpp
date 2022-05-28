#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <map>
#include <queue>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <limits>
#ifdef DBG
#include "dbg-macro/dbg.h"
#endif
#include "TreeNode.h"
using namespace std;
class Solution{
public:
	
};
using namespace std;

class graph {
public:
    vector<vector<int> > g;  // 图的领接表
    graph(int V, bool directed=false){
        this->V=V;  // 需传入图的顶点数
        this->directed = directed;  // 是否为有向图
        // g初始化为V个空的vector, 表示每一个g[i]都为空, 即没有任和边
        g = vector<vector<int> >(V, vector<int>());
    }
    ~graph(){};
    void addEdge(int v, int w);  // 顶点v与w有一条边
    int getV() { return V; }  // 取出顶点数
    int getE() { return E; }  // 取出边数

private:
    int V = 0;  // 顶点数
    int E = 0;  // 边数
    bool directed;  // 是否为有向图

};

void graph::addEdge(int v, int w) {
    assert(v>=0 && v<V);
    assert(w>=0 && w<V);
    g[v].push_back(w);
    if(!directed) g[w].push_back(v);  // 若不是有向图则w与v也有一条边
    E++;
}
class Component {
private:
    graph &G;  // 图的引用
    bool *visited;  // 记录节点是否被访问
    int ccount;  // 连通分量个数
    int *id;  // 给每个顶点所属的连通分量标号

    void dfs(int v);  // 从顶点v开始进行dfs
public:
    Component(graph &graph): G(graph)
    {
        visited = new bool[G.getV()];
        id = new int[G.getV()];
        ccount = 0;
        for (int i = 0; i < G.getV(); ++i) {
            visited[i] = false;
            id[i] = -1;
        }

        for (int i = 0; i < G.getV(); ++i) {
            if(!visited[i])
            {
                dfs(i);
                ccount++;
            }
        }
    }

    ~Component(){
        delete[] visited;
        delete[] id;
    }

    // 返回连通分量个数
    int count()
    {
        return ccount;
    }

    // 查询v和w是否连通
    bool isConnected(int v, int w)
    {
        return id[v]==id[w];
    }

    // 以文字形式显示图的连通分量具体情况
    void verbose()
    {
        for (int i = 1; i <= ccount; ++i) {
            cout << "Component " << i << " Vertex:";
            for (int j = 0; j < G.getV(); ++j) {
                if(id[j] == i-1) cout << " " << j;
            }
            cout << endl;
        }
    }
};

void Component::dfs(int v) {
    visited[v] = true;
    id[v] = ccount;
    // 遍历图G的顶点v的领接表
    for (int i = 0; i < G.g[v].size(); ++i) {
        if(!visited[G.g[v][i]])
            dfs(G.g[v][i]);
    }
}
int main(int argc,char* argv[]){
	Solution s;
	dbg(1);
	int cnt,paircnt,p1,p2 = 0;
	cin >> cnt >> paircnt;
	dbg(cnt);
   	graph G(cnt, false); // 建立顶点个数为6的图
	for(int i=0;i<paircnt;i++){
		cin >> p1 >> p2;
		dbg(p1);
		dbg(p2);
    		G.addEdge(p1, p2);
	}

    	Component component(G);
    	cout << "连通分量个数：" << component.count() << endl;  // 打印连通分量个数
    	cout << "1，2点是否连通：" << component.isConnected(1, 2) << endl;  // 判断两点是否连通
    	cout << "1，3点是否连通：" <<component.isConnected(1, 3) << endl;
    	component.verbose();  // 显示具体信息
	return 0;
}
