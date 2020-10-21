#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <limits>
#include "dbg-macro/dbg.h"
using namespace std;
class MyCircularQueue {
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
		size_ = k;
		base_ = new int[k];
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
		if(isFull()) return false;
		base_[rear_] = value;	
		rear_ = (rear_ + 1) % size_;
		count++;
		return true;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
		if(isEmpty()) return false;
		front_ = (front_+1) % size_;	
		count --;
		return true;
    }
    
    /** Get the front item from the queue. */
    int Front() {
		if(isEmpty()) return -1;
		return base_[front_ % size_];
    }
    
    /** Get the last item from the queue. */
    int Rear() {
		if(isEmpty()) return -1;
		return base_[(front_+count-1)%size_];
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
		return count == 0;
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
		return count == size_;
    }
public:
	int size_ = 0;
	int front_ = 0;
	int rear_ = 0;
	int* base_ = NULL;
	int count = 0;
};

int main(int argc,char* argv[]){
	MyCircularQueue circularQueue(3);
	dbg(circularQueue.enQueue(1));
	dbg(circularQueue.enQueue(2));
	dbg(circularQueue.enQueue(3));
	dbg(circularQueue.enQueue(4));
	dbg(circularQueue.Rear());
	dbg(circularQueue.isFull());
	dbg(circularQueue.deQueue());
	dbg(circularQueue.enQueue(4));
	dbg(circularQueue.Rear());
	return 0;
}
