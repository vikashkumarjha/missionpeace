/*
Given the root of a binary tree, return all root-to-leaf paths in any order.

A leaf is a node with no children.
*/


class Solution {
public:
    
    void helper(TreeNode *root, string path, vector<string> &paths) {
        if ( !root) return;
        path += to_string(root->val);
        if ( !root->left && !root->right) {
            paths.push_back(path);
        }
        helper(root->left, path + "->", paths);
        helper(root->right, path + "->", paths);
        
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> paths;
        if ( !root) return paths;
        string path;
        
        helper(root, path, paths);
        return paths;
        
    }
};