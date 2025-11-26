#include <bits/stdc++.h>

/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/

LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
    // Write your code here
    if(head == NULL || head->next == NULL){
        return head;
    }
    else{
    LinkedListNode<int>* forward = NULL; 
    LinkedListNode<int>* previous = NULL; 
    LinkedListNode<int>* current = head; 
    
    while(current != NULL){
        forward = current -> next;
        current -> next = previous;
        previous = current;
        current = forward;
    }   
    return previous;
}
}