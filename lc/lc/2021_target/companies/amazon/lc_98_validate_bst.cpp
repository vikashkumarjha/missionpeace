/*
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.

*/


#include "header.hpp"

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
class Solution {
public:


    bool helper(TreeNode *root, TreeNode *minNode, TreeNode *maxNode) {
        if ( !root){
            return true;
        }

        if ( minNode && root->val <= minNode->val ) {
            return false;
        }

        if ( maxNode && root->val >= maxNode->val) {
            return false;
        }

        return helper(root->left, minNode, root) && helper(root->right, root, maxNode);

    }

    bool isValidBST(TreeNode* root) {
        if ( !root) return true;
        return helper(root, nullptr, nullptr);
        
    }
};



class Solution {
public:
    bool isValidBST(TreeNode* root) {
        long pre = INT_MIN;
        stack<TreeNode*> st;
        while (root || !st.empty()) {
            while (root) {
                st.push(root);
                root = root->left;
            }
            root = st.top();
            st.pop();
            if (root->val <= pre) {
                return false;
            }
            pre = root->val;
            root = root->right;
        }
        return true;
    }
};