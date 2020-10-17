#include <iostream>
using namespace std;
#define MAX_SIZE 5
struct SqStack{
	int* base;
	int* top;
};
void InitStack(SqStack* stack){
	stack->base = stack->top = new int[MAX_SIZE];
}
int Size(SqStack* stack){
	return stack->top - stack->base;
}
bool Push(SqStack* stack,int elem){
	if(Size(stack) >= MAX_SIZE) return false;
	*stack->top++ = elem;
	return true;
}
bool Pop(SqStack* stack,int* elem){
	if(Size(stack) == 0) return false;
	*elem = *(--stack->top);
	return true;
}
bool Empty(SqStack* stack){
	return stack->base == stack->top;
}
bool Top(SqStack* stack,int* elem){
	if(Empty(stack)) return false;
	*elem = *(stack->top -1);
	return true;
}
void Print(SqStack* stack){
	for(int i=0;i<Size(stack);i++){
		cout << stack->base[i] << ",";
	}
	cout << endl;
}
int main(int argc,char* argv[]){
	SqStack* stack = new SqStack;
	InitStack(stack);
	Push(stack,1);
	Push(stack,2);
	Push(stack,3);
	Push(stack,4);
	Push(stack,5);
	Push(stack,6);
	int elem;
	Pop(stack,&elem);
	Print(stack);
	cout << elem << endl;
	
	return 0;
}
