#include <bits/stdc++.h> 
void solve(stack<int>&inputStack,int count, int size){
   //if middle element then pop and return
   //base case 
   if(count == size/2){
      inputStack.pop();
      return;
   }
   //if not middle element then store the top element for further insertion
   int num = inputStack.top();
   inputStack.pop();

   //Recursive call
   solve(inputStack, count+1, size);

   //Add the popped elements again after deleting the middle element
   inputStack.push(num);
}

void deleteMiddle(stack<int>&inputStack, int N){
   //start with the 0 index until the middle got for the pop or delete
	int count = 0;
   solve(inputStack, count, N); 
}