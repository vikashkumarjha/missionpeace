/*
 * A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. A node can only appear in the sequence at most once. Note that the path does not need to pass through the root.

The path sum of a path is the sum of the node's values in the path.

Given the root of a binary tree, return the maximum path sum of any path.


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
