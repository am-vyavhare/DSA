/*
 * Definition for linked list.
 * class Node {
 *  public:
 *		int data;
 *		Node *next;
 * 		Node *child;
 *		Node() : data(0), next(nullptr), child(nullptr){};
 *		Node(int x) : data(x), next(nullptr), child(nullptr) {}
 *		Node(int x, Node *next, Node *child) : data(x), next(next), child(child) {}
 * };
 */

Node* merge(Node* a, Node* b) {
        if (a == NULL) return b;
        if (b == NULL) return a;

        Node* result;

        if (a->data <= b->data) {
            result = a;
            result->child = merge(a->child, b);
        } else {
            result = b;
            result->child = merge(a, b->child);
        }

        result->next = NULL;  // important: remove next pointer
        return result;
    }

Node* flattenLinkedList(Node* head) 
{
	// Base case
        if (head == NULL || head->next == NULL) {
            return head;
        }

        // Step 1: Flatten the list on the right
        head->next = flattenLinkedList(head->next);

        // Step 2: Merge current list with flattened right list
        head = merge(head, head->next);

        return head;
}
