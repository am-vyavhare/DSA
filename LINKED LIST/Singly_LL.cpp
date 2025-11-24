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
        int value = this -> data;
        //memory free
        if(this->next != NULL) {
            delete next;
            this->next = NULL;
        }
        cout << " memory is free for node with data " << value << endl;
    }
}; 

//Insert Operation Functions

void InsertAtHead(Node* &head, int data){
    Node* newNode = new Node(data);
    newNode -> next = head;
    head = newNode;
} 

void InsertAtTail(Node* &tail, int data){
    Node* newNode = new Node(data);
    tail -> next = newNode;
    tail = newNode;
}

void InsertAtPosition(Node* &head,Node* &tail,  int position, int data){
    
    if(position == 1){
        InsertAtHead(head, data);  
        return;
    }

    Node* temp = head;
    int count = 1;
    while(count < position-1){
        temp = temp -> next;
        count++;
    }
    
    if(temp -> next == NULL){
        InsertAtTail(tail, data);
        return;
    }

    Node* newNode = new Node(data);
    newNode -> next = temp -> next;
    temp -> next = newNode;
}

//Delete Operation in the Linked List  

void DeleteNode(Node* &head, Node* &tail, int position){
    //Deletion handle for the first node
    if(position == 1){
        Node* temp = head;
        head = head -> next;
        temp -> next = NULL;
        delete temp;
    }
    //Handling the last node and the in between node 
    else{
        
        Node* current = head;
        Node* previous = NULL;
        int count = 1;
        
        while(count < position) {
            previous = current;
            current = current -> next;
            count++;
        }

        if(current -> next == NULL){
            tail  = previous;
        }
        previous -> next = current -> next;
        current -> next = NULL;
        delete current;
    }

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

int main(){

    Node* FirstNode = new Node(100);
    cout<<"\nInitially Linked List is -->";
    printLL(FirstNode);    
    
    Node* head = FirstNode;
    Node* tail = FirstNode;
    
    cout<<"\nInsertion at Head is Performed -->";
    InsertAtHead(head, 200);
    printLL(head);
    
    cout<<"\nInsertion at Tail is Performed -->";
    InsertAtTail(tail, 300);
    printLL(head);
    
    int position = 4;
    cout<<"\nInsertion at "<<position<<" position is Performed -->";
    InsertAtPosition(head, tail, position, 500);
    printLL(head);
    

    cout<<"\nDeletion at "<<position<<" position is Performed -->";
    DeleteNode(head, tail, position);
    printLL(head);
    
    cout << "head " << head -> data << endl;
    cout << "tail " << tail -> data << endl;
    
    return 0;
}