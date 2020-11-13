#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <limits>
#include "dbg-macro/dbg.h"
using namespace std;
#define LEN 100005
struct P{
	char name[256];
	int t;
};
P Q[LEN];
int head,tail,n;
void enqueue(P x){
	Q[tail] = x;
	tail = (tail + 1) % LEN;
}
P dequeue(){
	P x = Q[head];
	head = (head + 1) % LEN;
	return x;
}


int main(int argc,char* argv[]){
	int n,q;
	//scanf("%d %d",&n,&q);	
	cin >> n >> q;
	for(int i=1;i<=n;i++){
		//scanf("%s %d",Q[i].name,&Q[i].t);
		cin >> Q[i].name >> Q[i].t;
	}
	head = 1;tail = n+1;
	P u;
	int elaps = 0,c;
	while(head != tail){
		u = dequeue();	
		c = min(u.t,q);	
		u.t -= c;
		elaps += c;
		if(u.t > 0)
			enqueue(u);
		else
			printf("%s %d\n",u.name,elaps);
	}
	return 0;
}
