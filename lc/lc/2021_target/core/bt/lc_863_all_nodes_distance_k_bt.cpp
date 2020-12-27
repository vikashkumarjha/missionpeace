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
class Solution {
public:
    
    void find_parent(TreeNode *root) {
        if ( !root) return;
        if (root->left) {
            mParent[root->left] = root;
            find_parent(root->left);
        }
        
        if (root->right) {
            mParent[root->right] = root;
            find_parent(root->right);
        }
        
    }
    
    void find_nodes(TreeNode *root, int dist, int K) {
        if (!root || isVisited[root]) {
            return;
        } 
        if ( dist == K) {
            res.push_back(root->val);
        }
        isVisited[root] = true;
        
        
        find_nodes(mParent[root], dist+1, K);
        find_nodes(root->left, dist+1, K);
        find_nodes(root->right, dist+1, K);
        
    }
    
    
    
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
       
        if ( !root || !target) return res;
        mParent[root] = nullptr;
        
        find_parent(root);
        find_nodes(target, 0, K);
        return res;  
    }
    
private:
     unordered_map<TreeNode*, TreeNode*> mParent;
     unordered_map<TreeNode*, bool> isVisited;
     vector<int> res;
    
};
