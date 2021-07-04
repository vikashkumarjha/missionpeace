class Solution {
private:

public:
    void dfs(TreeNode* root, int minPathVal, int maxPathVal, int &result) {
        if ( !root) return;

        minPathVal = min(root->val, minPathVal);
        maxPathVal = max(root->val, maxPathVal);

        result = max(result, maxPathVal - minPathVal);
        dfs(root->left, minPathVal, maxPathVal, result);
        dfs(root->right, minPathVal, maxPathVal, result);

    }



    int maxAncestorDiff(TreeNode* root) {
        int minPathVal = INT_MAX;
        int maxPathVal = INT_MIN;
        int result = INT_MIN;

        dfs(root, minPathVal, maxPathVal, result);

        return result;


    }
};
