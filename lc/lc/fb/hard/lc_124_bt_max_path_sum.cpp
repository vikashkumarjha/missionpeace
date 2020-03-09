#include "header.hpp"
using namespace std;


 /** Definition for a binary tree node.
 *   * struct TreeNode {
 *    *     int val;
 *     *     TreeNode *left;
 *      *     TreeNode *right;
 *       *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 *        * };
*/


// path must contain one node
// path need not go through the root

int dfs(TreeNode* root, int &result) {
    if ( !root) return 0;

    int leftMax = dfs(root->left, result);
    int rightMax = dfs(root->right, result);
    // edge or root
    int singleMax = max(max(leftMax, rightMax) + root->val, root->val);
    // either the edge or complete root.
    int finalMax = max(singleMax , leftMax + rightMax + root->val);
    result = max(result, finalMax);
    return singleMax;

}

int maxPathSum(TreeNode* root) {
    int result = INT_MIN;
    dfs(root, result);
    return result;
}
