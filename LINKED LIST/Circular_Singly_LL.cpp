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
            next = NULL;
        }
        cout << "\nMemory is free for node with data " << value << endl;
    }
}; 

//Insert Operation Functions

void InsertNodeAfterElement(Node* &tail, int data, int element)
{
    //if empty list
    if(tail == NULL){
        Node* newNode = new Node(data);
        tail = newNode;
        newNode -> next = newNode;        
    }
    else{
        //Non empty list
        Node* current = tail;
        while(current -> data != element){
            current = current -> next;
        }
        Node* newNode = new Node(data);
        if(current == tail){
            tail = newNode;
        }
        newNode -> next = current -> next;
        current -> next = newNode;
    }
}

//Deletion of the Node
void DeleteNode(Node* &tail, int value){
    
    if(tail == NULL){
        cout<<"Linked List is Empty"<<endl;
        return;
    }
    else{
        //non empty list
        Node* previous = tail;
        Node* current = previous -> next;

        while(current -> data != value){
            previous = current;
            current = current -> next;
        }

        //1 node in the linked list 
        if( current == previous ){
            tail = NULL;
        }
        else if(tail == current){  //if deleting node is the tail node 
            tail = previous; 
        }
        previous -> next = current -> next;
        current -> next = NULL;
        delete current; 
    }
}


//Linked List Traversal
void print(Node* tail){
    //empty list
    if(tail == NULL){
        cout<<"Linked List is Empty"<<endl;
        return ;
    }
    Node* temp = tail;
    cout<<endl;
    do{
        cout<< temp -> data <<" - ";
        temp = temp -> next;
    }while (tail != temp);
}

int main(){

    Node* tail = NULL;
    
    cout<<"\nInsert 10";
    int element = 10;
    InsertNodeAfterElement(tail, 10 , element);
    print(tail);

    cout<<"\nInsert 20";
    InsertNodeAfterElement(tail, 20 , element);
    print(tail);

    cout<<"\nInsert 40";
    InsertNodeAfterElement(tail, 40 , 20);
    print(tail);
    
    cout<<"\nInsert 50";
    InsertNodeAfterElement(tail, 50 , 20);
    print(tail);
    
    cout<<"\nInsert 60";
    InsertNodeAfterElement(tail, 60 , 50);
    print(tail);

    int data = 300; 
    cout<<"\nInsertion after "<<element<<"  is Performed -->";
    InsertNodeAfterElement(tail, data , element);
    print(tail);
    

    int value = 10;
    cout<<"\n\nDeletion of "<<value<<" is Performed -->";
    DeleteNode(tail, value);
    print(tail);
    
    if (tail != NULL)
    cout << "\ntail " << tail -> data << endl;
    else
    cout << "\ntail is NULL" << endl;

    
    return 0;
}