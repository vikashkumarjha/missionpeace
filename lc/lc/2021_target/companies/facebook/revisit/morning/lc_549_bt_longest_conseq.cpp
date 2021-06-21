Given the root of a binary tree, return the length of the longest consecutive path in the tree.

This path can be either increasing or decreasing.

For example, [1,2,3,4] and [4,3,2,1] are both considered valid, but the path [1,2,4,3] is not valid.
On the other hand, the path can be in the child-Parent-child order, where not necessarily be parent-child order.

 

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
    
    int helper(TreeNode *root, int diff) {
        if ( !root) return 0;
        int l = helper(root->left, diff);
        int r = helper(root->right, diff);
        if ( root->left ) {
            if ( root->val - root->left->val == diff) {
                l = l + 1;
            }else {
                l = 0;
            }
        }
        
         if ( root->right ) {
            if ( root->val - root->right->val == diff) {
                r = r + 1;
            }else {
                r = 0;
            }
        }
         return max(l,r);
        
    }
    
    
    int longestConsecutive(TreeNode* root) {
        if ( !root) return 0;
        int result = 0;
        
        int x = longestConsecutive(root->left);
        int y = longestConsecutive(root->right);
        
        result = helper(root, 1) + helper(root, -1) + 1;
        
        result = max(result, max(x,y));
        
        return result;
        
    }
};