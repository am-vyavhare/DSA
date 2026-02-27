/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head){
    //pointers to maintain the track of the current, previous, and next element
    ListNode* forward = NULL;   //initially null
    ListNode* previous = NULL;  //initially null 
    ListNode* current = head;   //start of current list
    //traverse the list until current element reach last node
    while(current != NULL){
        forward = current -> next;  //store the next pointer
        current -> next = previous; //assign previous node to current of next
        previous = current;     //move previous to current
        current = forward;      //move current forward
    }
    //now the new head of reversed linked list is previous so return it 
    return previous;
    }
};