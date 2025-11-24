#include<iostream>
using namespace std;

// Node Class
class Node{
    public:
    int data;
    Node* next;
    Node* previous;

    Node(int data){
        this -> data = data;
        previous = NULL;
        next = NULL;
    }

    ~Node() {
        int value = this -> data;
        //memory free
        if(this->next != NULL) {
            delete next;
            next = NULL;
        }
        cout << " memory is free for node with data " << value << endl;
    }
};

// Linked List Traversal
void print(Node* &head){
    //If Linked List is Empty
    if(head == NULL){
        cout<<"\nLinked List is Empty"<<endl;
    }
    else{
    Node* temp = head;
    
    while(temp != NULL){
        cout<<temp->data<<" - ";
        temp = temp -> next;
    }    
    }
}

// Linked List Length Returning Function
int getLength(Node* &head){
    //If Linked List is Empty
    if(head == NULL){
        cout<<"\nLinked List is Empty"<<endl;
    }
    Node* temp = head;
    int count = 0;
    while(temp != NULL){
        temp = temp -> next;
        count++;
    }    
    return count;
}

//Insertion of the Node at the Begining 
void InsertAtHead(Node* &head, Node* &tail, int data){
    //If Linked List is Empty
    if(head == NULL){
        Node* temp = new Node(data);
        head = temp;
        tail = temp;
    }
    else{
    Node* temp = head;

    Node* newNode = new Node(data);
    newNode -> previous = NULL;
    newNode -> next = temp;
    temp -> previous = newNode;
    head = newNode;
    }
}

//Insertion of Node at the End of the Linked List
void InsertAtTail(Node* &head, Node* &tail, int data){
    //If Linked List is Empty
    if(head == NULL){
        Node* temp = new Node(data);
        head = temp;
        tail = temp;
    }
    else{
    Node* temp = tail;

    Node* newNode = new Node(data);
    tail -> next = newNode;
    newNode -> previous = tail;
    newNode -> next = NULL;
    tail = newNode;
    }
}


//Insertion of the Node in between of the Linked List
void InsertAtPosition(Node* &head,Node* &tail,  int position, int data){
    
    if(position == 1){
        InsertAtHead(head, tail, data);  
        return;
    }

    Node* temp = head;
    
    int count = 1;
    while(count < position-1){
        temp = temp -> next;
        count++;
    }
    
    if(temp -> next == NULL){
        InsertAtTail(head, tail, data);
        return;
    }

    Node* newNode = new Node(data);
    newNode -> next = temp -> next;
    temp -> next -> previous = newNode;
    newNode -> previous = temp;
    temp -> next = newNode;
}

//Delete Operation in the Linked List  

void DeleteNode(Node* &head, Node* &tail, int position){
    //If Linked List is Empty
    if(head == NULL){
        cout<<"\nLinked List is Empty"<<endl;
    }
    else{
    
    //Deletion handle for the first node
    if(position == 1){
        Node* temp = head;
        head = head -> next;
        temp -> next -> previous = NULL;
        temp -> previous = NULL;
        temp -> next = NULL;
        delete temp;
    }
    
    //Handling the last node and the in between node 
    else{
        
        Node* current = head;
        int count = 1;
        
        while(count < position) {
            current = current -> next;
            count++;
        }

        //handling the deleting of the last element 
        if(current -> next == NULL){
            current -> previous -> next = current -> next;
            tail  = current -> previous;
            current -> previous = NULL;
            delete current;
        }
        else{
        current -> previous -> next = current -> next;
        current -> next -> previous = current -> previous;
        current -> previous = NULL; 
        current -> next = NULL;
        delete current;
    }

    }
}
}


int main(){
    Node* FirstNode = new Node(11);

    Node* head = FirstNode;
    Node* tail = FirstNode;

    // Node* head = NULL;
    // Node* tail = NULL;

    cout<<"\nInitially the Doubly Linked List is -->"<<endl;
    print(head);
    
    cout<<"\nLength of the Linked List is -> "<<getLength(head);
    
    int data = 12;
    cout<<"\nAfter Insertion of -> "<<data<<" at the Head Position ->"<<endl;
    InsertAtHead(head, tail, data);
    print(head);
    
    data = 13;
    cout<<"\nAfter Insertion of -> "<<data<<" at the tail Position ->"<<endl;
    InsertAtTail(head, tail, data);
    print(head);
    
    data = 14;
    int position = 3;
    cout<<"\nAfter Insertion of -> "<<data<<" at the specific Position ->"<<position<<endl;
    InsertAtPosition(head, tail, position, data);
    print(head);
    
    position = 4;
    cout<<"\nDeletion at "<<position<<" position is Performed -->";
    DeleteNode(head, tail, position);
    print(head);

    cout << "\nhead -> " << head -> data << endl;
    cout << "tail -> " << tail -> data << endl;
    return 0;
}