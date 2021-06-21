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
    vector<int> rightSideView(TreeNode* root) {
        if (!root) return {};
        
        vector<int> res;
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty())
        {
            auto qsize = q.size();
            for ( int k = 0; k < qsize; k++) {
                auto curr = q.front(); q.pop();
                if ( k == 0) {
                    res.push_back(curr->val);
                }
                if (curr->right) {
                    q.push(curr->right);
                }
                if ( curr->left) {
                    q.push(curr->left);
                }
                
            }
            
        }
        
        return res;
        
    }
};