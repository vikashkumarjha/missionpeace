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

    int helper(TreeNode *root, int &res) {
        if (!root) return 0;

        int lSum = helper(root->left, res);
        int rSum = helper(root->right, res);

        int singleMax = max( max(lSum, rSum) + root->val, root->val);
        int finalMax = max(singleMax, lSum + rSum + root->val);
        res = max(res, finalMax);
        return singleMax;
    }
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        helper(root, res);
        return res;
    }
};
