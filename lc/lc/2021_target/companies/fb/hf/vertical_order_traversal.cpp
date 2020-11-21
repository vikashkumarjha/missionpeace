vector<vector<int>> verticalOrder(TreeNode* root) {
    vector<vector<int>> res;
    if ( !root)
        return res;

    queue<pair<int, TreeNode*>> q;
    q.push(make_pair(0, root));
    map<int, vector<int>> m;
    
    while ( !q.empty()) {
        auto qsize = q.size();
        for ( int i = 0; i < qsize; i++) {
            auto curr = q.front(); q.pop();
            auto t = curr.second;
            m[curr.first].push_back(t->val);
            if ( t->left) {
                q.push(make_pair(curr.first-1, t->left));
            }

            if ( t->right) {
                q.push(make_pair(curr.first+1, t->right));
            }

        }

        for(auto& v : m){
                res.push_back(v.second);
            }
            return res;




    }






}


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    map<int, map<int, vector<int>>> table;
    void dfs(TreeNode * root, int i, int j)
    {
        if (root == nullptr)
            return;
        table[j][i].push_back(root->val);
        dfs(root->left, i + 1, j - 1);
        dfs(root->right, i + 1, j + 1);
    }
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        dfs(root, 0, 0);
        vector<vector<int>> result;
        for (const auto & col : table)
        {
            result.emplace_back();
            for (const auto & elem : col.second)
            {
                const auto & vec = elem.second;
                copy(vec.begin(), vec.end(), back_inserter(result.back()));
            }
        }
        return result;
    }
};
