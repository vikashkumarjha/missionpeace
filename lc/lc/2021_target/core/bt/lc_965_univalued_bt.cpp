class Solution {
public:
    bool helper(TreeNode *root, int v) {
        if ( !root) return true;
        if ( root->val != v) return false;

        return helper(root->left, v) && helper(root->right, v);

    }

    bool isUnivalTree(TreeNode* root) {
        if ( !root) return true;

        return helper(root, root->val);

    }
};
