/*
 * Given the root of a binary tree and an integer targetSum, return true if the tree has a root-to-leaf path such that adding up all the values along the path equals targetSum.

A leaf is a node with no children.
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
    bool res = false;
    bool hasPathSum(TreeNode* root, int sum) {
        return has(root, sum);
        //return res;
    }

    bool has(TreeNode* root, int sum) {
        if(root == NULL){
            return false;
        }
        else if(sum == root->val && root->left == NULL && root->right == NULL){
           return true;
        }
        return has(root->left, sum - root->val) ||
            has(root->right, sum - root->val);


    }
};
