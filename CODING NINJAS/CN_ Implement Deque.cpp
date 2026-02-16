#include <bits/stdc++.h> 
class Deque
{
public:
    int* arr;
    int size;
    int front;
    int rear;
    // Initialize your data structure.
    Deque(int n)
    {
        //initialize all variables and create array with dynamic size
        size = n;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    // Pushes 'X' in the front of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushFront(int x)
    {
        //check if full then return false
        if(isFull()){
            return false;
        }
        //check if empty then set both pointer to 0
        if(isEmpty()){
            front = rear = 0;
        }
        else if(front == 0){//if front at first then move to last for cycle
            front = size - 1;
        }
        else{   //normal situation
            front--;
        }
        //insert and return true
        arr[front]=x;
        return true;
    }

    // Pushes 'X' in the back of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushRear(int x)
    {
        //if full then return false
        if(isFull()){
            return false;
        }
        //check if empty then set both pointer to 0
        if(isEmpty()){
            front = rear = 0;
        }
        else if(rear == size -1){ // if rear is at last then maintain cycle
            rear = 0;
        }
        else{ //normal situation
            rear++;
        }
        //insert and return true
        arr[rear] = x;
        return true;
    }

    // Pops an element from the front of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popFront()
    {
        //if empty return -1
        if(isEmpty()){
            return -1;
        }
        //store the returning element
        int pop_element = arr[front];
        arr[front] = -1;
        //if single element then set both pointer to -1
        if(front == rear){
            front = rear = -1;
        }
        else if(front == size - 1){//if front at last then move to first for cyclic nature
            front = 0;
        }
        else{   //normal situation
            front++;
        }
        return pop_element;
    }

    // Pops an element from the back of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popRear()
    {
        //if empty then return -1
        if(isEmpty()){
            return -1;
        }
        //store the pop element for return
        int pop_element = arr[rear];
        arr[rear] = -1;
        //if single element
        if(front == rear){
            front = rear = -1;
        }
        else if(rear == 0){//if rear is at first index then 
        //return to last for cycle maintain
            rear = size -1;
        }
        else{   //normal situation
            rear--;
        }
        return pop_element;
    }

    // Returns the first element of the deque. If the deque is empty, it returns -1.
    int getFront()
    {
        //if not empty then return
        if(!isEmpty()){
            return arr[front];
        }
        return -1;
    }

    // Returns the last element of the deque. If the deque is empty, it returns -1.
    int getRear()
    {
        //if not empty then return
        if(!isEmpty()){
            return arr[rear];
        }
        return -1;
    }

    // Returns true if the deque is empty. Otherwise returns false.
    bool isEmpty()
    {
        //empty condition
        if(front == -1){
            return true;
        }
        else{
            return false;
        }
    }

    // Returns true if the deque is full. Otherwise returns false.
    bool isFull()
    {
        //check all condition of full then return true
        if((front == 0 && rear == size -1) || ((front != 0) && rear == (front-1)%(size-1))){
            return true;
        }
        else{
            return false;
        }
    }
};