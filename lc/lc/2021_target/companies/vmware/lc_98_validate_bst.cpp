/*
Given the root of a binary tree, determine if it is a valid binary search tree (BST).

A valid BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
*/



class Solution {
public:
    bool helper(TreeNode *root, TreeNode *min, TreeNode *max) {
        if (!root) return true;
        if ( min && root->val <= min->val) return false;
        if ( max && root->val >= max->val) return false;


        return helper(root->left, min, root) && helper(root->right, root, max);


    }

    bool isValidBST(TreeNode* root) {
        if (!root) return true;

        return helper(root, nullptr, nullptr);
        
    }
};