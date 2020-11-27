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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        return findLCAUtil(root,p,q);
        
    }
private:
    TreeNode* findLCAUtil(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if ( root == p || root == q || root == NULL)
                return root;
        TreeNode* leftParent = findLCAUtil(root->left,p,q);
        TreeNode* rightParent = findLCAUtil(root->right,p,q);
        if ( leftParent && rightParent)
            return root;
        return ( leftParent ? leftParent : rightParent );
        
        
    }
};