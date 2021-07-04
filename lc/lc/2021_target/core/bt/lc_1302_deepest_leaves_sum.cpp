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
    int deepestLeavesSum(TreeNode* root) {
        if ( !root) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int res = 0;

        while ( !q.empty()) {
            res = 0;
            auto qsize = q.size();
            while ( qsize--) {
                auto curr = q.front(); q.pop();
                if ( !curr->left && !curr->right) {
                    res += curr->val;
                }
                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);

            }

        }

        return res;


    }
};
