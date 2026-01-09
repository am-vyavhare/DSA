/*************************************************
    
    class Node {
        public :

        int data;
        Node *next;

        Node(int data) {
            this -> data = data;
            this -> next = NULL;
        }
    };

*************************************************/
Node* floydDetectLoop(Node* head){
    //Create two pointers fast and slow to traverse Linked List
    Node* fast = head;
    Node* slow = head;
    
    //Traverse the List still we get the meeting point of slow and fast pointer
    while(fast != NULL && fast->next != NULL){
        slow = slow -> next;
        fast = fast -> next -> next;

        //Return the meeting point
        if(slow == fast){
            return slow;
        }
    }
    //Return NULL if there is no meeting point means no cycle present in the List
    return NULL;
}

Node* getStartOfLoop(Node* head){
    //Collect the intersection point of slow and fast in the cycle
    Node* intersection = floydDetectLoop(head);
    if(intersection == NULL){
        return NULL;
    }
    //initialize the start of slow at head of list
    Node* slow = head;

    //Traverse till slow and intersection meet and this point is start of Loop cycle 
    while(slow != intersection){
        slow = slow -> next;
        intersection = intersection -> next;
    }
    //Return the Loop Start
    return slow;
}

Node *removeLoop(Node *head)
{
    // Write your code here.
    //Return NULL if List is NULL
    if(head == NULL){
        return NULL;
    }

    //Start of Loop is NULL then return head
    Node* startofLoop = getStartOfLoop(head);
    if(startofLoop == NULL){
        return head;
    }
    
    Node* temp = startofLoop;

    //traverse till the previous node of start so that we will break the link by setting the next as NULL 
    while(temp -> next != startofLoop){
        temp = temp -> next;
    }
    //break the Link 
    temp -> next = NULL;
    return head;
}