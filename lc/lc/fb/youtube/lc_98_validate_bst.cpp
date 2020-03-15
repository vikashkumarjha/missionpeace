class Solution {
private:
    bool helper(TreeNode* root, TreeNode *min, TreeNode *max) {
        if ( !root)
            return true;
        if ( (min && root->val <=  min->val)  || 
                (max && root->val >= max->val) )
            return false;
        return helper(root->left, min, root) && 
            helper(root->right, root, max );

    }    
public:
    bool isValidBST(TreeNode* root) {
        if ( !root)
            return true;
        return helper(root, nullptr, nullptr);

    }
};
