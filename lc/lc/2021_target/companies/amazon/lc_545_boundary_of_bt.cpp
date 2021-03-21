/*
A binary tree boundary is the set of nodes (no duplicates) denoting the union of the left boundary, leaves, and right boundary.

The left boundary is the set of nodes on the path from the root to the left-most node. The right boundary is the set of nodes on the path from the root to the right-most node.

The left-most node is the leaf node you reach when you always travel to the left subtree if it exists and the right subtree if it doesn't. The right-most node is defined in the same way except with left and right exchanged. Note that the root may be the left-most and/or right-most node.

Given the root of a binary tree, return the values of its boundary in a counter-clockwise direction starting from the root.


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

    void getLeftBoundary(TreeNode *root, vector<int> &res) {
        if (root) {
            if (root->left) {
                res.push_back(root->val);
                getLeftBoundary(root->left, res);
            }
            else if (root->right) {
                res.push_back(root->val);
                getLeftBoundary(root->right, res);

            }
        }
    }
    void getRightBoundary(TreeNode *root, vector<int> &res) {
        if (root) {
            if (root->right) {
                res.push_back(root->val);
                getRightBoundary(root->right, res);
            }
            else if (root->left) {
                res.push_back(root->val);
                getRightBoundary(root->left, res);
            }
        }
    }

    void getLeaves(TreeNode *root, vector<int> &res) {
        if (root) {

            getLeaves(root->left, res);
            if ( !root->left && !root->right) {
                res.push_back(root->val);
            }
            getLeaves(root->right,res);
        }
    }



    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        if ( !root) return {};
        vector<int> res;
        res.push_back(root->val);

        getLeftBoundary(root->left, res);

        getLeaves(root->left, res);
        getLeaves(root->right, res);
        getRightBoundary(root->right, res);

        return res;

        
    }
};


