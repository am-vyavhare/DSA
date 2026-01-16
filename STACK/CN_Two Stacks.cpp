#include <bits/stdc++.h> 
class TwoStack {

public:
    //Data member declartion 
    int top1;  
    int top2;
    int size;
    int* arr;
    
    // Initialize TwoStack.
    TwoStack(int s) {
        this -> size = s;
        top1 = -1;
        top2 = size;   
        arr = new int[size];
    }
    
    // Push in stack 1.
    void push1(int num) {
        //check for space is available or not
        if(top2 - top1 > 1){
            top1++;
            arr[top1] = num;
        }
    }

    // Push in stack 2.
    void push2(int num){
        //check for space is available or not
        if(top2 - top1 > 1){
            top2--;
            arr[top2] = num;
        }
    }

    // Pop from stack 1 and return popped element.
    int pop1(){
        //check for empty or not
        if(top1 >= 0){
            int element = arr[top1];
            top1--;
            return element;
        }
        else
        {
            return -1;
        }
    }

    // Pop from stack 2 and return popped element.
    int pop2(){
        //check for empty or not
        if(top2 < size){
            int element = arr[top2];
            top2++;
            return element;
        }
        else
        {
            return -1;
        }
    }
};
