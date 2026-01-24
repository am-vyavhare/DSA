#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
bool solve(TreeNode<int>* root, int min, int max){
    //check whether the root is not empty
    if(root == NULL){
        return false;
    }

    //check whether the the given node is leaf node or not
    if(root -> left == NULL && root -> right == NULL){
        //check if there is any possible option to insert and if not return true that it has dead end
        if(min == max){
            return true;
        }
    }

    //recursively go in depth of the tree using DFS
    return solve(root->left, min, root -> data -1) || 
    solve( root-> right, root -> data +1, max);

}
bool isDeadEnd(TreeNode<int>* root){
    //Return true or false that is returned by the checking function
    return solve(root, 1, INT_MAX);
}