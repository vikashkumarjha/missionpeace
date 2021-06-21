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
    int getHeight(TreeNode *root) {
        if (!root) return 0;
        int l = getHeight(root->left);
        int r = getHeight(root->right);
        return max(l,r) + 1;
        
    }
    
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
       if (!root) return nullptr;
       int l = getHeight(root->left);
       int r = getHeight(root->right);
       if ( l == r) {
           return root;
       }else if ( l > r) {
           return lcaDeepestLeaves(root->left);
       }else {
           return lcaDeepestLeaves(root->right);
       }
        
    }
};