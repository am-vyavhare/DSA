/**
 * Definition for singly-linked list.
 * class Node {
 * public:
 *     int data;
 *     Node *next;
 *     Node() : data(0), next(nullptr) {}
 *     Node(int x) : data(x), next(nullptr) {}
 *     Node(int x, Node *next) : data(x), next(next) {}
 * };
 */

Node* kReverse(Node* head, int k) {
    // Base case
    if (head == NULL) {
        return NULL;
    }

    // Step 1: Check if there are at least k nodes
    Node* temp = head;
    int count = 0;
    while (temp != NULL && count < k) {
        temp = temp->next;
        count++;
    }

    // If nodes less than k, do NOT reverse
    if (count < k) {
        return head;
    }

    // Step 2: Reverse first k nodes
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;
    count = 0;

    while (curr != NULL && count < k) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    // Step 3: Recursively process remaining list
    head->next = kReverse(curr, k);

    // prev is new head after reversing k nodes
    return prev;
}
