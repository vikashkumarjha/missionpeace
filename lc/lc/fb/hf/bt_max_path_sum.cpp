class Solution {
private:
       
    int  helper(TreeNode* root, int &result) {
        if (!root)
           return 0;
        
        int leftmax = helper(root->left, result);
        int rightmax = helper(root->right, result);
        
        int singlemax = max(max(leftmax, rightmax) + root->val, root->val);
        int finalmax  = max(singlemax, leftmax + rightmax + root->val);
        result = max(result, finalmax);
        
        return singlemax;
        
    }
    
public:
    int maxPathSum(TreeNode* root) {
        int result = INT_MIN;
        helper(root, result );
       
        return result;
    }
};