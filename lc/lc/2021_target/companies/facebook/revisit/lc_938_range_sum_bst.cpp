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
    
    void helper(TreeNode *root, int L, int R, int &res) {
        if ( !root) {
            return;
        }
        if ( root->val >= L and root->val <= R) {
            res += root->val;
        }
        
        if ( root->val > L) {
            helper(root->left, L, R, res);
        }
        
        if ( root->val < R) {
            helper(root->right, L, R, res);
        }
        
        
    }
    
    int rangeSumBST(TreeNode* root, int low, int high) {
        int res = 0;
        helper(root, low, high, res);
        return res;
        
    }
};