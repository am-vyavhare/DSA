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

Node* sortList(Node *head){
    // Write your code here.
    int count0 = 0;
    int count1 = 0;
    int count2 = 0;

    Node* temp = head;
    while(temp != NULL){
        if(temp -> data == 0){
            count0++;
        }
        else{
            if(temp ->data == 1){
                count1++;
            }
            else{
                count2++;
            }
        }
        temp = temp -> next;
    }

    temp = head;
    while(temp != NULL){
        if(count0 >= 1){
            temp -> data = 0;
            count0--;
        }
        else{
            if(count1 >= 1){
                temp -> data = 1;
                count1--;
            }
            else{
                temp -> data = 2;
                count2--;
            }
        }
        temp = temp -> next;

    }
    return head;
}

/****************************/

//Approach 2 - without changing the data - that is you need to solve by manipulating links

void insertAtTail(Node* &tail, Node* &curr){
    tail -> next = curr;
    tail = curr;
}

Node* sortList(Node *head){
    // Write your code here.
    //Create nodes for the 3 seprate lists
    Node* zerohead = new Node(-1);
    Node* zerotail = zerohead;
    Node* onehead = new Node(-1);
    Node* onetail = onehead;
    Node* twohead = new Node(-1);
    Node* twotail = twohead;

    Node* curr = head;
    //traverse to add the nodes in the respective list
    while( curr != NULL){
        int data = curr -> data;

        if(data == 0){
            insertAtTail(zerotail, curr);
        }
        else if(data == 1){
            insertAtTail(onetail, curr);
        }
        else{
            insertAtTail(twotail, curr);
        }
        curr = curr -> next;
    }

    //Merge the List
    head = zerohead -> next;

    if( onehead -> next != NULL){
        zerotail -> next = onehead -> next;
    }
    else{
        zerotail -> next = twohead -> next;
    }
    onetail -> next = twohead -> next;
    twotail -> next = NULL;

    //Free the Memory
    delete onehead;
    delete twohead;
    delete zerohead; 
    
    return head;
}