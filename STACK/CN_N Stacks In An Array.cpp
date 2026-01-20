#include <bits/stdc++.h> 
class NStack
{
    int* arr; // array to store the elements and to make multiple stack
    int* top; // array to store the top element of the particular stack
    int* next; //When index is free ? next[i] points to next free index
    //When index is occupied ? next[i] links stack nodes (like a linked list)

    int n,s; // N is number of stack to implement 
    //and S is size of the array to be used for the storing of the element

    //location to store the index of free position where the next element to be stored 
    int freespot;
public:
    // Initialize your data structure.
    NStack(int N, int S)
    {
        n = N; //Number of stack
        s = S; //Size of array
        arr = new int[s]; //array that store the stacks
        top = new int[n]; //top array that stores the top element of every stack
        next = new int[s]; //array that stores the next location of top 
        //if element present otherwise next free space is pointed by it

        //initialize the top initially all at -1
        for(int i = 0; i < n; i++){
            top[i] = -1;
        }  

        //initialize next for each index i next free index is i+1
        for(int i = 0; i < s - 1; i++){
            next[i] = i+1;
        }

        //update last index value to -1 since it point no where 
        next[s-1] = -1;

        //initialise freespot to 0 to add first element at location 0
        freespot = 0;
    }

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m)
    {
        //check for overflow and if no space to add return false
        if(freespot == -1){
            return false;
        }

        //find index where the element to be pushed
        int index = freespot;

        //update freespot to point at the next free index location present at the current next[iindex]
        freespot = next[index];

        //insert element at the freespot index
        arr[index] = x;

        //update next since the element is added in the stack then next[index] will point to the top it
        next[index] = top[m-1];

        //update top to index to denote new top and m-1 is used since first array 1 is at 0 so (-1) used
        top[m-1] = index;

        //successful push return true
        return true;
    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m)
    {
        //check underflow condition and if no element return -1
        if(top[m-1] == -1){
            return -1;
        }

        //get the index of the top element of stack at m index
        int index = top[m-1];

        //update the top of stack to the next element that is denoted by the next[index]
        top[m-1] = next[index]; 
        
        //update the index position of the array as a freespot now for use
        next[index] = freespot;

        //update the freespot to use that index 
        freespot = index;

        //return the element that we are popping
        return arr[index];
    }
};