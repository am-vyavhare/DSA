/**
 * Definition of doubly linked list:
 * class Node {
 * public:
 *      int data;
 *      Node *prev;
 *      Node *next;
 *      Node() {
 *          this->data = 0;
 *          this->prev = NULL;
 *          this->next = NULL;
 *      }
 *      Node(int data) {
 *          this->data = data;
 *          this->prev = NULL;
 *          this->next = NULL;
 *      }
 *      Node (int data, Node *next, Node *prev) {
 *          this->data = data;
 *          this->prev = prev;
 *          this->next = next;
 *      }
 * };
 *
 *************************************************************************/

Node * removeDuplicates(Node *head)
{
    // Write your code here
    if(head == NULL){
        return head;
    }
    //Node to point the 2nd node
    Node* curr = head -> next;
    //traverse till the current node is not null
    while(curr != NULL){
        //check whether the current and previous node have same data
        if(curr -> prev -> data == curr -> data){
            Node* NodeToDelete = curr;
            curr -> prev -> next = curr -> next;
        //if the current node is not last then update previous pointer
            if(curr -> next != NULL){
            curr -> next -> prev = curr -> prev;
            }      
            //move next and delete
            curr = curr -> next;
            NodeToDelete -> next = NodeToDelete -> prev = NULL;
            delete NodeToDelete;
        }
        else{
            curr = curr -> next;
        }
    }
    return head;
}
