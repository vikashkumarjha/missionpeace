//Given a bt find the max path sum
// path can start from any node and end at any node.


//For each node there are four ways.
//1. node only
// 2. Max max path through left and node
// 3. Max max path through righ and node
// 4 .Max path left + node + right



int helper(TreeNode *root, int &res) {
    if (!root) return 0;

    int l = helper(root->left, res);
    int r = helper(root->right, res);
    int maxSingle = max(max(l,r)+root->val , root->val);
    int finalMax = max(maxSingle, l + r + root->val);
    res = max(res, finalMax);
    return singleMax;

}





int findMaxPathSum(TreeNode *root) {
    if (!root) return 0;
    int res = INT_MIN;

    helper(root, res);
    return res;


}








