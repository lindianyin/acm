#include <vector>
#include <iostream>
using namespace std;
struct linkNode{
	int elem = 0;
	struct linkNode* next = NULL;
	struct linkNode* pre = NULL;
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
		node->pre = p;
	}else{
		for(int i=0;i<idx && p;i++){
			p = p->next;	
		}
		if(!p)
			return false;	
		node->next = p->next;
		p->next = node;
		node->next->pre = node;
		node->pre = p;
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
void PrintLinkList(linkHead* head){
	linkNode* p = head->next;
	while(p){
		cout << p->elem << ",";
		p = p->next;
	}
	cout << endl;
}
void Change(linkHead* a,int elem){
	linkNode* r = FindElement(a,elem);//p q r s
	linkNode* s = r->next;
	linkNode* q = r->pre;
	linkNode* p = q->pre; 
	p->next = r;
	r->next = q;
	q->next = s;
	s->pre = q;
	q->pre = r;
	r->pre = p;	
}
int main(int argc,char* argv[]){
	linkHead* a = new linkHead;
	InitLinkList(a);
	InsertLinkList(a,0,11);
	InsertLinkList(a,0,6);
	InsertLinkList(a,0,5);
	InsertLinkList(a,0,3);
	Change(a,6);
	PrintLinkList(a);
	return 0;
}
