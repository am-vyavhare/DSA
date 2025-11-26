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

void reverse(LinkedListNode<int>* &head, LinkedListNode<int> * current, LinkedListNode<int> * previous){
    if(current == NULL){
        head = previous;
        return;
    }

    LinkedListNode<int>* forward = current -> next;
    reverse(head, forward, current);
    current -> next = previous;
}

LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
    // Write your code here
    LinkedListNode<int>* current = head;
    LinkedListNode<int>* previous = NULL;
    reverse(head, current, previous);
    return head;
}


// APPROACH 2 

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

LinkedListNode<int>* reverse(LinkedListNode<int>* &head){
    if(head == NULL || head -> next == NULL){
        return head;
    }
    
    LinkedListNode<int>* new_head = reverse(head -> next);
    head -> next -> next = head;
    head -> next = NULL;
    return new_head;
}

LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
    // Write your code here
    return reverse(head);
}

