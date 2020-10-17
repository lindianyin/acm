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
	int j = 0;
	while(p && j < idx){
		p = p->next;
		j++;
	}
	if(!p ||j > idx)
		return false;
	node->next = p->next;
	p->next = node;
	return true;
}
bool InsertLinkList_1(linkHead* head,int idx,int elem){
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
	while(p && j<idx){
		p = p->next;	
		j++;
	}
	if(!p || j > idx)
		return false;
	linkNode* tmp = p->next;
	p->next = p->next->next;
	delete tmp;	
}
bool DeleteLinkList_1(linkHead* head,int idx){
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
int main(int argc,char* argv[]){
	linkHead head;
	InitLinkList(&head);
	InsertLinkList_1(&head,0,1);
	InsertLinkList_1(&head,0,2);
	InsertLinkList_1(&head,0,3);
	DeleteLinkList_1(&head,1);
	linkNode* p = head.next;
	while(p){
		cout << p->elem << std::endl;
		p = p->next;
	}
	return 0;
}
