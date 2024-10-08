/*
641. Design Circular Deque
Solved
Medium
Topics
Companies
Design your implementation of the circular double-ended queue (deque).

Implement the MyCircularDeque class:

MyCircularDeque(int k) Initializes the deque with a maximum size of k.
boolean insertFront() Adds an item at the front of Deque. Returns true if the operation is successful, or false otherwise.
boolean insertLast() Adds an item at the rear of Deque. Returns true if the operation is successful, or false otherwise.
boolean deleteFront() Deletes an item from the front of Deque. Returns true if the operation is successful, or false otherwise.
boolean deleteLast() Deletes an item from the rear of Deque. Returns true if the operation is successful, or false otherwise.
int getFront() Returns the front item from the Deque. Returns -1 if the deque is empty.
int getRear() Returns the last item from Deque. Returns -1 if the deque is empty.
boolean isEmpty() Returns true if the deque is empty, or false otherwise.
boolean isFull() Returns true if the deque is full, or false otherwise.
 

Example 1:

Input
["MyCircularDeque", "insertLast", "insertLast", "insertFront", "insertFront", "getRear", "isFull", "deleteLast", "insertFront", "getFront"]
[[3], [1], [2], [3], [4], [], [], [], [4], []]
Output
[null, true, true, true, false, 2, true, true, true, 4]

Explanation
MyCircularDeque myCircularDeque = new MyCircularDeque(3);
myCircularDeque.insertLast(1);  // return True
myCircularDeque.insertLast(2);  // return True
myCircularDeque.insertFront(3); // return True
myCircularDeque.insertFront(4); // return False, the queue is full.
myCircularDeque.getRear();      // return 2
myCircularDeque.isFull();       // return True
myCircularDeque.deleteLast();   // return True
myCircularDeque.insertFront(4); // return True
myCircularDeque.getFront();     // return 4
 
*/

//Deque is double ended queue
//we should be able to insert and remove at both ends
//points to remember
// 1) for incremet = (front+1)%k  because when reaches to kth index it should be crcular and come to 0
// 2) for decrement = (rear-1+k)%k;  because when reaches -1 index then should be circular and come to k-1.

class MyCircularDeque {
public:
    vector<int> dq;
    int k;
    int front;
    int rear;
    int total;

    MyCircularDeque(int k) {
        dq.resize(k);
        this->k = k;
        front = 0;//intially
        rear = k-1;//intially
        total=0;
    }
    
    bool insertFront(int value) {
        if(isFull()){
            return false;
        }
        dq[front] = value;
        front = (front+1)%k;
        total++;
        return true;
    }
    
    bool insertLast(int value) {
        if(isFull()){
            return false;
        }
        dq[rear] = value;
        rear = (rear-1+k)%k;
        total++;
        return true;
    }
    
    bool deleteFront() {
        if(isEmpty()){
            return false;
        }
        front = (front-1+k)%k;
        total--;
        return true;
    }
    
    bool deleteLast() {
        if(isEmpty()){
            return false;
        }
        rear = (rear+1)%k;
        total--;
        return true;
    }
    
    int getFront() {
        if(isEmpty()){
            return -1;
        }
        return dq[(front-1+k)%k];
    }
    
    int getRear() {
        if(isEmpty()){
            return -1;
        }
        return dq[(rear+1)%k];
    }
    
    bool isEmpty() {
        if(total==0){
            return true;
        }
        return false;
    }
    
    bool isFull() {
        if(total==k){
            return true;
        }
        return false;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
