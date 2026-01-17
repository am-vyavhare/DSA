#include <bits/stdc++.h>
void insertSorted(stack<int> &stack, int element){
	//Check whether the stack is empty if yes then push first element
	if(stack.empty()){
		stack.push(element);
		return;
	}
	//if the top is less than current element then insert the element since it is right position on current situation
	if(stack.top()<=element){
		stack.push(element);
		return;
	}
	//otherwise we need to find the correct position by calling the function recursively in depth
	else{
		int top = stack.top();
		stack.pop();
		//Recursive Call
		insertSorted(stack, element);
		//Again insert the popped elements
		stack.push(top);
	}
}
void sortStack(stack<int> &stack)
{	
	//Check whether the stack is empty or not if empty then return
	if(stack.empty()){
		return;
	}
	//Otherwise store the top element and pop and recursive call
	int num = stack.top();
	stack.pop();

	//Recursive call till the end of the stack
	sortStack(stack);

	//Insert the stored element in the sorted order
	insertSorted(stack, num);
}