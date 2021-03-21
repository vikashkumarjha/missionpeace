/*

We are given a binary tree (with root node root), a target node, and an integer value K.

Return a list of the values of all nodes that have a distance K from the target node.  The answer can be returned in any order.

 

Example 1:

Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, K = 2

Output: [7,4,1]

Explanation: 
The nodes that are a distance 2 from the target node (with value 5)
have values 7, 4, and 1.


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


#include "header.hpp"
class Solution {
public:    
    vector<int> result;
    unordered_map<TreeNode*, bool> visited;
    unordered_map<TreeNode*, TreeNode*> parents;
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        parents.insert({ root, NULL });
        find_parents(root);
        
        find_nodes(target, 0, K);
        
        return result;
    }
    
    void find_nodes(TreeNode* node, int dist, int K) {
        if (node == NULL || visited[node] == true)
            return;
        
        visited[node] = true;
        if (dist == K)
            result.push_back(node->val);
        
        find_nodes(parents[node], dist + 1, K);
        find_nodes(node->left, dist + 1, K);
        find_nodes(node->right, dist + 1, K);
    }
    
    void find_parents(TreeNode* node) {
        if (node == NULL) 
            return;
        
        if (node->left != NULL) {
            parents[node->left] = node;
            find_parents(node->left);
        }
        
        if (node->right != NULL) {
            parents[node->right] = node;
            find_parents(node->right);   
        }
    }
};