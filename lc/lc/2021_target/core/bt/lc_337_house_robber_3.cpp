/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//sum of the money if you rob this house
//sum of the money if skip this house
//Children return both values so that parents can repeat the same calculation.
class Solution {
public:
    int rob(TreeNode* root) {
        auto result = robOrSkip(root);
        return max(result.first, result.second);
    }

    pair<int, int> robOrSkip(TreeNode* root) {
        if (!root) return make_pair(0,0);
        auto l = robOrSkip(root->left);
        auto r = robOrSkip(root->right);
        int rob = root->val + l.second + r.second;
        int skip = max(l.first, l.second) + max(r.first, r.second);
        return make_pair(rob, skip);
    }

};
