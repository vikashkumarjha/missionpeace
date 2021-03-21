/*

Given a binary tree, return the vertical order traversal of its nodes' values. (ie, from top to bottom, column by column).

If two nodes are in the same row and column, the order should be from left to right.

Examples 1:

Input: [3,9,20,null,null,15,7]

   3
  /\
 /  \
 9  20
    /\
   /  \
  15   7 

Output:

[
  [9],
  [3,15],
  [20],
  [7]
]

*/

#include "header.hpp"



  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
class Solution {
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        map<int, vector<int>> m;
        vector<vector<int>> res;
        
        if ( !root) return res;
        
        queue<pair<int,TreeNode*>> q;
        q.push(make_pair(0, root));
        
        while ( !q.empty()) {
            auto qsize = q.size();
            while(qsize--) {
                auto curr = q.front(); q.pop();
                int d = curr.first;
                auto node = curr.second;
                m[d].push_back(node->val);
                
                if ( node->left) {
                    q.push(make_pair(d-1, node->left));
                }
                
                if ( node->right) {
                    q.push(make_pair(d+1, node->right));
                }
                
            }
        }
        
        for ( auto it : m) {
            res.push_back(it.second);
        }
        return res;
        
    }
};