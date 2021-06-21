/*
Given the root of a binary tree, return the number of uni-value subtrees.

A uni-value subtree means all nodes of the subtree have the same value.


*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
   
    bool helper(TreeNode * root, int & count){
        if (!root) return true;
       
        bool x = helper(root->left,  count);
        bool y = helper(root->right, count);
       
        if ((x && y) &&
            ((root->left == nullptr) || (root->left->val == root->val)) &&
            ((root->right == nullptr) || (root->right->val == root->val))){
           
            count++;
            return true;
        }        
       
        return false;
    }
   
public:
    int countUnivalSubtrees(TreeNode* root) {
        if (!root) return 0;
       
        int count = 0;
        helper(root, count);
       
        return count;
       
    }
};
