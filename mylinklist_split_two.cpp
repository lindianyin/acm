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

void SplitTwo(linkHead* a,linkHead* b,linkHead* c){
	linkNode* pa = a->next;
	linkNode* pb = b;
	linkNode* pc = c;	
	while(pa){
		if(pa->elem < 0){
			pb->next = pa;
			pb = pa;
		}else{
			pc->next = pa;	
			pc=pa;
		}
		pa = pa->next;
	}
	pb->next = NULL;
	pc->next = NULL;	
}
int main(int argc,char* argv[]){
	linkHead* a = new linkHead;
	linkHead* b = new linkHead;
	linkHead* c = new linkHead;
	InitLinkList(a);
	InitLinkList(b);
	InitLinkList(c);
	InsertLinkList(a,0,11);
	InsertLinkList(a,0,-6);
	InsertLinkList(a,0,-5);
	InsertLinkList(a,0,3);
	SplitTwo(a,b,c);
	linkNode* pb = b->next;
	while(pb){
		cout << pb->elem << endl;
		pb = pb->next;
	}
	cout << endl;
	linkNode* pc = c->next;
	while(pc){
		cout << pc->elem << std::endl;
		pc = pc->next;
	}
	return 0;
}
