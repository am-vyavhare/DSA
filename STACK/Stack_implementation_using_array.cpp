#include<iostream>
#include<stack>
using namespace std;

class Stack{
    //properties
    public:
        int *arr;
        int top;
        int size;

    //Constructor function
    Stack(int size){
        this -> size = size;
        arr = new int[size];
        top = -1;
    }

    //behaviour 
    void push(int data){
        if(top < size -1){
            top++;
            arr[top] = data;
        }
        else{
            cout<<"Stack is OverFlow/Full"<<endl;
        }
    }
    

    void pop(){
        if(top>=0){
            top--;
        }
        else{
            cout<<"Stack is Underflow/Empty"<<endl;
        }
    }

    int peek(){
        if(top >= 0){
            return top;
        }
        else{
            cout<<"Stack is empty"<<endl;
            return -1;
        }
    }

    bool isEmpty(){
        if(top == -1){
            return true;
        }
        return false;
    }

    void print(){
        if(top == -1){
            cout<<"stack is empty"<<endl;
        }
        else{
            for(int i = top; i >=0 ;i --){
                cout<<"element is "<<arr[i]<<endl;
            }

        }
    }
};


int main(){

    //Creation of the Stack
    Stack s(10);

    //Print top of stack
    cout<<"The top of Stack is : "<<s.peek()<<endl;

    //Insertion of element that PUSH operation 
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    cout<<"After Insertion"<<endl;
    //Print top of stack
    cout<<"The top of Stack is : "<<s.peek()<<endl;

    //Print the Stack
    s.print();

    //Remove the elements from stack : pop
    s.pop();
    s.pop();
    s.pop();
    // s.pop();

    cout<<"After Deletion :"<<endl;
    //Check whether is Empty or not 
    if(s.isEmpty()){
        cout<<"Stack is Empty"<<endl;
    }
    else{
        cout<<"Stack is not Empty"<<endl;
    }

    //Print top of stack
    cout<<"The top of Stack is : "<<s.peek()<<endl;

    return 0;
}

//Creation of Stack using built in library class stack

/*
#include<iostream>
#include<stack>
using namespace std;

int main(){
    //Creation of the stack
    stack<int> s;
    
    //push operation in the stack - adding element at the top
    s.push(90);
    s.push(95);

    //pop operation in the stack - remove the element from the top
    s.pop();

    cout<<"Printing the Top Element : "<<s.top()<<endl;

    //Check whether the Stack is empty or not by using stack_variable.empty() function 
    if(s.empty()){
        cout<<"Stack is empty"<<endl;
    }
    else{
        cout<<"Stack is not empty"<<endl;
    }
    
    //size of the stack
    int size = s.size();
    cout<<"Stack size is: "<<size<<endl;
    
    return 0;
}
    */
