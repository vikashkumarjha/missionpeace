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

Given the root of a binary tree, return the same tree where every subtree (of the given tree) not containing a 1 has been removed.

A subtree of a node node is node plus every node that is a descendant of node.


class Solution {
public:

    bool containsOne(TreeNode *root) {
        if (!root) return false;
        bool inLeftTree = containsOne(root->left);
        bool inRightTree = containsOne(root->right);
        if ( !inLeftTree) {
            root->left = nullptr;

        }
        if ( !inRightTree) {
            root->right = nullptr;

        }

        return root->val == 1 || inLeftTree || inRightTree;


    }


    TreeNode* pruneTree(TreeNode* root) {
        return containsOne(root) ? root : nullptr;



    }
};
