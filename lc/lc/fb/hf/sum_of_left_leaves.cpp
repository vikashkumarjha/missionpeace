class Solution {
public:
    void helper(TreeNode* root, int& sum){
        if ( !root )
            return;
        if ( root->left){
            if ( !root->left->left && !root->left->right){
                sum += root->left->val;
            }
            helper(root->left, sum);
        }
        if ( root->right){
            helper(root->right,sum);
        }
    }
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        helper(root,sum);
        return sum;
    }

};