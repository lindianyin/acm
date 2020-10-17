#include <vector>
#include <iostream>
using namespace std;
struct linkNode{
	int elem;
	struct linkNode* next;
	struct linkNode* pre;
};
typedef linkNode linkHead;
void InitLinkList(linkHead* head){	
	head->next = NULL;
	head->pre = NULL;
}
bool InsertLinkList(linkHead* head,int idx,int elem){
	linkNode* node = new linkNode;
	node->elem = elem;
	node->next = NULL;	
	node->pre = NULL;
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
	p->next->pre = p;
	delete tmp;	
}
int main(int argc,char* argv[]){
	linkHead head;
	InitLinkList(&head);
	InsertLinkList(&head,0,1);
	InsertLinkList(&head,0,2);
	InsertLinkList(&head,0,3);
	DeleteLinkList(&head,1);
	linkNode* p = head.next;
	while(p){
		cout << p->elem << std::endl;
		p = p->next;
	}
	return 0;
}
