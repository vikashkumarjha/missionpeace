/*
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

Note: A leaf is a node with no children.



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
    int minDepth(TreeNode* root) {
       if (root == NULL) 
            return 0;
        if (root->left == NULL && root->right == NULL) // Reach to leaf node
            return 1; 
        if (root->left == NULL) 
            return minDepth(root->right) + 1;
        if (root->right == NULL) 
            return minDepth(root->left) + 1;
        return min(minDepth(root->left), minDepth(root->right)) + 1;
        
        
        
        
    }
};

class Solution {
public:
    void minDepthUtil(TreeNode* root, int &mlen, int len) {
        if (!root) return;
        
        if (!root->left && !root->right){
            mlen = min(mlen, len);
            return;
        }   
        
        minDepthUtil(root->left, mlen, len+1);
        minDepthUtil(root->right, mlen, len+1);
    }

    int minDepth(TreeNode* root) {
        if (!root) return 0;
        
        int mlen = INT_MAX;
        
        minDepthUtil(root, mlen, 1);
        
        return mlen;
    }
};

class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root) {
            return 0;
        }
        queue<TreeNode*> nodesQueue;
        root->val = 1;
        nodesQueue.push(root);
        while (!nodesQueue.empty()) {
            TreeNode* currentNode = nodesQueue.front();
            nodesQueue.pop();
            if (!currentNode->left && !currentNode->right) { // Leaf Node
                return currentNode->val;
            }
            if (currentNode->left) {
                currentNode->left->val = currentNode->val + 1;
                nodesQueue.push(currentNode->left);
            }
            if (currentNode->right) {
                currentNode->right->val = currentNode->val + 1;
                nodesQueue.push(currentNode->right);
            }
        }
        return 0;
    }
};