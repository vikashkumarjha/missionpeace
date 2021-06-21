/*
Given the root of a binary search tree and the lowest and highest boundaries as low and high, trim the tree so that all its elements lies in [low, high]. Trimming the tree should not change the relative structure of the elements that will remain in the tree (i.e., any node's descendant should remain a descendant). It can be proven that there is a unique answer.

Return the root of the trimmed binary search tree. Note that the root may change depending on the given bounds.
*/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
   TreeNode* trimBST(TreeNode* root, int L, int R) {
        
    if ( root == nullptr)
        return root;

    if ( root->val >= L && root->val <=  R){
        root->left = trimBST(root->left,L,R);
        root->right = trimBST(root->right,L,R);
       // return root;
    }
    else if ( root->val < L ){
        root = trimBST(root->right,L,R);
    }
    else if ( root->val > R) {
        root = trimBST(root->left,L,R);
    }
    return root;
    }
};