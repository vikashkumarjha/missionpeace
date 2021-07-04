Given the root of a binary tree and an integer targetSum, return the number of paths where the sum of the values along the path equals targetSum.

The path does not need to start or end at the root or a leaf, but it must go downwards (i.e., traveling only from parent nodes to child nodes).



class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
    if ( !root ) return 0;

    return pathSumFromRoot(root, sum ) + pathSum(root->left, sum) + pathSum(root->right, sum);
}

int pathSumFromRoot(TreeNode* root , int sum ){
    if ( !root)
            return 0;

    int result = ( root->val == sum ) ? 1 : 0;
    return result + pathSumFromRoot(root->left , sum - root->val) +
            pathSumFromRoot(root->right, sum - root->val);

}
};
