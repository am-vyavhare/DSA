#include <bits/stdc++.h> 
void insertAtBottom(stack<int>& myStack, int data){
    //check whether the stack is empty or not if empty then insert the element at bottom and return
    if(myStack.empty()){
        myStack.push(data);
        return;
    }
    //if not empty then store the top element for insertion when return
    int element = myStack.top();
    //pop the top element
    myStack.pop();

    //Recursive call
    insertAtBottom(myStack, data);

    //Adding element when returning
    myStack.push(element);
}
stack<int> pushAtBottom(stack<int>& myStack, int x) 
{
    //Function to insert element at bottom
    insertAtBottom(myStack, x);
    return myStack;
}
