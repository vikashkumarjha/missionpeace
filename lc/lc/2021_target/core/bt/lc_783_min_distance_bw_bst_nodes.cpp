/*
 * Given the root of a Binary Search Tree (BST), return the minimum difference between the values of any two different nodes in the tree.


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
public:
    TreeNode *prev = nullptr;

    void helper(TreeNode *root, int &minVal) {
        if (!root) return;
        helper(root->left,  minVal);

        if (prev) {
            minVal = min(minVal, abs(prev->val - root->val) );
        }
        prev = root;

        helper(root->right, minVal);

    }

    int minDiffInBST(TreeNode* root) {
            int res = INT_MAX;
            TreeNode *last = nullptr;
            helper(root, res);
            return res;

    }
};


