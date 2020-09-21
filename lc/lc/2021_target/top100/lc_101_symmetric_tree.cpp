/*
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
*/
#include "../header.hpp"

class Solution {
public:

    bool helper(TreeNode *l, TreeNode *r) {
        if ( !l && !r)
        return true;
        if ( !l || !r) return false;
        return ( l->val == r->val && helper(l->left, r->right) && helper(l->right, r->left));
    }

    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        return helper(root->left, root->right);

        
    }
};