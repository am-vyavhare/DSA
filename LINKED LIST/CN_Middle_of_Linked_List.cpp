/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};
*/

Node *findMiddle(Node *head) {
    // Write your code here
    if(head == NULL){
        return NULL;
    }
    int count = 1;
    Node* temp = head;
    
    while(temp -> next != NULL){
        temp = temp -> next;
        count++;
    }
    
    temp = head;
    int middle = count/2 + 1;
    int i = 1;
    while(i < middle){
        temp = temp -> next;
        i++;
    }
    return temp;
}

