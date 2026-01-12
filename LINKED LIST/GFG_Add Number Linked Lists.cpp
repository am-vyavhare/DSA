/*
class Node {
  public:
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  private:
    Node* reverse(Node* head){
        Node* curr = head;
        Node* prev = NULL;
        Node* next = NULL;
        
        while(curr != NULL){
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    
    void insertAtTail(Node* &anshead,Node* &anstail, int digit){
        Node* newnode = new Node(digit);
        newnode -> next = NULL;
        if(anshead == NULL){
            anshead = newnode;
            anstail = newnode;
        }
        else{
            anstail -> next = newnode;
            anstail = newnode;
        }
    }
    
    Node* add(Node* first, Node* second) {

    int carry = 0;
    Node* ansHead = NULL;
    Node* ansTail = NULL;

    while(first != NULL || second != NULL || carry != 0){

        int value1 = 0;
        if(first != NULL){
            value1 = first->data;
        }

        int value2 = 0;
        if(second != NULL){
            value2 = second->data;
        }

        int sum = value1 + value2 + carry;
        int digit = sum % 10;
        carry = sum / 10;

        insertAtTail(ansHead, ansTail, digit);

        if(first != NULL) first = first->next;
        if(second != NULL) second = second->next;
    }
    return ansHead;
}

  public:
    Node* addTwoLists(Node* first, Node* second) {
        // code here
        //reverse the given linked list
        first = reverse(first);  
        second = reverse(second);
        
        //Add both Linked List and return result list
        Node* ans = add(first , second);
        
        //Reverse the answer list to get original answer
        ans = reverse(ans);
        
        //Remove the Leading zero
        while(ans != NULL && ans->data == 0 && ans->next != NULL){
            ans = ans->next;
        }

        //Return answer list 
        return ans;
    }
};