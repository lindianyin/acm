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

linkHead* Union(linkHead* a,linkHead* b){
	linkNode* pa = a->next;
	linkNode* pb = b->next;
	linkNode* pc = a;
	while(pa && pb){
		if(pa->elem < pb->elem){
			pc->next = pa;
			pc = pa;
			pa = pa->next;
		}else if(pa->elem == pb->elem){
			pc->next = pa;
			pc = pa;
			pa = pa->next;
			pb = pb->next;
		}else{
			pc->next = pb;
			pc = pb;
			pb = pb->next;
		}
	}
	pc->next = pa ? pa : pb;
	return a;
}
int main(int argc,char* argv[]){
	linkHead* a = new linkHead;
	InitLinkList(a);
	InsertLinkList(a,0,11);
	InsertLinkList(a,0,6);
	InsertLinkList(a,0,5);
	InsertLinkList(a,0,3);
	linkHead* b = new linkHead;
	InitLinkList(b);
	InsertLinkList(b,0,6);
	InsertLinkList(b,0,3);
	InsertLinkList(b,0,2);
	linkHead* c = Union(a,b);
	linkNode* p = c->next;
	while(p){
		cout << p->elem << std::endl;
		p = p->next;
	}
	return 0;
}
