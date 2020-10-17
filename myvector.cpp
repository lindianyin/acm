#include <vector>
#include <iostream>
using namespace std;
#define MAX_SIZE 100
struct sqlist{
	int len;
	int elem[MAX_SIZE];
};
void InitList(sqlist* list){	
	list->len = 0;
}
bool InsertList(sqlist* list,int idx,int elem){
	if(idx < 0 || idx > list->len || list->len >= MAX_SIZE)
		return false;
	if(idx != list->len){
		for(int i = list->len-1;i>=idx;i--){
			list->elem[i+1] = list->elem[i];
		}	
	}	
	list->elem[idx] = elem;		
	list->len++;
	return true;
}
bool DeleteList(sqlist*list,int idx){
	if(idx<0 || idx>list->len-1)
		return false;
	if(idx != list->len -1){
		for(int i = idx+1;i<list->len;i++){
			list->elem[i-1] = list->elem[i];
		}
	}
	list->len--;
	return  true;
}
bool GetElement(sqlist* list,int idx,int* elem){
	if(idx < 0 || idx>list->len-1)
		return false;
	*elem = list->elem[idx];
	return true;
}
int main(int argc,char* argv[]){
	sqlist list;
	InitList(&list);
	InsertList(&list,0,1);
	InsertList(&list,0,2);
	InsertList(&list,0,3);
	DeleteList(&list,1);
	for(int i=0;i<list.len;i++)
		cout << list.elem[i] << ",";
	return 0;
}
