
class Solution {
public:
    bool helper(TreeNode *root, TreeNode *min, TreeNode *max) {
        if (!root) return true;
        if ( min && root->val <= min->val) return false;
        if ( max && root->val >= max->val) return false;


        return helper(root->left, min, root) && helper(root->right, root, max);


    }

    bool isValidBST(TreeNode* root) {
        if (!root) return true;

        return helper(root, nullptr, nullptr);
        
    }
};