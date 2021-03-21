int diameterOfBinaryTree(TreeNode* root) {
    int res = 0;
    dfs(root, res);
    return res;

}

int dfs(TreeNode *root, int &res) {
    if ( !root) 
        return 0;

    int l = dfs(root->left, res);
    int r = dfs(root->right, res);

    res = max(res, l + r); 
    return max(l, r) + 1;
}
