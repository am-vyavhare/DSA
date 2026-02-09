#include <bits/stdc++.h> 
class Queue {
    //variable for array and front and rear
    int* arr;
    int size;
    int rear;
    int qfront;
public:
    Queue() {
    // Implement the Constructor
        size = 1000;
        arr = new int[size];
        qfront = 0;
        rear = 0;
    }

    /*----------------- Public Functions of Queue -----------------*/
    bool isEmpty(){
        //check if both pointer point to same postion
        if(qfront == rear){
            return true;
        }
        return false;
    }

    void enqueue(int data) {
        //check if queue is full
        if(rear == size){
            // cout<<"Queue is Full";
        }
        else{
            arr[rear] = data;
            rear++;
        }
    }

    int dequeue() {
        // check if empty then remove
        if(qfront == rear){
            return -1;
        }
        else{
            int val = arr[qfront];
            arr[qfront] = -1;
            qfront++;
            //if after removal the queue is empty then reset front and rear to 0
            if(qfront == rear){
                qfront = rear = 0;
            }
            return val;
        }
    }

    int front() {
        // check empty otherwise return
        if(qfront == rear){
            return -1;
        }
        else{
            return arr[qfront];
        }
    }
};