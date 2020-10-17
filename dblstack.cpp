#include <iostream>
using namespace std;
#define MAX_SIZE 10
struct DblStack{
	int* elem;	
	int bot[2];
	int top[2];
};
void Init(DblStack* s){
	s->bot[0] = -1;
	s->top[0] = -1;
	s->bot[1] = MAX_SIZE;
	s->top[1] = MAX_SIZE;
	s->elem = new int[MAX_SIZE];
}
void Push(DblStack* s,int e,int d){
	if(0 == d){
		s->elem[++s->top[0]] = e;	
	}else if(1 == d){
		s->elem[--s->top[1]] = e;
	}
}
void Pop(DblStack* s,int d,int *e){
	if(0 == d){
		*e = s->elem[s->top[0]--];
	}else if(1 == d){
		*e = s->elem[s->top[1]++];
	}
}
int main(int argc,char* argv[]){

}
