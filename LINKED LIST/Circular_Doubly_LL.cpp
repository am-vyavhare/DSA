#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* previous;

    Node(int data){
        this -> data = data;
        this -> next = NULL;
        this -> previous = NULL;
    }

    ~Node(){
        int value = this -> data;
        cout<<"\n The data - "<<value<<" is deleted from the Linked List and the Memory is Free of it";
    }
};

void InsertNodeAt(Node* &head, int data, int element){
    //Empty Linked List
    if(head == NULL){
        Node* newNode = new Node(data);
        newNode -> next = newNode;
        newNode -> previous = newNode;
        head = newNode;
    }
    //Linked List with 1 or more Node
    else{
        Node* temp = head;
        while(temp -> data != element){
            temp = temp -> next;
            if(temp == head){
                cout<<"\nThe given element - "<<element<<" is not present in the Linked List";
                break;
            }
        }

        Node* newNode = new Node(data);
        newNode -> next = temp -> next;
        newNode -> previous = temp;
        temp -> next -> previous = newNode; 
        temp -> next = newNode;

    }
}

//Deleting of the Node
void DeleteNodeByValue(Node* &head, int value){
    if(head == NULL){
        cout<<"\n The Linked List is Empty Nothing to Delete";
        return;
    }
    else{
        Node* current = head;
        while(current -> data != value){
            current = current -> next;
            if(current == head){
                cout<<"\nThe given value - "<<value<<" is not present in the Linked List";
                return;
            }
        }
        
        //if single node 
        if(current == head && head == current -> next){
            current -> next = NULL;
            current -> previous = NULL;
            delete current;
            head = NULL;
            return;
        }
        else{
        if(current == head){
        head = current -> next; 
        }
        current -> previous -> next = current -> next;
        current -> next -> previous = current -> previous;
        current -> next = NULL;
        current -> previous = NULL;
        delete current;
        }
    }
}

//Printing of the Linked List 
void print(Node* head){
    if(head == NULL){
        cout<<"\n The Linked List is Empty Nothing to Print";
        return;
    }
    cout<<endl;
    Node* temp = head;
    do{
        cout<< temp -> data <<" - ";
        temp = temp -> next;
    }while(temp != head);
}

//Printing the Linked List in the Reverse Order
void printReverse(Node* head){
    if(head == NULL){
        cout<<"\n The Linked List is Empty Nothing to Print";
        return;
    }
    cout<<endl;
    Node* temp = head;
    do{
        cout<< temp -> data <<" - ";
        temp = temp -> previous;
    }while(temp != head);
}

int main(){
    Node* head = NULL;

    int data = 1;
    int element = 2;
    cout<<"\nThe data - "<<data<<" is inserted after the element - "<<element<<endl;
    InsertNodeAt(head, data, element);
    print(head);

    data = 2;
    element = 1;
    cout<<"\nThe data - "<<data<<" is inserted after the element - "<<element<<endl;
    InsertNodeAt(head, data, element);
    print(head);
    
    data = 3;
    element = 2;
    cout<<"\nThe data - "<<data<<" is inserted after the element - "<<element<<endl;
    InsertNodeAt(head, data, element);
    print(head);

    data = 4;
    element = 3;
    cout<<"\nThe data - "<<data<<" is inserted after the element - "<<element<<endl;
    InsertNodeAt(head, data, element);
    print(head);
    
    data = 5;
    element = 4;
    cout<<"\nThe data - "<<data<<" is inserted after the element - "<<element<<endl;
    InsertNodeAt(head, data, element);
    print(head);

    int value = 1;
    cout<<"\nThe value - "<<value<<" is deleted from the Linked List"<<endl;
    DeleteNodeByValue(head, value);
    print(head);

    value = 10;
    cout<<"\nThe value - "<<value<<" is deleted from the Linked List"<<endl;
    DeleteNodeByValue(head, value);
    print(head);

    cout<<"\n\nPrinting the Linked List in the Reverse Order"<<endl;
    printReverse(head);
    
    return 0;
}