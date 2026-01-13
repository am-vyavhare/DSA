/********************************************************************

    Following is the representation of the Singly Linked List Node:

    class node{
        public:
            int data;
            node * next;
            node(int data){
                this->data=data;
                this->next=NULL;
            }
    };
    
********************************************************************/
node* findmid(node* head){
    node* slow = head;
    node* fast = head -> next;
    //traverse the fast till null and slow with it 
    while(fast != NULL && fast -> next != NULL){
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    return slow;
}

node* merge(node* left,node* right){
    if(left == NULL){
        return right;
    }
    if(right == NULL){
        return left;
    }

    node* answer = new node(-1);
    node* temp = answer;

    while(left != NULL && right != NULL){
        if(left -> data <= right -> data){
            temp -> next = left;
            temp = left;
            left = left -> next;
        }
        else{
            temp -> next = right;
            temp = right;
            right = right -> next;
        }
    }

    while(left != NULL){
        temp -> next = left;
        temp = left;
        left = left -> next; 
    }

    while(right != NULL){
        temp -> next = right;
        temp = right;
        right = right -> next;
    }

    return answer -> next; 
}

node* mergeSort(node *head){
    //check if head is null or next is null them return head
    if(head == NULL || head -> next == NULL){
        return head;
    }

    //break the list in two half part and get the mid element node
    node* mid = findmid(head);

    //Assign start for first part as left and second part as right
    node* left = head;
    node* right = mid -> next;
    mid -> next = NULL;

    //Recursively sort the half parts 
    left = mergeSort(left);
    right = mergeSort(right);

    //merge the sorted parts 
    node* ans = merge(left, right);

    //Return answer node
    return ans;
}
