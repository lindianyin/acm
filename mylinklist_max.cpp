#include <vector>
#include <iostream>
using namespace std;
struct linkNode{
	int elem;
	struct linkNode* next;
};
typedef linkNode linkHead;
void InitLinkList(linkHead* head){	
	head->next = NULL;
}
bool InsertLinkList(linkHead* head,int idx,int elem){
	linkNode* node = new linkNode;
	node->elem = elem;
	node->next = NULL;	
	linkNode* p = head;
	if(p->next == NULL && idx == 0){
		p->next = node;
	}else{
		for(int i=0;i<idx && p;i++){
			p = p->next;	
		}
		if(!p)
			return false;	
		node->next = p->next;
		p->next = node;
	}
	return true;
}
bool DeleteLinkList(linkHead* head,int idx){
	int j=0;
	linkNode* p = head; //^1->2->3 j=3 idx = 2 p->2
	for(int i = 0;i<idx && p;i++)
		p = p->next;
	if(!p)
		return false;
	linkNode* tmp = p->next;
	p->next = p->next->next;
	delete tmp;	
}
linkNode* FindElement(linkHead* head,int elem){
	linkNode* p = head->next;
	while(p){
		if(p->elem == elem)
			return p;
		else
			p = p->next;
	}
	return NULL;
}

linkNode* MaxNode(linkHead* a){
	linkNode* pa = a->next;
	linkNode* pmax = NULL;
	while(pa){
		if(pmax == NULL){
			pmax = pa;
		}else{
			if(pa->elem > pmax->elem){
				pmax = pa;
			}
		}
		pa = pa->next;
	}
	return pmax;
}
int Max(linkHead* a){
	if(a->next == NULL)
		return a->elem;
	else
		return max(a->elem,Max(a->next));
}
int Cnt(linkHead* a){
	if(a->next == NULL)
		return 0;
	else
		return 1 + Cnt(a->next);
}
int Avg(linkHead* a,int cur_sum,int n){
	if(a->next == NULL){
		return (a->elem + cur_sum) / n;
	}
	else
		return Avg(a->next,cur_sum+a->elem,n+1);
}
int main(int argc,char* argv[]){
	linkHead* a = new linkHead;
	InitLinkList(a);
	InsertLinkList(a,0,9);
	InsertLinkList(a,0,6);
	InsertLinkList(a,0,6);
	InsertLinkList(a,0,3);
	linkNode* pmax = MaxNode(a);
	cout << pmax->elem << endl;
	cout << Max(a) << endl;
	cout << Cnt(a) << endl;
	cout << Avg(a,0,0) << endl;
	return 0;
}
