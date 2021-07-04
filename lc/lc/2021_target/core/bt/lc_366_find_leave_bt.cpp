class Solution {
private:
    std::unordered_map<int,std::vector<int>> mp;
    int groupByHeight(TreeNode* root, std::unordered_map<int,std::vector<int>> &m)
    {
        if (!root) return 0;
        int lHeight = groupByHeight(root->left, m);
        int rHeight = groupByHeight(root->right, m);
        int h = max(lHeight, rHeight) + 1;
        m[h].push_back(root->val);
        return max(lHeight, rHeight) + 1;
    }
    
public:
    vector<vector<int>> findLeaves(TreeNode* root) {
        std::vector<std::vector<int>> result;
        if ( !root)
            return result;
        groupByHeight(root,mp);
        for ( int i = 1; i <= mp.size(); i++){
            result.push_back(mp[i]);
        }
        return result;
        
    }
};


Given the root of a binary tree, collect a tree's nodes as if you were doing this:

Collect all the leaf nodes.
Remove all the leaf nodes.
Repeat until the tree is empty.

