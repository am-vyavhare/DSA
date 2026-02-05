#include <bits/stdc++.h> 
/*Structure of the Node of the BST is as
struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val) 
    {
        data = val;
        left = right = NULL;
    }
};
*/
//Inorder Traversal Function
void inorder(Node* root, vector<int>& v){
    if(root == NULL){
        return;
    }
    inorder(root->left, v);
    v.push_back(root->data);
    inorder(root->right, v);
}

int countCouples(Node* root1, Node* root2 , int x)
{
    //create vector to store the inorder traversal of 
    //the both BST that will give us sorted array by their ID
    vector<int> men;
    vector<int> women;
    //collect sorted vector
    inorder(root1, men);
    inorder(root2, women);
    //initialize two pointer 1st-start from men array and 2nd-end from women
    int start_men = 0;
    int end_women = women.size()-1;
    int count = 0;     // to count pairs of couples
    //until they will not cross find pairs
    while(start_men < men.size() && end_women >= 0){
        //calculate id sum 
        int sum = men[start_men]+women[end_women];
        //if match increment count and move forward
        if(sum == x){
            count++;
            start_men++;
            end_women--;
        }
        else{
        //if sum is less move start else move end
        if(sum < x)
            start_men++;
        else
            end_women--;
        }
    }
    return count;
}