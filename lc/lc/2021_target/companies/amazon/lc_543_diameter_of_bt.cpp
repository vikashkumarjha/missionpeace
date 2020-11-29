
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
private:
    
    // Here we are Returning Number of Edges in Diameter
    // ---- Here height is number of Nodes involved in the Path
    
    int helper(TreeNode* root, int & diaNodeCount) {
        if (root == NULL) return 0;
        
        int ld = helper(root->left,  diaNodeCount);
        int rd = helper(root->right, diaNodeCount);
        
        diaNodeCount = max(diaNodeCount, ld + rd + 1);
        
        return max(ld, rd) + 1;
    }    
    
public:
    
    int diameterOfBinaryTree(TreeNode* root) {
        int diaNodeCount = 1;
        
        helper(root, diaNodeCount);
        
        return diaNodeCount - 1;
    }
};