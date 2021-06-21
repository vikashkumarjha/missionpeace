/*
Given the root of a binary search tree, and an integer k, return the kth (1-indexed) smallest element in the tree.
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
    int kthSmallest(TreeNode* root, int k) {
         stack<TreeNode*> stk;
        stk.push(root);
        while (!stk.empty()&&k){
            TreeNode *cur=stk.top();
            while (cur->left){
                stk.push(cur->left);
                cur=cur->left;
            }
            do{
                cur=stk.top();
                stk.pop();
                k--;
                if (k==0) return cur->val;
            } while(!cur->right);
            stk.push(cur->right);
        }
        
    }
};