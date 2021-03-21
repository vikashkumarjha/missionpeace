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

/*
Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
]

*/

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if ( !root) return res;
        queue<TreeNode*> q;
        
        q.push(root);
        bool leftToRight = true;
        while ( !q.empty()) {
            int qsize = q.size();
            vector<int> row;
            while (qsize--) {
                auto curr = q.front(); q.pop();
                if ( leftToRight){
                    row.push_back(curr->val);
                }else {
                    row.insert(row.begin(), curr->val);
                }
                
                
                if ( curr->left) {
                    q.push(curr->left);
                }
                if ( curr->right) {
                    q.push(curr->right);
                }
            }
            leftToRight = !leftToRight;
            res.push_back(row);
            
        }
        
        return res;
        
        
        
        
    }
};