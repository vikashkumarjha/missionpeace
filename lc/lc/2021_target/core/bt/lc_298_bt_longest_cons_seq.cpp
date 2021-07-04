class Solution {
public:

    void helper(TreeNode *root, int expectedVal, int localMaxPath, int &globalMaxPath){
        if ( !root)
            return;

        if ( root->val == expectedVal) {
            localMaxPath++;
        }else {
            localMaxPath = 1;
        }
        globalMaxPath = max(globalMaxPath, localMaxPath );
        helper(root->left, root->val + 1, localMaxPath, globalMaxPath);
        helper(root->right, root->val + 1, localMaxPath, globalMaxPath);


    }
    int longestConsecutive(TreeNode* root) {
        int global_max_path = INT_MIN;
        int local_max_path = 0;
        if ( !root)
            return 0;
        helper(root, root->val, local_max_path, global_max_path);
        return global_max_path;

    }
};
