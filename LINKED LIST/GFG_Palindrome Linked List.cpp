/*
class Node {
  public:
    int data;
    Node *next;

    Node(int x) {
       data = x;
       next = NULL;
    }
};
*/

class Solution {
  public:
    bool isPalindrome(Node *head) {
        //  code here
        if(head == NULL){
            return true;
        }
        
        vector<int> arr;
        Node* temp = head;
        
        while(temp !=  NULL){
            arr.push_back(temp -> data);
            temp = temp -> next;
         }
         
         int start = 0;
         int end = arr.size() - 1;
         
         while(start <= end){
             if(arr[start] == arr[end]){
                 start++;
                 end--;
             }
             else
                 return false;
         }
         return true;
        }
};

//Approach 2 - using two pointers to find mid then compare half half list wihtout using array 

class Solution {
    private:
    //Function to get the middle of the linked list
    Node* getMiddle(Node* head){
        
        Node* slow = head;
        Node* fast = head -> next;
        while(fast != NULL && fast -> next != NULL){
            fast = fast -> next -> next;
            slow = slow -> next;
        }
        return slow;
    }
    //Function to reverse last half part of the linked list
    Node* reverse(Node* head){
        Node* curr = head;
        Node* prev = NULL;
        Node* next = NULL;
        while(curr != NULL){
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    
  public:
    bool isPalindrome(Node *head) {
        //return true if single node 
        if(head -> next == NULL){
            return true;
        }
        //get middle node of linked list
        Node* middle = getMiddle(head);
        
        //Reverse the Linked List
        Node* temp = middle -> next;
        middle -> next = reverse(temp);
        
        Node* head1 = head;
        Node* head2 = middle -> next;
        
        while( head2 != NULL ){
            if(head1 -> data != head2 -> data){
                return false;
            }
            head1 = head1 -> next;
            head2 = head2 -> next;
        }
         
        temp = middle -> next;
        middle -> next = reverse(temp);
        return true;
}
};