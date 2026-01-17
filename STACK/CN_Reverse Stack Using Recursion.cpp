void insertAtBottom(stack<int> &stack,int num){
    //Base case if stack empty then push the element that is default bottom now
    if(stack.empty()){
        stack.push(num);
        return;
    }
    //Otherwise store the top element and pop till the bottom reach
    int element = stack.top();
    stack.pop();

    //Recursively call to reach the bottom
    insertAtBottom(stack, num);
    //push the reomoved element again on top of it
    stack.push(element);
}

void reverseStack(stack<int> &stack){
    //base case stack is empty or not
    if(stack.empty()){
        return;
    }

    //store top element in num and pop
    int num = stack.top();
    stack.pop();

    //Recursively do this until the stack is empty
    reverseStack(stack);

    //insert the popped element at the bottom of the stack
    insertAtBottom(stack, num);
}