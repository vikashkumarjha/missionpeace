/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;
        map<int,vector<int>> m;

        queue<pair<int,TreeNode*>> q;
        q.push({0,root});

        while (!q.empty())
        {
            auto qsize = q.size();
            while ( qsize--)
            {
                auto curr = q.front(); q.pop();
                int d = curr.first;
                auto node = curr.second;
                m[d].push_back(node->val);
                if ( node->left) {
                    q.push({d-1, node->left});    
                }

                if ( node->right) {
                    q.push({d+1, node->right});
                }
            }
        }

        for ( auto e : m) {
            auto row = e.second;
            sort(begin(row), end(row));
            res.push_back(row);
        }

        return res;

    }
};
