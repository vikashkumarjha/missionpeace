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
    TreeNode* helper(TreeNode* root, TreeNode *p, TreeNode *q) {
        if ( !root ) return nullptr;

        if ( root == p || root == q) return root;

        auto leftLca = helper(root->left, p, q);
        auto rightLca = helper(root->right, p, q);

        if ( leftLca && rightLca) return root;

        return (leftLca ? leftLca : rightLca);
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return helper(root, p, q);

    }
};
