#include <iostream>
using namespace std;
#define MAX_SIZE 5
struct SqQueue{
	int* base;
	int front;
	int rear;
};
void Init(SqQueue* queue){
	queue->base = new int[MAX_SIZE];
	queue->front = queue->rear = 0;
}
int Size(SqQueue* queue){
	return (queue->front - queue->rear + MAX_SIZE) % MAX_SIZE;
}
bool Empty(SqQueue* queue){
	return 0 == Size(queue);
}
bool Full(SqQueue* queue){
	return Size(queue) == (MAX_SIZE - 1);
}
bool Print(SqQueue* queue){
	int size = Size(queue);
	int front = queue->front;
	while(size--){
		cout << queue->base[(front++)%MAX_SIZE] << ",";
	}
	cout << endl;
}
bool EnQueue(SqQueue* queue,int elem){
	queue->base[queue->rear%MAX_SIZE] = elem;
	queue->rear = (queue->rear+1) % MAX_SIZE;
	return true;
}
bool DeQueue(SqQueue* queue,int* elem){
	*elem = queue->base[queue->front]; 
	queue->front = (queue->front+1) % MAX_SIZE;
	return true;
}

int main(int argc,char* argv[]){
	SqQueue* queue = new SqQueue;
	Init(queue);
	EnQueue(queue,1);
	EnQueue(queue,2);
	EnQueue(queue,3);
	EnQueue(queue,4);
	EnQueue(queue,5);
	EnQueue(queue,6);
	Print(queue);	
	return 0;
}
