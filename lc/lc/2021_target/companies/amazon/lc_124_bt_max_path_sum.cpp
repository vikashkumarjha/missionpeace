/*Given a non-empty binary tree, find the maximum path sum.

For this problem, a path is defined as any node sequence from some starting node to any node in the tree along the parent-child connections. 
The path must contain at least one node and does not need to go through the root.

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
    int helper(TreeNode *root, int &globalSum) {
        if ( !root) return 0;
       
        int lSum = helper(root->left, globalSum);
        int rSum = helper(root->right, globalSum);
        
        int localMax = max(max(lSum,rSum) + root->val, root->val);
        int finalMax = max(localMax, lSum + rSum + root->val);
        
        globalSum = max(globalSum, finalMax);
        
        return localMax;
        
    }
    
    
    
    int maxPathSum(TreeNode* root) {
        if (!root) return 0;
        int globalSum = INT_MIN;
        helper(root, globalSum);
        return globalSum;
        
    }
};