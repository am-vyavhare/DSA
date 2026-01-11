#include <bits/stdc++.h>

/************************************************************

    Following is the linked list node structure.
    
    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

************************************************************/

Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    // Write your code here.
    //Return another list if one is null
    if(first == NULL){
        return second;
    }    
    if(second == NULL){
        return first;
    }

    //Create Node Pointer for the Result List with its Tail
    Node<int>* FinalNode = new Node<int>(-1);
    Node<int>* FinalTail = FinalNode;

    //Traverse and Link the Nodes in the Final list in sorted Order until one finishes
    while(first != NULL && second != NULL){
        if(first -> data <= second -> data){
            FinalTail -> next = first;
            first = first -> next;
        }
        else{
            FinalTail -> next = second;
            second = second -> next;
        }
        FinalTail = FinalTail -> next;
    }
    //Assign the Remaining list to the finalTail 
    FinalTail -> next = (first == NULL)? second : first;
    return FinalNode -> next;
}


/************************************************************/
//Approach Two - By adding the one list elements inside another list elements and returning the final list after merge 

#include <bits/stdc++.h>

Node<int>* solve(Node<int>* first, Node<int>* second){
    //if first list have only one node 
    if(first->next == NULL){
        first -> next = second;
        return first;
    }

    //Create pointers to maintain track of the both lists
    Node<int>* curr1 = first;
    Node<int>* next1 = first -> next;
    Node<int>* curr2 = second;
    Node<int>* next2 = second -> next;

    //traverse until the one of the list reach end
    while(next1 != NULL && curr2 != NULL){
        //Compare the second list data with the first list window 
        if((curr1-> data <= curr2 -> data) && (curr2 -> data < next1 -> data)){
           //add node in between of first list
            curr1 -> next = curr2;
            next2 = curr2 -> next;
            curr2 -> next = next1;
            
            //Update the pointers 
            curr1 = curr2;
            curr2 = next2;
        }   
        else{
            //Move first list window to further
            curr1 = next1;
            next1 = next1 -> next;
            //if first list reach end then append the second list and return 
            if(next1 == NULL){
                curr1 -> next = curr2;
                return first;
            }   
        }         
    }
    //Return Final Node
    return first;
}

Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    // Write your code here.
    //Return another list if one is null
    if(first == NULL){
        return second;
    }    
    if(second == NULL){
        return first;
    }

    //Consider the List as First which have first element smaller
    if(first -> data <= second -> data){
        solve(first , second);
    }
    else{
        solve(second, first);
    }
}
