/**
 *  * Definition for a binary tree node.
 *   * struct TreeNode {
 *    *     int val;
 *     *     TreeNode *left;
 *      *     TreeNode *right;
 *       *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 *        * };
 *         */
class Solution {
public:
    TreeNode* helper(vector<int> &nums, int l, int r) {
        if ( l >= r) {
            return nullptr;
        }
        int m = l + ( r - l) / 2;
        TreeNode *root = new TreeNode(nums[m]);
        root->left = helper(nums, l, m );
        root->right = helper( nums, m + 1, r);
        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int N = nums.size();
        if ( N == 0 ) return nullptr;
        int l = 0;
        int r = N;
        return helper(nums, l, r);
    }
};
