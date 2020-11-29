/*Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

Example:

Input: [1,2,3,null,5,null,4]
Output: [1, 3, 4]
Explanation:

   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---

  */

 


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
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        
        if ( !root) {
            return {};
        }
        queue<TreeNode*> q;
        q.push(root);
        while ( !q.empty()) {
           auto qsize = q.size();
            for ( int k = 0; k < qsize; k++) {
                auto currNode = q.front(); q.pop();
                if ( k == 0 ) {
                    result.push_back(currNode->val);
                }
                if ( currNode->right) {
                    q.push(currNode->right);
                }
                if ( currNode->left) {
                    q.push(currNode->left);
                }
            
            }
        }
        
        return result;
        
     
        
    }
};