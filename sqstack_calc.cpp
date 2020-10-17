#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
using namespace std;
#define MAX_SIZE 10
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

int calc(char* s){
	SqStack* stack = new SqStack;
	InitStack(stack);
	int len = strlen(s);
	int i = 0;
	int j = 0;
	while(i<len && j<len){
		while(isspace(s[i])) i++;
		j = i;
		while(!isspace(s[j])) j++;	
		if(isdigit(s[i]))
			Push(stack,atoi((char*)(s+i)));	
		else{
			int op = s[i];	
			int b,a;
			Pop(stack,&b);
			Pop(stack,&a);
			if(op == '+')
				Push(stack,a+b);	
			else if(op == '-')
				Push(stack,a-b);	
			else if(op == '*')
				Push(stack,a*b);	
			else if(op == '/')
				Push(stack,a/b);	
		}
		i = j;
	}
	int res = 0;
	Pop(stack,&res);
	return res;
}



int main(int argc,char* argv[]){
	char exp[] = "1 2 + 4 *";
	int res = calc(exp);	
	cout << res << endl;
	return 0;
}
