#include<iostream>
using namespace std;

//Node Class defination -- 
class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }

    ~Node() {
    cout << " Memory is free for node with data " << data << endl;
    }

}; 

//Insert Operation Functions

void InsertAtTail(Node* &tail, int data){
    Node* newNode = new Node(data);
    tail -> next = newNode;
    tail = newNode;
}

//Linked List Traversal
void printLL(Node* &head){
    Node* temp=head;
    cout<<"\n Head ---> ";
    while(temp!=NULL){
        cout<<temp->data<<" -> ";
        temp = temp -> next; 
    }
    cout<<" <--- Tail\n";
}

//Remove Duplicates from Sorted Linked List
void Remove_Duplicates(Node* &head){
    if(head == NULL){
        return;
    }

    Node* curr = head;

    while(curr != NULL && curr->next != NULL){

        if(curr->data == curr->next->data){
            Node* NodeToDelete = curr->next;
            curr->next = curr->next->next;

            NodeToDelete->next = NULL;
            delete NodeToDelete;
        }
        else{
            curr = curr->next;
        }
    }
}

int main(){

    Node* FirstNode = new Node(100);
    cout<<"\nInitially Linked List is -->";
    printLL(FirstNode);    
    
    Node* head = FirstNode;
    Node* tail = FirstNode;
    
    cout<<"\nInsertion at Tail is Performed -->";
    InsertAtTail(tail, 200);
    printLL(head);
    
    InsertAtTail(tail, 200);
    printLL(head);

    InsertAtTail(tail, 200);
    printLL(head);

    InsertAtTail(tail, 300);
    printLL(head);
    
    Remove_Duplicates(head);
    cout<<"\nAfter Removing the Duplicate Elements from the list";
    printLL(head);
    
    return 0;
}