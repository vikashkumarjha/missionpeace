/*
Given the root of a binary tree, 
return the length of the diameter of the tree.

The diameter of a binary tree is the length of the longest path 
between any two nodes in a tree. This path may or may not pass 
through the root.

The length of a path between two nodes is represented by the number of 
edges between them.

*/




class Solution {
public:
    
    int helper(TreeNode *root, int &res) {
        if ( !root) {
            return 0;
        }
        int ld = helper(root->left,res);
        int rd = helper(root->right, res);
        res = max(res, ld+rd);
        return max(ld,rd) + 1;
        
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        int res = 0;
        helper(root, res);
        return res;
        
    }
};