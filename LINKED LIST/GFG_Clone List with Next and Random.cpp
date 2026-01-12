/*
class Node {
  public:
    int data;
    Node* next;
    Node* random;

    Node(int x) {
        data = x;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
    private:
    void insertAtTail(Node* &head, Node* &tail, int d){
        Node* newNode = new Node(d);
        if(head == NULL){
            head = newNode;
            tail = newNode;
            return;
        }
        else{
            tail -> next = newNode;
            tail = newNode;
        }
        
    }
  public:
    Node* cloneLinkedList(Node* head) {
        // code here
        //step 1 : create a clone list
        Node* cloneHead = NULL ;
        Node* cloneTail = NULL;
        
        Node* temp = head;
        
        while(temp!=NULL){
            insertAtTail(cloneHead, cloneTail, temp -> data);
            temp = temp -> next;
        }
        
        //Step - 2 Create a map
        unordered_map<Node*, Node*> oldToNewNode;
        
        Node* originalNode = head; 
        Node* cloneNode = cloneHead;
        while( originalNode != NULL && cloneNode != NULL){
            oldToNewNode[originalNode] = cloneNode;
            originalNode = originalNode -> next;
            cloneNode = cloneNode -> next;
        }
    
        originalNode = head;
        cloneNode = cloneHead;
        
        while(originalNode != NULL){
            cloneNode -> random = oldToNewNode[originalNode -> random];
            originalNode = originalNode -> next;
            cloneNode = cloneNode -> next;
        }
        
        return cloneHead;
        
    }
};

//Approach 2 - Using the Links change instead of unordered map 

class Solution {
    private:
    void insertAtTail(Node* &head, Node* &tail, int d)
    {
        Node* newnode = new Node(d);
        if(head == NULL){
            head = newnode;
            tail = newnode;
        }
        else{
            tail -> next = newnode;
            tail = newnode;
        }
    }
    
  public:
    Node* cloneLinkedList(Node* head) {
        // code here
        //step 1 - create a clone list
        
        Node* cloneHead = NULL;
        Node* cloneTail = NULL;
        
        Node* temp = head;
        while(temp!=NULL){
            insertAtTail(cloneHead, cloneTail, temp -> data);
            temp = temp -> next;
        }
        
        //step 2 - cloneNodes add in between original list
        
        Node* originalNode = head;
        Node* cloneNode = cloneHead;
        
        while(originalNode != NULL && cloneNode != NULL){
            Node* next = originalNode -> next;
            originalNode -> next = cloneNode;
            originalNode = next;
            
            next = cloneNode -> next;
            cloneNode -> next = originalNode;
            cloneNode = next;
        }
        
        //step 3 - random pointer copy 
        temp = head;
        
        while( temp != NULL){
            if(temp -> next != NULL){
                temp -> next -> random = temp -> random ? temp -> random -> next : temp -> random;
            }
            temp = temp -> next -> next;
        }
        
        //step 4 - revert changes done in step 2
        originalNode = head;
        cloneNode = cloneHead;
        
        while(originalNode != NULL && cloneNode != NULL){
            originalNode -> next = cloneNode -> next;
            originalNode = originalNode -> next;
            
            if(originalNode != NULL){
            cloneNode -> next = originalNode -> next;
            }
            cloneNode = cloneNode -> next;
        }
        
        //step 5 - return ans;
        return cloneHead;
    }
};