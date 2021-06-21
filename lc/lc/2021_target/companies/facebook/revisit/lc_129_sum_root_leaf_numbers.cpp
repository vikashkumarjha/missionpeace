/*
You are given the root of a binary tree containing digits from 0 to 9 only.

Each root-to-leaf path in the tree represents a number.

For example, the root-to-leaf path 1 -> 2 -> 3 represents the number 123.
Return the total sum of all root-to-leaf numbers.

A leaf node is a node with no children.
*/

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
    int sumNumbers(TreeNode *root) {
        if(!root)
            return 0;
        sum=0;
        DFS(root, 0);
        return sum;
    }
    
    void DFS(TreeNode *node, int currentSum)
    {
        if (!node) return;
        currentSum=currentSum*10+node->val;
        if(!node->left&&!node->right)
            sum+=currentSum;
       // if(node->left)
            DFS(node->left, currentSum);
       // if(node->right)
            DFS(node->right, currentSum);
    }
private:
    int sum;
};