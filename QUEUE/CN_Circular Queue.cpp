#include <bits/stdc++.h> 
class CircularQueue{
    public:
    int* arr;
    int front;
    int rear;
    int size;

    CircularQueue(int n){
        size = n;
        arr = new int[size];
        front = rear = -1;
    }

    // Enqueues 'X' into the queue.
    bool enqueue(int value){
        // 1. Check if queue is full
        if((front == 0 && rear == size - 1) || (rear == (front - 1 + size) % size)){
            return false;
        }
        // 2. First element insertion
        else if(front == -1){
            front = rear = 0;
        }
        // 3. Rear wrap around
        else if(rear == size - 1 && front != 0){
            rear = 0;
        }
        // 4. Normal flow
        else{
            rear++;
        }
        
        arr[rear] = value;
        return true;
    }

    // Dequeues top element from queue.
    int dequeue(){
        // 1. Check if empty 
        if(front == -1){
            return -1;
        }

        int val = arr[front];
        arr[front] = -1; // Optional: mark as empty

        // 2. Single element logic
        if(front == rear){
            front = rear = -1;
        }
        // 3. Front wrap around
        else if(front == size - 1){
            front = 0; 
        }
        // 4. Normal flow
        else{
            front++;
        }
        
        return val;
    }
};