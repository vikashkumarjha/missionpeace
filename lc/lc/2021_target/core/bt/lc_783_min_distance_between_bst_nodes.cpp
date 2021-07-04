class Solution {
public:
    TreeNode *prev = nullptr;
   
    void helper(TreeNode *root, int &minVal) {
        if (!root) return;
        helper(root->left,  minVal);
       
        if (prev) {
            minVal = min(minVal, abs(prev->val - root->val) );
        }
        prev = root;
       
        helper(root->right, minVal);
       
    }
   
    int minDiffInBST(TreeNode* root) {
            int res = INT_MAX;
            TreeNode *last = nullptr;
            helper(root, res);
            return res;
       
    }
};


