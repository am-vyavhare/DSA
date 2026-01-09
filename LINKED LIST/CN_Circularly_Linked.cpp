#include <bits/stdc++.h> 
/*************************************************
        Following is the structure of class Node:
     
        class Node{
        public:
            int data;
            Node* next;
            
            Node(int data){
                this->data = data;
                this->next = NULL;
            }
            
        }
**************************************************/


bool isCircular(Node* head) {

    // Empty list is circular
    if (head == NULL) {
        return true;
    }

    Node* slow = head;
    Node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        // If fast comes back to head ? circular
        if (fast == head || slow == head) {
            return true;
        }

        // Cycle detected but not involving head
        if (slow == fast) {
            return false;
        }
    }

    // If we hit NULL ? not circular
    return false;
}

